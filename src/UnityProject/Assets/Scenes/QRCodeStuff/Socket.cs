// Unity C# code
using System.Collections;
using System.Net;
using UnityEngine;
using System.Net.Sockets;
using System;
using System.Text;
using System.IO;
using TMPro;
using System.Threading;

public class Socket : MonoBehaviour
{

    
    // Use this for initialization
    internal Boolean socketReady = false;
    TcpClient mySocket;
    NetworkStream theStream;
    StreamWriter theWriter;
    StreamReader theReader;
    String Host = "192.168.0.177"; //here the IP is the one of the server on which matlab is running 
    Int32 Port = 4000;
    

    public GameObject point1;
    public GameObject point2;
    public GameObject point3;
    public GameObject point4;
    public TextMeshPro IPText;
    public TextMeshPro IPText2;
    public GameObject RegObject;
    public GameObject KukaRobot;

    public GameObject target;
    public GameObject startPoint;
    public GameObject connector;
    public GameObject joint7;
    double angularError;

    public GameObject link1;
    Vector3 KukaPosition = new Vector3();
    Quaternion KukaOrientation = new Quaternion();

    string a;
    int bytesReceived;

    void Start()
    {
        IPText.text = Host;
        IPText2.text = Host;
    }
    // Update is called once per frame
    void Update()
    {
        
    
    }

