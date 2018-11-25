#pragma once


#include <ctime>



namespace mytimer
{

	class Timer

	{

	public:
		static Timer * instance()
		{
			static Timer * inst(new Timer());
			return inst;
		}

		int getTime();

		bool setInterrupt(int milliSeconds);

	private:

		clock_t t1_;

		int second_;


	private:

		Timer();
		~Timer();
		Timer(const Timer&) {}           // Private copy-construction

		Timer& operator=(Timer&) {}      // Private assignment

		void * operator new (std::size_t aSize);
		void operator delete(void* obj);

		void * operator new[](std::size_t aSize);
		void operator delete[](void* obj);
	};

}
