#pragma once
#include "IVisitor.h"
#include <string>
#include <vector>

struct StatRecord
{
	std::string name;
	uint64_t square;
};

using Statistics = std::vector<StatRecord>;

class StatisticVisitor : public IVisitor
{
public:
	void visitWidget(const Widget* widget, const char* class_name) override;
	void visitWindow(const Widget* window) override;

	inline Statistics& getStatistics();

private:
	Statistics stat;
};

 // --- Inline --------------------

inline Statistics& StatisticVisitor::getStatistics()
{
	return stat;
}

