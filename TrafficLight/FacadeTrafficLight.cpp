#include"stdafx.h"

#include"FacadeTrafficLight.h"
#include"AllLight.h"

#include <iostream>
#include <fstream>  

namespace trafficlight
{

	FacadeLights::FacadeLights(int redTime, int yellowTime, int greenTime) :
		redTime_(redTime), // Duration of luminescence
		yellowTime_(yellowTime), // Duration of luminescence
		greenTime_(greenTime) // Duration of luminescence
	{
		timer_ = mytimer::Timer::instance(); //Get timer

		// Create lightings
		light_.push_back(new RedLight);
		light_.push_back(new YellowLight);
		light_.push_back(new GreenLight);

		oneColourPassTime_ = 0; // The duration of the glow of the current color
		keyComtrol_ = 's';		// Automatic start
		timeLight_ = RED_;		// Starting with red

		outfile = new std::ofstream("log_test.txt");
	}

	FacadeLights::~FacadeLights()
	{
		using namespace std;

		vector<Light*>::iterator begin = light_.begin();
		vector<Light*>::iterator end = light_.end();

		// remove lamps
		for (; begin != end; begin++)
		{
			delete *begin;
		}
		//free vector
		light_.clear();

		outfile->close();
		delete outfile;
	}

	void FacadeLights::drow(HANDLE handle, const char key)
	{
		keyComtrol_ = key; // check messages from the keyboard

		int lightPosition = computeTimeLight(); //Determine the current color

		light_.at(lightPosition)->drowTrafficLight(handle); // Drawing current state
	}


	//Determine the current color
	FacadeLights::TimeLight FacadeLights::computeTimeLight()
	{
		
		static int startTime(timer_->getTime()); //Initialize at startup

		int currentTime = timer_->getTime();	
		if (keyComtrol_ == 'S' || keyComtrol_ == 's')
		{
			oneColourPassTime_ = currentTime - startTime;	//Calculate the duration
		}
		else if (keyComtrol_ == 'P' || keyComtrol_ == 'p')
		{
			startTime = currentTime - oneColourPassTime_;	//Change the start time

			*outfile << "Pause, Time = " << timer_->getTime() << std::endl;

			return timeLight_;  //return the current color
		}

		switch (timeLight_)
		{
		case RED_:
			if (oneColourPassTime_ < redTime_)
			{
				*outfile << "Start red colour, Time = " << timer_->getTime() << std::endl;

				return RED_;
			}
			else
			{
				oneColourPassTime_ = 0;
				startTime = timer_->getTime();
				timeLight_ = YELLOW_; //Specify the next color
				*outfile << "End red colour, Time = " << timer_->getTime() << std::endl;

				return YELLOW_;
			}
			break;
		case YELLOW_:
			if (oneColourPassTime_ < yellowTime_)
			{
				*outfile << "Start yellow colour, Time = " << timer_->getTime() << std::endl;

				return YELLOW_;
			}
			else
			{
				oneColourPassTime_ = 0;
				startTime = timer_->getTime();
				timeLight_ = GREEN_; // Specify the next color
				*outfile << "End yellow colour, Time = " << timer_->getTime() << std::endl;

				return GREEN_;
			}
			break;
		case GREEN_:
			if (oneColourPassTime_ < greenTime_)
			{
				*outfile << "Start green colour, Time = " << timer_->getTime() << std::endl;

				return GREEN_;
			}
			else
			{
				oneColourPassTime_ = 0;
				startTime = timer_->getTime();
				timeLight_ = RED_; // Specify the next color
				*outfile << "End green colour, Time = " << timer_->getTime() << std::endl;

				return RED_;
			}
			break;
		default:
			// Here need to handle the error
			*outfile << "Error Message, Time = " << timer_->getTime() << std::endl;

			return timeLight_; //
			break;
		}

	}

}
