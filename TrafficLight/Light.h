#pragma once
#include<Windows.h>

namespace trafficlight
{
	// Interface for different conditions
	class Light
	{
	public:
		Light();

		virtual ~Light();

		virtual void drowTrafficLight(HANDLE handle) = 0;

	protected:

		void drowRoof();
		void drowOffLight();
		void drowGreenLight(HANDLE handle);
		void drowYellowLight(HANDLE handle);
		void drowRedLight(HANDLE handle);
		void drowBase();

		bool YellowIsOn(); //Indicates flashing yellow status
		void setYellowIsOn(bool); //Sets flashing yellow status
	private:

		bool yellowIsOn_; //Stores flashing yellow status
	};

}