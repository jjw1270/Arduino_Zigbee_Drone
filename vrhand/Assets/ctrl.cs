using System;
using UnityEngine;
using System.IO.Ports;
using System.Collections;

public class ctrl : MonoBehaviour
{
	public Transform hand;
	public Transform[] finger;
	string[] result = { "0", "0", "0", "0", "0", "0", "0", "0" };


	SerialPort stream = new SerialPort("COM12", 9600, Parity.None, 8, StopBits.One);
	void Start()
	{
		stream.Open();
		StartCoroutine(play());
	}
	void OnApplicationQuit()
	{
		stream.Close();
	}
	string tmp = null;
	void Update()
	{
		try
		{
			if (stream.IsOpen)
			{
				Debug.Log(stream.ReadLine());
				tmp = stream.ReadLine();
				stream.ReadTimeout = 100;
				result = tmp.Split(new char[] { ',' });  // ,�� �������� �߶� �迭 result �� �־��.

				/*for (int i = 0; i < result.Length; i++)  // �迭�� 0 ���� ����Ǹ�, �迭�� ���̸�ŭ ��ȯ
				{
					Debug.Log(i + ": " + result[i]);
				}*/
			}

		}
		catch (TimeoutException e)
		{
			//Debug.Log(e);
		}


	}
	IEnumerator play()
	{
		while (true)
		{
			hand.localRotation = Quaternion.Euler(new Vector3(float.Parse(result[0]), float.Parse(result[1]), float.Parse(result[2])));
			for (int i = 0; i < finger.Length; i++)
			{
				finger[i].localPosition = new Vector3(finger[i].localPosition.x, finger[i].localPosition.y, float.Parse(result[i + 3]) / 50.0f);
			}
			Debug.Log(result[0]);

			yield return new WaitForSeconds(0.1f);
		}
	}

}