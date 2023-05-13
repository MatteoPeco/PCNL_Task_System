using QRTracking;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class DebugText : MonoBehaviour
{
    public GameObject DebugTextText;
    public GameObject qrCodePrefab;

    private TextMeshPro debugText;
    Vector3 positionQRcode;

    // Start is called before the first frame update
    void Start()
    {
        debugText = DebugTextText.GetComponent<TextMeshPro>();
    }

    // Update is called once per frame
    void Update()
    {
        //QRCodesVisualizer QRCode = new QRCodesVisualizer(qrCodePrefab);
        //positionQRcode = qrCodePrefab.QRpose;
        debugText.text = positionQRcode.ToString();
    }
}
