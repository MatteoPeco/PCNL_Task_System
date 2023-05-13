using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Microsoft.MixedReality.QR;
using System; // to use String
using TMPro;

namespace QRTracking
{
    public class QRCodesVisualizer : MonoBehaviour
    {
        public GameObject qrCodePrefab;
        public TextMeshPro LatestQRCodeDetails;

        public TextMeshPro DebugText1; 
        public TextMeshPro DebugText2; 
        public GameObject box; ///<----------
        public GameObject sphere1box;///<----------
        public GameObject sphere2box;///<----------
        public GameObject sphere3box;///<----------
        public GameObject axis; ////<----------
        public GameObject Kidneys; ////<---------- 
        public GameObject LeftUreter;
        public GameObject SpineRibs;
        public GameObject StartPoint;
        public GameObject EndPoint;
        public GameObject Path;
        public GameObject Marker1;///<----------
        public GameObject Marker2;///<----------
        public GameObject Marker3;///<----------
        public GameObject Marker4;
        public GameObject OnlineRegButton;

        public QRCodesManager qRCodesManager;
        public TextMeshPro statusText;
        Vector3 oldPosition;

        // here the 3 points on wich the RF of the box will be bilt are defined <------------
        [HideInInspector]
        public Vector3 point1;
        [HideInInspector]
        public Vector3 point2;
        [HideInInspector]
        public Vector3 point3;
        [HideInInspector]
        public bool flag; // variable needed from BoxRFcomputation script to know if the stop scan is finished




        private System.Collections.Generic.SortedDictionary<System.Guid, GameObject> qrCodesObjectsList; 
        private System.Collections.Generic.SortedDictionary<System.Guid, string> qrCodesObjectsNamesList;

        private bool clearExisting = false;

        struct ActionData
        {
            public enum Type
            {
                Added,
                Updated,
                Removed
            };
            public Type type;
            public Microsoft.MixedReality.QR.QRCode qrCode;

            public ActionData(Type type, Microsoft.MixedReality.QR.QRCode qRCode) : this()
            {
                this.type = type;
                qrCode = qRCode;
            }
        }

        private System.Collections.Generic.Queue<ActionData> pendingActions = new Queue<ActionData>();
        void Awake()
        {

        }

        // Use this for initialization
        void Start()
        {
            Debug.Log("QRCodesVisualizer start");
            qrCodesObjectsList = new SortedDictionary<System.Guid, GameObject>();
            qrCodesObjectsNamesList = new SortedDictionary<System.Guid, string>(); 
            box.SetActive(false); //<--------- the cube is hided at the beginnig
            axis.SetActive(false);
            sphere1box.SetActive(false);
            sphere2box.SetActive(false);
            sphere3box.SetActive(false);
            LeftUreter.SetActive(false);
            Kidneys.SetActive(false);
            SpineRibs.SetActive(false);
            StartPoint.SetActive(false);
            EndPoint.SetActive(false);
            Path.SetActive(false);
            Marker1.SetActive(false);
            Marker2.SetActive(false);
            Marker3.SetActive(false);
            Marker4.SetActive(false);
            OnlineRegButton.SetActive(false);

            oldPosition = LeftUreter.transform.position;
            flag = false;



            // listen to any event changes on QRCOdeManager
            QRCodesManager.Instance.QRCodesTrackingStateChanged += Instance_QRCodesTrackingStateChanged;
            QRCodesManager.Instance.QRCodeAdded += Instance_QRCodeAdded;
            QRCodesManager.Instance.QRCodeUpdated += Instance_QRCodeUpdated;
            QRCodesManager.Instance.QRCodeRemoved += Instance_QRCodeRemoved;
            if (qrCodePrefab == null)
            {
                throw new System.Exception("Prefab not assigned");
            }
        }
        // call this whenever the state has changed - line 120 of QRCodesManager - this method is invoked when we start QR Tracking from QRCodesManager
        private void Instance_QRCodesTrackingStateChanged(object sender, bool status)
        {
            if (!status)
            {
                clearExisting = true;
            }
        }

        // listen to QRCodesManager changes on QRCodeVisualizer
        private void Instance_QRCodeAdded(object sender, QRCodeEventArgs<Microsoft.MixedReality.QR.QRCode> e)
        {
            Debug.Log("QRCodesVisualizer Instance_QRCodeAdded");

            lock (pendingActions)
            {
                pendingActions.Enqueue(new ActionData(ActionData.Type.Added, e.Data));
            }
        }

        private void Instance_QRCodeUpdated(object sender, QRCodeEventArgs<Microsoft.MixedReality.QR.QRCode> e)
        {
            Debug.Log("QRCodesVisualizer Instance_QRCodeUpdated");

            lock (pendingActions)
            {
                pendingActions.Enqueue(new ActionData(ActionData.Type.Updated, e.Data)); // Enqueue adds an object to the end of the Queue
            }
        }

        private void Instance_QRCodeRemoved(object sender, QRCodeEventArgs<Microsoft.MixedReality.QR.QRCode> e)
        {
            Debug.Log("QRCodesVisualizer Instance_QRCodeRemoved");

            lock (pendingActions)
            {
                pendingActions.Enqueue(new ActionData(ActionData.Type.Removed, e.Data));
            }
        }

