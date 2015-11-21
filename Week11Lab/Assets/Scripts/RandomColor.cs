using UnityEngine;
using System.Collections;

[RequireComponent(typeof(Shader))]
public class RandomColor : MonoBehaviour {

    void Start()
    {
        Renderer rend = GetComponent<Renderer>();
        rend.material.color = new Color(Random.Range(0f, 1f), Random.Range(0f, 1f), Random.Range(0f, 1f));
    }
}
