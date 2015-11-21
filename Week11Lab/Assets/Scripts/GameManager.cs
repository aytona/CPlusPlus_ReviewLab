using UnityEngine;
using System.Collections;

public class GameManager : Singleton<GameManager>{

    private int _numBalls;

    public int NumBalls
    {
        get
        {
            return _numBalls;
        }
        set
        {
            _numBalls = value;
        }
    }


}
