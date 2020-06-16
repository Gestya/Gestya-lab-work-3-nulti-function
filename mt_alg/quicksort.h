#pragma once

#include <functional>
//#include <chrono>
#include <thread>

template<class T>
size_t quick_sort_one_pass(T* a, size_t low, size_t high,
    const std::function<bool(const T&, const T&)>& cmp_fun)
{
    if (low >= high)
        return 0;

    T pivot = a[(low + high) / 2];

    size_t i = low;
    size_t j = high;

    while (true)
    {
        while (cmp_fun(a[i], pivot))
            i++;

        while (cmp_fun(pivot, a[j]))
            j--;

        if (i >= j)
            break;

        std::swap(a[i], a[j]);
        i++;
        j--;
    }

    return j;
    //quick_sort(a, low, j, cmp);
    //quick_sort(a, j + 1, high, cmp);
}

template<class T>
void quick_sort(T* a, size_t low, size_t high,
    const std::function<bool(const T&, const T&)>& cmp_fun)
{
    if (low >= high)
        return;

    size_t middle = quick_sort_one_pass(a, low, high, cmp_fun);
    if (middle >= 0)
    {
        quick_sort(a, low, middle, cmp_fun);
        quick_sort(a, middle + 1, high, cmp_fun);
    }
}

template<class T>
void mt_quick_sort(T* a, size_t low, size_t high,
    const std::function<bool(const T&, const T&)>& cmp_fun)
{
    if (low >= high)
        return;

    size_t middle = quick_sort_one_pass(a, low, high, cmp_fun);

    std::thread lo_part(quick_sort<T>, a, low, middle, cmp_fun);
    std::thread hi_parg(quick_sort<T>, a, middle + 1, high, cmp_fun);
    lo_part.join();
    hi_parg.join();
}
