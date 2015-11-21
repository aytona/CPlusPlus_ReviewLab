using UnityEngine;
using System.Collections;

public class DestroyOnTouch : MonoBehaviour {

	void OnTriggerEnter(Collider other)
    {
        Destroy(other.gameObject);
        if (other.tag == "Player")
            Application.LoadLevel(Application.loadedLevel);
        if (other.tag == "Ball")
            GameManager.Instance.NumBalls--;
    }
}
