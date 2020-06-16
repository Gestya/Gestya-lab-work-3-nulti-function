#include "gtest/gtest.h"
#include "quicksort.h"

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>


namespace
{
	template<class T>
	auto cmp_function = [](const T& a, const T& b) -> bool {
		return a < b;
	};

	#include <Windows.h>
	#include <cassert>
	#include <cstdio>
	class Timer
	{
	public:
		Timer()
		{
			if (!QueryPerformanceFrequency(&frequency))
				throw std::exception("QueryPerformanceFrequency failed");

			reset();
		}
		~Timer() = default;

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
}

TEST(CompareAlgorithms, EqualResults)
{
	srand(static_cast<unsigned int>(time(NULL)));

	size_t len{ 200 };
	std::vector<int> v1(len);
	for (size_t i = 0; i < len; ++i)
	{
		v1[i] = rand();
	}
	std::vector<int> v2{ v1 };

	quick_sort<int>(v1.data(), 0, v1.size() - 1, cmp_function<int>);
	mt_quick_sort<int>(v2.data(), 0, v2.size() - 1, cmp_function<int>);

	EXPECT_EQ(len, v1.size());
	EXPECT_EQ(len, v2.size());
	for (size_t i = 1; i < v1.size(); ++i)
	{
		EXPECT_LE(v1[i - 1], v1[i]);
	}
	for (size_t i = 1; i < v2.size(); ++i)
	{
		EXPECT_LE(v2[i - 1], v2[i]);
	}
	for (size_t i = 0; i < len; ++i)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
}


TEST(CompareAlgorithms, PerformanceTest)
{
	srand(static_cast<unsigned int>(time(NULL)));

	Timer timer;
	int repeats{ 200 };

   std::vector<double> multithread, single;
    for (int k = 0; k < repeats; k++)
    {
		// multithread
        {
            int len{ 10000 };
			std::vector<int> vct(len);
			for (size_t i = 0; i < len; ++i)
			{
				vct[i] = rand();
			}

			timer.reset();
            mt_quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);
			multithread.push_back(timer.get_time());

			EXPECT_EQ(len, vct.size());
			for (size_t i = 1; i < vct.size(); ++i)
			{
				EXPECT_LE(vct[i - 1], vct[i]);
			}
        }
		// single
        {
			int len{ 10000 };
			std::vector<int> vct(len);
			for (size_t i = 0; i < len; ++i)
			{
				vct[i] = rand();
			}

			timer.reset();
			quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);
			single.push_back(timer.get_time());

			EXPECT_EQ(len, vct.size());
			for (size_t i = 1; i < vct.size(); ++i)
			{
				EXPECT_LE(vct[i - 1], vct[i]);
			}
        }
        std::cout << k << "/" << repeats << "\t\t" <<
			multithread.back() << "\t" << single.back() << "\n";
    }

    double average_multithread{ 0 };
    for (const auto& e : multithread)
		average_multithread += e;
	average_multithread /= static_cast<double>(multithread.size());

	double average_single{ 0 };
	for (const auto& e : single)
		average_single += e;
	average_single /= static_cast<double>(single.size());

    std::cout << "-------------------------------------------\n";
    std::cout << average_multithread << "\t" << average_single << "\n";
	EXPECT_LT(average_multithread, average_single);

	double profit = 100.0 - (average_multithread / average_single) * 100.0;
    std::cout << "Profit = " << profit << "%" << std::endl;

	EXPECT_GT(profit, 10.0); // Profit > 10%
}
