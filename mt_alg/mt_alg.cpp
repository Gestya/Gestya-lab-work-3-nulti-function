#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UI.h"
#include "StatisticVisitor.h"
#include "quicksort.h"
#include "Stopwatch.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Stopwatch stopwatch;

    auto name_cmp = [](const StatRecord& r1, const StatRecord& r2)->bool {
        return r1.name < r2.name;
    };
    auto square_cmp = [](const StatRecord& r1, const StatRecord& r2)->bool {
        return r1.square < r2.square;
    };

    std::vector<double> mt, single;
    for (int k = 0; k < 1000; k++)
    {
        {
            int cnt{ 10000 };
            Widget* desktop = buildRandomUI(cnt);

            StatisticVisitor stat_visitor;
            desktop->accept(stat_visitor);
            auto& stats = stat_visitor.getStatistics();

            stopwatch.reset();
            mt_quick_sort<StatRecord>(stats.data(), 0, stats.size() - 1, name_cmp);
            mt.push_back( stopwatch.get_time() );

            delete desktop;
        }
        {
            int cnt{ 10000 };
            Widget* desktop = buildRandomUI(cnt);

            StatisticVisitor stat_visitor;
            desktop->accept(stat_visitor);
            auto& stats = stat_visitor.getStatistics();

            stopwatch.reset();
            quick_sort<StatRecord>(stats.data(), 0, stats.size() - 1, name_cmp);
            single.push_back( stopwatch.get_time() );

            delete desktop;
        }
        std::cout << k << "\t" << mt.back() << "\t" << single.back() << "\n";
    }

    double st_mt{ 0 };
    for (const auto& e : mt)
        st_mt += e;
    double st_s{ 0 };
    for (const auto& e : single)
        st_s += e;
    std::cout << "-------------------------------------------\n";
    std::cout << st_mt/mt.size() << "\t" << st_s/single.size() << "\n";
    std::cout << "Profit = " << 100.0 - (st_mt / mt.size() / (st_s / single.size()) * 100.0) << std::endl;
    return 0;
}
