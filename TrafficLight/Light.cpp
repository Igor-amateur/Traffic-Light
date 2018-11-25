#include "stdafx.h"

#include"Light.h"
#include<iostream>

namespace trafficlight
{

	const char QUADRATE(254);	//Glowing element of the traffic light
	const char HEEL(208);		//base of the traffic light

	Light::Light()
	{
		yellowIsOn_ = true; //Always on at the beginning
	}

	Light::~Light()
	{

	}


	void Light::drowRoof()
	{
		using namespace std;
		cout << endl;
		cout << "           " << '_' << endl;
	}

	void Light::drowOffLight()
	{
		using namespace std;

		cout << "          " << '|' << QUADRATE << '|' << endl;
	}

	void Light::drowGreenLight(HANDLE handle)
	{
		using namespace std;
		cout << "          " << '|';
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN); //Set the color green
		cout << QUADRATE;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //Restore white
		cout << '|' << endl;
	}

	void Light::drowYellowLight(HANDLE handle)
	{
		using namespace std;
		cout << "          " << '|';
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN); //Set the color Yellow
		cout << QUADRATE;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << '|' << endl;
	}

	void Light::drowRedLight(HANDLE handle)
	{
		using namespace std;
		cout << "          " << '|';
		SetConsoleTextAttribute(handle, FOREGROUND_RED); //Set the color Red
		cout << QUADRATE;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //Restore white
		cout << '|' << endl;
	}

	void Light::drowBase()
	{
		using namespace std;
		cout << "           " << 'T' << endl;
		cout << "           " << '|' << endl;
		cout << "           " << '|' << endl;
		cout << "           " << '|' << endl;
		cout << "           " << '|' << endl;
		cout << "           " << HEEL << endl;
	}

	//Indicates flashing yellow status
	bool Light::YellowIsOn()
	{
		return yellowIsOn_;
	}

	//Sets flashing yellow status
	void Light::setYellowIsOn(bool state)
	{
		yellowIsOn_ = state;
	}

}