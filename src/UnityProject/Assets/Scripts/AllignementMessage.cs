using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
// libraries for the ros connection
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.UnityRoboticsDemo;
using System.Threading;

public class AllignementMessage : MonoBehaviour
{
    public GameObject Base;
    public GameObject Link2;
    public GameObject Link3;
    public GameObject Link4;
    public GameObject Link5;
    public GameObject Link6;
    public GameObject Link7;
    public GameObject TCP;
    public GameObject connector;
  

    //variables for the connection to send the stiffness to ROS
    ROSConnection ros;
    string topicName = "Stiffness";
    float pos_x = 50.0f;
    float pos_y = 50.0f;
    float pos_z = 50.0f;
    float rot_x = 10.0f;
    float rot_y = 10.0f;
    float rot_z = 10.0f;
    float rot_w = 0.0f;


    // Start is called before the first frame update
    void Start()
    {
        
        Base.SetActive(false);
        Link2.SetActive(false);
        Link3.SetActive(false);
        Link4.SetActive(false);
        Link5.SetActive(false);
        Link6.SetActive(false);
        Link7.SetActive(false);
        TCP.SetActive(false);
        //connector.SetActive(false);
       
        // start the connection with ros 
        ros = ROSConnection.GetOrCreateInstance();
        ros.RegisterPublisher<PosRotMsg>(topicName);
    }

    // Update is called once per frame
    void Update()
    {

        PosRotMsg modifiedStiffness = new PosRotMsg( 
            pos_x,
            pos_y,
            pos_z,
            rot_x,
            rot_y,
            rot_z,
            rot_w
              );

        //Debug.Log(modifiedStiffness.pos_x + " ," + modifiedStiffness.pos_y);
        ros.Publish(topicName, modifiedStiffness);
    }

    public void RobotAlligned()
    {
        pos_x = 4500;
        pos_y = 4500;
        pos_z = 1.0f;
        rot_x = 200;
        rot_y = 200;
        rot_z = 200;
        rot_w = 1;
        connector.SetActive(true);
    }
    public void RobotNotAlligned()
    {
        pos_x = 50.0f;
        pos_y = 50.0f;
        pos_z = 50.0f;
        rot_x = 10.0f;
        rot_y = 10.0f;
        rot_z = 10.0f;
        rot_w = 0.0f;
        //connector.SetActive(false);
    }
}
