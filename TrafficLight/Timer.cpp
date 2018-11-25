#include "stdafx.h"

#include "Timer.h"

#include<Windows.h>
#include <iostream>
#include <stdio.h>


namespace mytimer

{

	// Private constructor

	Timer::Timer()
	{
		t1_ = clock();
		second_ = 0;
	}



	// Private destructor

	Timer::~Timer()
	{

	}

	// Private
	void * Timer::operator new (std::size_t aSize)

	{

		return malloc(aSize);

	}


	// Private
	void Timer::operator delete(void* obj)

	{

		free(obj);

	}


	// Private
	void * Timer::operator new[](std::size_t aSize)

	{

		return malloc(aSize);

	}


	// Private
	void Timer::operator delete[](void* obj)

	{

		free(obj);

	}


	int Timer::getTime()

	{
		int x(0); //time in seconds
		clock_t t2 = clock();

		x = (t2 - t1_) / CLOCKS_PER_SEC; //Get time in seconds

		if ((x - second_) > 0)
		{
			second_ = x; // Refresh time
		}

		return second_; 

	}

	//Allows you to create an interrupt in milliseconds

	bool Timer::setInterrupt(int milliSeconds)

	{
		static clock_t oldTime(0);
		clock_t rialTime = clock();
		int difference(0);

		while (true)
		{
			difference = (rialTime - oldTime) / (CLOCKS_PER_SEC / 1000);
			if (difference >= milliSeconds) // If the pause corresponds to the specified time
			{
				break; // leave loop
			}
			Sleep(milliSeconds - difference); // Wait for the right time
			rialTime = clock(); //Specify time
		}
		oldTime = rialTime; //Save current time
		return true; //Allow continue
	}
}