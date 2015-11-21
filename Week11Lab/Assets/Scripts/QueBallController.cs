using UnityEngine;
using System.Collections;

[RequireComponent(typeof(Rigidbody))]
public class QueBallController : MonoBehaviour {

    [SerializeField]
    private float mouseSensitivity = 5f;
    [SerializeField]
    private float power = 100f;

    private Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    void FixedUpdate()
    {
        if (Input.GetKey(KeyCode.Space))
            rb.AddForce(transform.forward * power);
    }
}
