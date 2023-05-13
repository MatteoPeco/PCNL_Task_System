using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CancelButton : MonoBehaviour
{
    //script needed to set inactive by default the cancel button
    public GameObject Button;
    // Start is called before the first frame update
    void Start()
    {
        Button.SetActive(false); 
    }
}
