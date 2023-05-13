using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Linq;
using System;
using System.IO;
using System.Text;

public class MatlabToUnity : MonoBehaviour
{

    // Use this for initialization
    TcpListener listener;
    int flag = 0; // flag used to understand wheteher it is the orientation or the translation that we are  receiving 
    int flag2 = 0; //flag to converto the string into float, to be done only when the data is recived, thats why the flag is needed
    String Orientation;
    String Translation;
    
    Vector3 KukaPosition = new Vector3();
    Quaternion KukaOrientation = new Quaternion();

    public GameObject KukaRobot;

    void Start()
    {
        listener = new TcpListener(IPAddress.Parse("10.168.71.151"), 4000); // you have to manually insert the hololens IP
        listener.Start();
        print("is listening");
    }
    // Update is called once per frame
    void Update()
    {
        
        if (!listener.Pending())
        {
        }
        else
        {
            flag2 = 1;
            if (flag == 0)
            {
                TcpClient client = listener.AcceptTcpClient();
                NetworkStream ns = client.GetStream();
                StreamReader reader = new StreamReader(ns);
                Orientation = reader.ReadToEnd();
                //print("Orientation: " + Orientation); 
                flag++;
            }
            if (flag == 1)
            {
                TcpClient client = listener.AcceptTcpClient();
                NetworkStream ns = client.GetStream();
                StreamReader reader = new StreamReader(ns);
                Translation = reader.ReadToEnd();
                //print("Translation: " + Translation);
                flag = 0;
            }
        }

        if (flag2 == 1)
        {
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
            flag2 = 0;
        }
        

    }
}
