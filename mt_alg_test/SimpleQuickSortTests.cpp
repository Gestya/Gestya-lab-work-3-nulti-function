#include "gtest/gtest.h"
#include "quicksort.h"

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


namespace
{
	template<class T>
	auto cmp_function = [](const T& a, const T& b) -> bool {
		return a < b;
	};
}


TEST(SimpleQuickSort, ZeroInterval)
{
	int zero{ 0 };
	std::vector<int> vct{ zero };
	quick_sort<int>(vct.data(), 0, 0, cmp_function<int>);
	EXPECT_EQ(1, vct.size());
	EXPECT_EQ(zero, vct[0]);
}

TEST(SimpleQuickSort, WrongInterval)
{
	std::vector<int> v1{ 7, 4, 9, 2, 5 };
	std::vector<int> unsorted{ v1 };
	quick_sort<int>(v1.data(), 3, 2, cmp_function<int>);
	EXPECT_EQ(v1, unsorted);
}

TEST(SimpleQuickSort, InverseComparator)
{
	auto inverse_int_cmp = [](const int& a, const int& b) -> bool {
		return a > b;
	};

	std::vector<int> vct{ 7, 4, 9, 2, 5 };
	quick_sort<int>(vct.data(), 0, vct.size() - 1, inverse_int_cmp);
	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_GE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, AllShortArrays)
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (size_t len = 1; len < 20; ++len)
	{
		std::vector<int> vct(len);
		for (size_t i = 0; i < len; ++i)
			vct[i] = rand();

		quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

		for (size_t i = 1; i < vct.size(); ++i)
		{
			EXPECT_LE(vct[i - 1], vct[i]);
		}
	}
}

TEST(SimpleQuickSort, IncreasingArray)
{
	size_t len{ 40 };
	std::vector<int> vct(len);

	for (size_t i = 0; i < len; ++i)
	{
		vct[i] = static_cast<int>(i * 2 + 100);
	}
	
	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, DecreasingArray)
{
	size_t len{ 40 };
	std::vector<int> vct(len);

	for (size_t i = 0; i < len; ++i)
	{
		vct[i] = static_cast<int>(2000 - i * 2);
	}

	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, OneSmaller)
{
	std::vector<int> vct{ 555, 555, 555, 555, 0, 555 };

	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, OneBigger)
{
	std::vector<int> vct{ 3, 111, 3, 3, 3, 3 };

	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, OneSmallerAndOneBigger)
{
	std::vector<int> vct{ 11, 3, 11, 11, 555, 11 };

	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, StringArray)
{
	std::vector<std::string> vct{
		"2nd", "International", "School", "Amplitudes"
		"Cosmology", "Holography", "Positive", "Geometries" };

	quick_sort<std::string>(vct.data(), 0, vct.size() - 1, cmp_function<std::string>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, FlolatArray)
{
	std::vector<float> vct{ 0.0f, -2.432f, 4.42243f, -23.54343f, 5.353f, 1.45e+4 };

	quick_sort<float>(vct.data(), 0, vct.size() - 1, cmp_function<float>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}

TEST(SimpleQuickSort, HugeArrayl)
{
	srand(static_cast<unsigned int>(time(NULL)));

	size_t len{ 50000 };
	std::vector<int> vct(len);
	for (size_t i = 0; i < len; ++i)
		vct[i] = rand();

	quick_sort<int>(vct.data(), 0, vct.size() - 1, cmp_function<int>);

	for (size_t i = 1; i < vct.size(); ++i)
	{
		EXPECT_LE(vct[i - 1], vct[i]);
	}
}