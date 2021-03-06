// TrafficLight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<Windows.h>
#include<iostream>
#include <conio.h> // for _kbhit()

#include"Timer.h"
#include"FacadeTrafficLight.h"

namespace mws //create my work space

{

	using namespace mytimer;
	using namespace trafficlight;

}


int main()
{
	const int DURATION_RED(2); //seconds
	const int DURATION_YELLOW(4); //seconds
	const int DURATION_GREEN(3); //seconds

	const int PAUSE(250); //milliseconds

	const int KSM_224(224); //keyboard system message
	const int KSM_63(63); //keyboard system message

	mws::FacadeLights trafficLight(DURATION_RED, DURATION_YELLOW, DURATION_GREEN);
	mws::Timer* timer(mws::Timer::instance());//Displays the time and sets the interrupt period
	char key('s');//Stores a character from the keyboard
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole != INVALID_HANDLE_VALUE) {



		CONSOLE_FONT_INFOEX cfi;

		cfi.cbSize = sizeof(cfi);

		cfi.nFont = 0;

		cfi.dwFontSize.X = 0;

		cfi.dwFontSize.Y = 24;

		cfi.FontFamily = FF_DONTCARE;

		cfi.FontWeight = FW_NORMAL;

		wcscpy_s(cfi.FaceName, L"Lucida Console");

		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);



		CONSOLE_CURSOR_INFO ccf;

		ccf.dwSize = 100;//maximum cursor size

		ccf.bVisible = FALSE;//cursor is not displayed

		SetConsoleCursorInfo(hConsole, &ccf); //Set new cursor properties

	}

	COORD coord = { 0 }; //Coordinate cursor coordinates

	while (timer->setInterrupt(PAUSE))//interrupt loop
	{
		SetConsoleCursorPosition(hConsole, coord);//Set the drawing with (x = 0 and y = 0)

		trafficLight.drow(hConsole, key);

		std::cout << timer->getTime() << std::endl;
		if (_kbhit())//if you press a key on the keyboard

		{
			char temp = key;
			key = _getch();

			if (key == KSM_63)

			{

				std::cout << std::endl << "Choose English Layout" << std::endl;

			}
			else if (key == KSM_224)

			{

				key = _getch();//get the next value from the buffer

			}



			std::cout << key << std::endl;


			if ('e' == key || 'E' == key)
			{

				exit(0);//then finish

			}
			else if (!('s' == key || 'S' == key || 'p' == key || 'P' == key))
			{
				key = temp;
			}

		}
		///////////////////////// Clear screen
		std::cout << std::endl;
		std::cout << "                                                      " << std::endl;
		std::cout << "                                                      " << std::endl;
		std::cout << "                                                      " << std::endl;
		///////////////////////////////////////
	}

	return 0;
}

