#pragma once

#include<vector>
#include"Timer.h"
#include"Light.h"

namespace trafficlight
{

	class FacadeLights
	{
	public:
		FacadeLights(int redTime, int yellowTime, int greenTime);
		~FacadeLights();

		void drow(HANDLE handle, const char key);

	private:
		enum TimeLight { RED_ = 0, YELLOW_ = 1, GREEN_ = 2 };

		TimeLight timeLight_;
		mytimer::Timer * timer_;
		std::vector<Light*> light_;
		char keyComtrol_; // saves user commands
		int oneColourPassTime_; //duration of the current color

		// Luminosity duration constants
		const int redTime_;
		const int yellowTime_;
		const int greenTime_;
	private:
		TimeLight computeTimeLight(); //Check current color with timer
	};


}