    public void receiveRobotPosition()
    {
        try
        {
            mySocket = new TcpClient(Host, Port);
            theStream = mySocket.GetStream();
            //theWriter = new StreamWriter(theStream);
            socketReady = true;

            //StreamReader reader = new StreamReader(theStream, Encoding.UTF8);
            //a = reader.ReadToEnd();


            byte[] receiveBuffer = new byte[1024];
            bytesReceived = theStream.Read(receiveBuffer, 0, 2);
            string L = String.Concat((char)receiveBuffer[0], (char)receiveBuffer[1]);

            bytesReceived = theStream.Read(receiveBuffer, 0, Int32.Parse(L));
            string Orientation = "";
            for (int i = 0; i < Int32.Parse(L); i++)
            {
                Orientation = String.Concat(Orientation, (char)receiveBuffer[i]);
            }

            print(Orientation);
            bytesReceived = theStream.Read(receiveBuffer, 0, 2);
            string L2 = String.Concat((char)receiveBuffer[0], (char)receiveBuffer[1]);

            bytesReceived = theStream.Read(receiveBuffer, 0, Int32.Parse(L2));
            string Translation = "";
            for (int i = 0; i < Int32.Parse(L2) + 1; i++)
            {
                Translation = String.Concat(Translation, (char)receiveBuffer[i]);
            }

            print(Translation);

            string[] sTranslation = Translation.Split(";"[0]);
            KukaPosition.x = float.Parse(sTranslation[0]);
            KukaPosition.y = float.Parse(sTranslation[2]);
            KukaPosition.z = float.Parse(sTranslation[1]); // nb y and z are inverted couse of the different RF of unity and matlab
                                                           //print(KukaPosition);
            KukaRobot.transform.localPosition = KukaPosition;

            string[] sOrientation = Orientation.Split(" "[0]);
            KukaOrientation.x = float.Parse(sOrientation[1]);
            KukaOrientation.y = float.Parse(sOrientation[2]);
            KukaOrientation.z = float.Parse(sOrientation[3]);
            KukaOrientation.w = float.Parse(sOrientation[0]);
            //print(KukaOrientation);
            KukaRobot.transform.localRotation = KukaOrientation;

            //Console.WriteLine($"This is what the peer sent to you: {a}");
        }
        catch (Exception e)
        {
            Debug.Log("Socket error: " + e);
        }

    }
    public void SetupAndSend() //function that set up the socket and send the message to matlab every time it is called
    {
        /*
        Quaternion R = RegObject.GetComponent<BoxRFComputation>().R;
        Vector3 tran = RegObject.GetComponent<BoxRFComputation>().oldTran;
        */
        //inclination error
        Vector3 vector1 = joint7.transform.position - connector.transform.position;
        Vector3 vector2 = startPoint.transform.position - target.transform.position;
        angularError = Mathf.Acos( (Vector3.Dot(vector1,vector2))/(vector1.magnitude * vector2.magnitude) );

        /*
        Vector3 joint7Pos = joint7.transform.position;
        Vector3 connectorPos = connector.transform.position;  
        Vector3 startPointPos = startPoint.transform.position; 
        Vector3 targetPos = target.transform.position;
        */
        Quaternion R = link1.transform.rotation;
        Quaternion tran = connector.transform.rotation;
         
        //Vector3 point1 = RegObject.GetComponent<BoxRFComputation>().sphere1box.transform.position;
        //Vector3 point2 = RegObject.GetComponent<BoxRFComputation>().sphere2box.transform.position;
        //Vector3 point3 = RegObject.GetComponent<BoxRFComputation>().sphere3box.transform.position;
        /*
        string joint7Poss = angularError.ToString("f4") + "," + joint7.transform.position.y.ToString("f4") + "," + joint7.transform.position.z.ToString("f4");
        string connectorPoss = connector.transform.position.x.ToString("f4") + "," + connector.transform.position.y.ToString("f4") + "," + connector.transform.position.z.ToString("f4");
        string startPointPoss = startPoint.transform.position.x.ToString("f4") + "," + startPoint.transform.position.y.ToString("f4") + "," + startPoint.transform.position.z.ToString("f4");
        string targetPoss = target.transform.position.x.ToString("f4") + "," + target.transform.position.y.ToString("f4") + "," + target.transform.position.z.ToString("f4");
        */
        string Rs = R.w.ToString("f4") + "," + (-R.x).ToString("f4") + "," + (-R.z).ToString("f4") + "," + (-R.y).ToString("f4"); 
        string trans = tran.w.ToString("f4") + "," + (-tran.x).ToString("f4") + "," + (-tran.z).ToString("f4") + "," + (-tran.y).ToString("f4");
        string angleS = angularError.ToString("f10");
        //string point1s = point1.x.ToString("f4") + "," + point1.y.ToString("f4") + "," + point1.z.ToString("f4");
        //string point2s = point2.x.ToString("f4") + "," + point2.y.ToString("f4") + "," + point2.z.ToString("f4");
        //string point3s = point3.x.ToString("f4") + "," + point3.y.ToString("f4") + "," + point3.z.ToString("f4");

        
        string Len1 = Rs.Length.ToString(); //the length of the string is computed in order to tell to matlab how long the string will be 
        string Len2 = trans.Length.ToString();
        string Len3 = angleS.Length.ToString();
        
        
        //string Len11 = point1s.Length.ToString();
        //string Len21= point2s.Length.ToString();
        //string Len31 = point3s.Length.ToString();


        try
        {
            mySocket = new TcpClient(Host, Port);
            theStream = mySocket.GetStream();
            theWriter = new StreamWriter(theStream);
            socketReady = true;

            Byte[] sendBytes = Encoding.UTF8.GetBytes(Len1 + R.w.ToString("f4") + "," + (-R.x).ToString("f4") + "," + (-R.z).ToString("f4") + "," + (-R.y).ToString("f4") + Len2 + tran.w.ToString("f4") + "," + (-tran.x).ToString("f4") + "," + (-tran.z).ToString("f4") + "," + (-tran.y).ToString("f4") + Len3 + angularError.ToString("f10"));
            print(Rs);
            //Byte[] sendBytes = Encoding.UTF8.GetBytes(Len1 + angularError.ToString("f4") + "," + joint7.transform.position.y.ToString("f4") + "," + joint7.transform.position.z.ToString("f4") + Len2 + connector.transform.position.x.ToString("f4") + "," + connector.transform.position.y.ToString("f4") + "," + connector.transform.position.z.ToString("f4") +
            //    Len3 + startPoint.transform.position.x.ToString("f4") + "," + startPoint.transform.position.y.ToString("f4") + "," + startPoint.transform.position.z.ToString("f4")+Len4 + target.transform.position.x.ToString("f4") + "," + target.transform.position.y.ToString("f4") + "," + target.transform.position.z.ToString("f4"));
            mySocket.GetStream().Write(sendBytes, 0, sendBytes.Length); // with this one also
            Debug.Log("socket is sent");
        }
        catch (Exception e)
        {
            Debug.Log("Socket error: " + e);
        }
    
    }

}