        private void HandleEvents()
        {
            lock (pendingActions)
            {
                while (pendingActions.Count > 0)
                {
                    var action = pendingActions.Dequeue(); // removes an element from the queue FIFO approach
                    if (action.type == ActionData.Type.Added)
                    {
                        GameObject qrCodeObject = Instantiate(qrCodePrefab, new Vector3(0, 0, 0), Quaternion.identity);
                        qrCodeObject.GetComponent<SpatialGraphCoordinateSystem>().Id = action.qrCode.SpatialGraphNodeId;
                        qrCodeObject.GetComponent<QRCode>().qrCode = action.qrCode;
                        LatestQRCodeDetails.text = action.qrCode.Data; //updating to show in our QRCodePanel the data of latest QR code scanned
                        qrCodesObjectsList.Add(action.qrCode.Id, qrCodeObject); //QRcode added 
                        qrCodesObjectsNamesList.Add(action.qrCode.Id, action.qrCode.Data); //QRcodeData added 
                    }
                    else if (action.type == ActionData.Type.Updated)
                    {
                        if (!qrCodesObjectsList.ContainsKey(action.qrCode.Id))
                        {
                            GameObject qrCodeObject = Instantiate(qrCodePrefab, new Vector3(0, 0, 0), Quaternion.identity);
                            qrCodeObject.GetComponent<SpatialGraphCoordinateSystem>().Id = action.qrCode.SpatialGraphNodeId;
                            qrCodeObject.GetComponent<QRCode>().qrCode = action.qrCode;
                            qrCodesObjectsList.Add(action.qrCode.Id, qrCodeObject);
                        }
                    }
                    else if (action.type == ActionData.Type.Removed)
                    {
                        if (qrCodesObjectsList.ContainsKey(action.qrCode.Id))
                        {
                            Destroy(qrCodesObjectsList[action.qrCode.Id]);
                            qrCodesObjectsList.Remove(action.qrCode.Id);

                            //Destroy(qrCodesObjectsNamesList[action.qrCode.Id]); // be careful you might need to add this
                            qrCodesObjectsNamesList.Remove(action.qrCode.Id); 
                        }
                    }
                }
            }
            if (clearExisting)
            {
                clearExisting = false;
                foreach (var obj in qrCodesObjectsList)
                {
                    Destroy(obj.Value);
                }
                qrCodesObjectsList.Clear();
                //careful maybe you have to replicate the foreach also for the qrCodesObjectsNamesList
                qrCodesObjectsNamesList.Clear(); 

            }
        }

        // Update is called once per frame
        void Update()
        {
            
            HandleEvents();

            // this if is needed for the online registration, the flag is set to false only when the position of the hologram has been updated
            // in this way you are sure the chnages have been applied
            /*
            if (!oldPosition.Equals(LeftUreter.transform.position))
            {
                flag = false;
                oldPosition = LeftUreter.transform.position;
            }
            */
        }


        public void StartScan()
        {
            // start QR tracking with the press of a button
            box.SetActive(false); /////<----------
            axis.SetActive(false);
            sphere1box.SetActive(false);
            sphere2box.SetActive(false);
            sphere3box.SetActive(false);
            LeftUreter.SetActive(false);
            Kidneys.SetActive(false);
            SpineRibs.SetActive(false);
            StartPoint.SetActive(false);
            EndPoint.SetActive(false);
            Path.SetActive(false);
            Marker1.SetActive(false);
            Marker2.SetActive(false);
            Marker3.SetActive(false);
            Marker4.SetActive(false);
            OnlineRegButton.SetActive(false);

            flag = false;
                
            
           
            qRCodesManager.StartQRTracking();
            statusText.text = "Started QRCode Tracking";
        }
        public void StopScan()
        {
            box.SetActive(false); ///<-----
            axis.SetActive(false);
            sphere1box.SetActive(false);
            sphere2box.SetActive(false);
            sphere3box.SetActive(false);
            LeftUreter.SetActive(true);
            Kidneys.SetActive(true);
            SpineRibs.SetActive(true);
            StartPoint.SetActive(true);
            EndPoint.SetActive(true);
            Path.SetActive(true);
            Marker1.SetActive(false);
            Marker2.SetActive(false);
            Marker3.SetActive(false);
            Marker4.SetActive(false);
            OnlineRegButton.SetActive(false);


            foreach (var qrcode in qrCodesObjectsList) //checking all the qrcodes saved in the list 
            {
               
                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key],"1")) //recognising the QR code that says 1
                {
                    point1 = qrcode.Value.gameObject.transform.localPosition;
                }

                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key],"2")) //recognising the QR code that says 2
                {
                    point2 = qrcode.Value.gameObject.transform.localPosition;  
                }
                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key], "3")) //recognising the QR code that says 2
                {
                    point3 = qrcode.Value.gameObject.transform.localPosition;
                }

            }

            // Stop the tracking with the press of a button
            qRCodesManager.StartQRTracking();
            statusText.text = "QRCode Tracking in the background";
            flag = true;
        }

        public void OnlineRegistration() //function for the online registration, it doesn't do anything, is simply a refresh of the position of the holograms
        {

            foreach (var qrcode in qrCodesObjectsList) //checking all the qrcodes saved in the list 
            {

                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key], "1")) //recognising the QR code that says 1
                {
                    point1 = qrcode.Value.gameObject.transform.localPosition;
                }

                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key], "2")) //recognising the QR code that says 2
                {
                    point2 = qrcode.Value.gameObject.transform.localPosition;
                }
                if (String.Equals(qrCodesObjectsNamesList[qrcode.Key], "3")) //recognising the QR code that says 2
                {
                    point3 = qrcode.Value.gameObject.transform.localPosition;
                }

            }

            flag = true;
        }



    }

}