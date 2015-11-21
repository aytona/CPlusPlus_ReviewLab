using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class UI : MonoBehaviour {

    [SerializeField]
    private Text counterText;

    void Start()
    {
        GameObject[] balls = GameObject.FindGameObjectsWithTag("Ball");
        GameManager.Instance.NumBalls = balls.Length;
    }

    void Update()
    {
        counterText.text = "Balls: " + GameManager.Instance.NumBalls.ToString();
    }
}
