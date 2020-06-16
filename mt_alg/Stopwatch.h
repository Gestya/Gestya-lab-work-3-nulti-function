#pragma once

class StopwatchImpl;

class Stopwatch
{
public:
	Stopwatch();
	~Stopwatch();

	void reset();
	double get_time();

private:
	StopwatchImpl* p_impl;
};

