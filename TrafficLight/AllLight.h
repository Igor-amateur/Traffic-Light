#pragma once

#include"Light.h"

//State Drawing Classes

namespace trafficlight
{

	class RedLight : public Light
	{
	public:
		RedLight();
		~RedLight();

		virtual void drowTrafficLight(HANDLE handle);

	private:

	};

	/////////////////////////////////////////////////////////

	class YellowLight : public Light
	{
	public:
		YellowLight();
		~YellowLight();

		virtual void drowTrafficLight(HANDLE handle);

	private:

	};

	////////////////////////////////////////////////////////////

	class GreenLight : public Light
	{
	public:
		GreenLight();
		~GreenLight();

		virtual void drowTrafficLight(HANDLE handle);

	private:

	};


}