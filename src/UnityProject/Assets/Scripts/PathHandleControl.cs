using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PathHandleControl : MonoBehaviour
{
    public GameObject Handle;
    int flag = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void StillOrMove()
    {
        if (flag==0)
        {
            Handle.SetActive(false);
            flag++;
        }
        else
        {
            Handle.SetActive(true);
            flag = 0;
        }
          
    }    

}
