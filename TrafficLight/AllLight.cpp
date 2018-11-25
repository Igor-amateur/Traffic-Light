#include "stdafx.h"

#include "AllLight.h"

//State Drawing Classes

namespace trafficlight
{

	RedLight::RedLight()
	{
		// do nothing
	}

	RedLight::~RedLight()
	{
		// do nothing
	}

	void RedLight::drowTrafficLight(HANDLE handle)
	{
		drowRoof();
		drowRedLight(handle);
		drowOffLight();
		drowOffLight();
		drowBase();
	}


	/////////////

	YellowLight::YellowLight()
	{
		// do nothing
	}

	YellowLight::~YellowLight()
	{
		// do nothing
	}

	void YellowLight::drowTrafficLight(HANDLE handle)
	{
		if (YellowIsOn())
		{
			drowRoof();
			drowOffLight();
			drowYellowLight(handle);
			drowOffLight();
			drowBase();

			setYellowIsOn(false);
		}
		else
		{
			drowRoof();
			drowOffLight();
			drowOffLight();
			drowOffLight();
			drowBase();
			setYellowIsOn(true);
		}
	}

	//////////////

	GreenLight::GreenLight()
	{
		// do nothing
	}

	GreenLight::~GreenLight()
	{
		// do nothing
	}

	void GreenLight::drowTrafficLight(HANDLE handle)
	{
		drowRoof();
		drowOffLight();
		drowOffLight();
		drowGreenLight(handle);
		drowBase();
		if (YellowIsOn() == false)
		{
			setYellowIsOn(true);
		}
	}

}