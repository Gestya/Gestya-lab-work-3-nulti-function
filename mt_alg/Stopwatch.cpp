#include "Stopwatch.h"
#include <iostream>


#include <Windows.h>
#include <cassert>
#include <cstdio>
class StopwatchImpl
{
public:
	StopwatchImpl()
	{
		if (!QueryPerformanceFrequency(&frequency))
			throw std::exception("QueryPerformanceFrequency failed");

		reset();
	}
	~StopwatchImpl() = default;

	void reset() 
	{
		if (!QueryPerformanceCounter(&start_count))
			throw std::exception("QueryPerformanceCounter failed");
	}

	double get_time() {
		LARGE_INTEGER now;
		if (!QueryPerformanceCounter(&now))
			throw std::exception("QueryPerformanceCounter failed");

		int64_t diff = now.QuadPart - start_count.QuadPart;

		return 1.0 / static_cast<double>(frequency.QuadPart) * diff;
	}
	
private:
	LARGE_INTEGER frequency;
	LARGE_INTEGER start_count;
};


Stopwatch::Stopwatch()
{
	p_impl = new StopwatchImpl();
}

Stopwatch::~Stopwatch()
{
	delete p_impl;
}

void Stopwatch::reset()
{
	p_impl->reset();
}

double Stopwatch::get_time()
{
	return p_impl->get_time();
}
