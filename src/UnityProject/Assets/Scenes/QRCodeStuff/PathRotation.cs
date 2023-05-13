using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PathRotation : MonoBehaviour
{
    public Transform StartPoint;
    float currentTheta;
    float currentPhi;
    Vector3 radius;
    public GameObject registration; // gameobject that contains the BoxRFComputation script
    bool rotated; // is the flag variable taken from the BoxRFComputation scritp that tells if the a translation has accured and if the path rotation needs to be reinitilised

    //Script explaination: the rotation that is applied to the path is the application of the spherical coordinates computed starting from the cartesian coordinates

    // Start is called before the first frame update
    void Start()
    {
        radius = new Vector3(StartPoint.position.x - this.transform.position.x, StartPoint.position.y - this.transform.position.y, StartPoint.position.z - this.transform.position.z);
        
        currentTheta = Mathf.Atan2(StartPoint.position.y - this.transform.position.y, StartPoint.position.x - this.transform.position.x);
        currentTheta = currentTheta * 180 / Mathf.PI;

        currentPhi = Mathf.Acos((StartPoint.position.z - this.transform.position.z) / radius.magnitude);
        currentPhi = currentPhi * 180 / Mathf.PI;
    }


    // Update is called once per frame
    void Update()
    {
        rotated = registration.GetComponent<BoxRFComputation>().rotated;
        if (rotated)
        {
            radius = new Vector3(StartPoint.position.x - this.transform.position.x, StartPoint.position.y - this.transform.position.y, StartPoint.position.z - this.transform.position.z);

            currentTheta = Mathf.Atan2(StartPoint.position.y - this.transform.position.y, StartPoint.position.x - this.transform.position.x);
            currentTheta = currentTheta * 180 / Mathf.PI;

            currentPhi = Mathf.Acos((StartPoint.position.z - this.transform.position.z) / radius.magnitude);
            currentPhi = currentPhi * 180 / Mathf.PI;

        }
        
        //ROTATION AROUND Z (Thata angle)
        float newTheta = Mathf.Atan2(StartPoint.position.y - this.transform.position.y, StartPoint.position.x - this.transform.position.x);
        newTheta = newTheta * 180 / Mathf.PI;

        if (newTheta != currentTheta) //update only if the StartPoint moved
        {
            float deltaTheta = newTheta - currentTheta;
            this.transform.Rotate(0f, 0f, deltaTheta, Space.World);

            currentTheta = newTheta;
        }
        

        //ROTATION AROUND rotationVector (Phi angle) 
        //Axis of rotation definition
        Vector3 ZAxis = new Vector3(0f, 0f, 1f);
        radius = new Vector3(StartPoint.position.x - this.transform.position.x, StartPoint.position.y - this.transform.position.y, StartPoint.position.z - this.transform.position.z);
        Vector3 rotationVector = Vector3.Cross(radius, ZAxis).normalized;
        
        //Angle of rotation defintion
        float newPhi = Mathf.Acos((StartPoint.position.z - this.transform.position.z) /radius.magnitude);
        newPhi = newPhi * 180 / Mathf.PI;

        if (newPhi != currentPhi) //update only if the StartPoint moved
        {
            float deltaPhi = newPhi - currentPhi;
            this.transform.RotateAround(this.transform.position, rotationVector, -deltaPhi); //there is the minus because the unity RF is left handed compared to the classical right handed

            currentPhi = newPhi;
        }
        
        //Debug.Log(currentPhi +";"+ newPhi);
        
    }
}
