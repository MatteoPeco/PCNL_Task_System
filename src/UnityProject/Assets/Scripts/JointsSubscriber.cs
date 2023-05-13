using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.UnityRoboticsDemo;

// CODE EXPLAINATION
// this script is the one that takes the joints values from the ros topic: joints, and updates the Unity kuka model values in order to 
// give the gazebo configuration also to the kuka in unity

public class JointsSubscriber : MonoBehaviour
{
    public GameObject Link2;
    public GameObject Joint2;
    public GameObject Link4;
    public GameObject Joint4;
    public GameObject Link6;
    public GameObject Joint6;
    public GameObject TCP;
    public GameObject Connector1;
    //public GameObject ToolTipPosition; // importing also the toottip in order to get it's position after the configuration of the kuka, this value will be used from the tooltip transform script
    //public GameObject EEObject; // importin the EEObject beacuse its position will be associated to the ToottipPosition empty object

    float[] diffJoints = new float[7];
    float[] readJoints = new float[7];
    float[] oldJoints = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    public int inv_speed = 1; // total steps

    //double a1_joint, a2_joint, a3_joint, a4_joint, a5_joint, a6_joint, e1_joint = 0;
    //public int flag; // the flag variable is used to save the initial toottipposition, so you update the tooltipPosition variable at the first iteration 
    //and then you put the flag at 1, it will be 0 again only at the next time you play the scene
    //nb the flag variable is public because the transformPublisher script has to know when the configuration is upadted, in the way to send the correct tooltip position to gazebo


    void Start()
    {
        ROSConnection.GetOrCreateInstance().Subscribe<RotJointsMsg>("joints", JointsParamChange);
        //ToolTipPosition.transform.position = (EEObject.transform.position); //we initialise also in the start so even if the rosmessage is not received you are in the right position
        //flag = 0;
    }
    void Update()
    {
        //print(Connector1.transform.rotation);
        //Debug.Log(ToolTipPosition.transform.position);
        //Debug.Log(diffJoints[0] + ", " + diffJoints[1] + ", " + diffJoints[2] + ", " + diffJoints[3] + ", " + diffJoints[4] + ", " + diffJoints[5] + ", " + diffJoints[6]);
    }
    void JointsParamChange(RotJointsMsg jointsMessage)
    {
        readJoints[0] = jointsMessage.a1_joint * 180 / Mathf.PI;
        readJoints[1] = jointsMessage.a2_joint * 180 / Mathf.PI;
        readJoints[2] = jointsMessage.e1_joint * 180 / Mathf.PI;
        readJoints[3] = jointsMessage.a3_joint * 180 / Mathf.PI;
        readJoints[4] = jointsMessage.a4_joint * 180 / Mathf.PI;
        readJoints[5] = jointsMessage.a5_joint * 180 / Mathf.PI;
        readJoints[6] = jointsMessage.a6_joint * 180 / Mathf.PI;

        for (int i = 0; i <= 6; i++)
        {
            diffJoints[i] = readJoints[i] - oldJoints[i];
            oldJoints[i] = readJoints[i];
        }
        MoveKuka(diffJoints);

        //Debug.Log(readJoints[0] + ", " + readJoints[1] + ", " + readJoints[2] + ", " + readJoints[3] + ", " + readJoints[4] + ", " + readJoints[5] + ", " + readJoints[6]);// = readJoints;
        //Debug.Log(diffJoints[0] + ", " + diffJoints[1] + ", " + diffJoints[2] + ", " + diffJoints[3] + ", " + diffJoints[4] + ", " + diffJoints[5] + ", " + diffJoints[6]);

        /*if (flag == 0)
        {
            ToolTipPosition.transform.position = (EEObject.transform.position);
            Debug.Log("aggiornato!");
            flag++;
        }*/

    }

    private void MoveKuka(float[] joints)
    {

        float[] delta_joints = new float[7];
        for (int i = 0; i < delta_joints.Length; i++)
        { // was i < joints.Length
            delta_joints[i] = joints[i] / inv_speed;
        }

        for (int i = 0; i < inv_speed; i++)
        {
            Link2.transform.Rotate(0f, -delta_joints[0], 0f); //Rotate around "y" axis in Unity, Real robot "z" axis
            Joint2.transform.Rotate(0f, 0f, delta_joints[1]);  //Rotate around "z" axis in Unity, Real robot "y" axis
            Link4.transform.Rotate(0f, -delta_joints[2], 0f); //Rotate around "y" axis
            Joint4.transform.Rotate(0f, 0f, -delta_joints[3]); //Rotate around "z" axis
            Link6.transform.Rotate(0f, -delta_joints[4], 0f); //Rotate around "y" axis
            Joint6.transform.Rotate(0f, 0f, delta_joints[5]);  //Rotate around "z" axis
            TCP.transform.Rotate(0f, -delta_joints[6], 0f); //Rotate around "y" axis
        }

    }

}