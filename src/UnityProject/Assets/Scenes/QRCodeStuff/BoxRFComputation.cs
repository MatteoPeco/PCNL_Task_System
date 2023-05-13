using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using QRTracking; // it is necessary couse the QRCodesVisualizer script has the namespace QRTracking inside

public class BoxRFComputation : MonoBehaviour
{
    public GameObject qrCodesManager;

    public GameObject sphere1box;
    public GameObject sphere2box;
    public GameObject sphere3box;

    public GameObject worldRF;
    public bool rotated = false; //public variable taken from pathrotation script to initialize the path rotation everytime it is rotated from the registration

    [HideInInspector]
    public Quaternion R;
    Quaternion Rold = new Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    [HideInInspector]
    public Vector3 oldTran;
    private Vector3 tran;


    private Vector3[] boxPoints = new Vector3[3]; //matrix to save the scanned points
    private Vector3[] worldPoints = new Vector3[3]; //matrix to save the world rf points paired to the scanned ones

  

    // Start is called before the first frame update
    void Start()
    {
          
    }

    // Update is called once per frame
    void Update()
    {
        if (qrCodesManager.GetComponent<QRCodesVisualizer>().flag)  // the flag is true when the QRCodesVisualizer stopscan function has finished, hence the points position have been updated
        {

            boxPoints[0] = qrCodesManager.GetComponent<QRCodesVisualizer>().point1; //taking the scanned points that are scanned in another script
            boxPoints[1] = qrCodesManager.GetComponent<QRCodesVisualizer>().point2;
            boxPoints[2] = qrCodesManager.GetComponent<QRCodesVisualizer>().point3;

            //computing the axis that will be needed to create the world rf
            Vector3 X = boxPoints[2] - boxPoints[0];
            Vector3 Z = boxPoints[1] - boxPoints[0];

            Vector3 Upwards = Vector3.Cross(Z, X);
            Upwards = Upwards / Upwards.magnitude;
            Upwards = X.magnitude * Upwards;

            //plaicying the spheres onto the points positions in order to hava the debugging
            sphere1box.transform.position = boxPoints[0];
            sphere2box.transform.position = boxPoints[1];
            sphere3box.transform.position = boxPoints[2];

            //rotating the frame with the LookRotation transformation that computes the transformation starting from a RF
            R = Quaternion.LookRotation(boxPoints[1] - boxPoints[0], Upwards);
            worldRF.transform.rotation = R;

            //this if sets the rotated variable to true in the cycle in which there is the transformation  
            if(R != Rold)
            {
                rotated = true;
                Rold = R;
            }
            else
            {
                rotated = false;
            }

            tran = boxPoints[0] - worldRF.transform.position;

            //after rotation also the translation is applyed to the RF
            worldRF.transform.position = boxPoints[0]; 

            /* //here the same concept of the line above is applied the difference is the function, i cutted couse the one above
             * is less complex
            //after rotation also the translation is applyed to the RF
            if (boxPoints[0] != worldRF.transform.position)
            {
                tran = boxPoints[0] - worldRF.transform.position;
                worldRF.transform.Translate(tran, Space.World);
                oldTran = tran;

            }
            */


        }
        
    }
    
}
