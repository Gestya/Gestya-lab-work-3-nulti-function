#include "StatisticVisitor.h"
#include "Widget.h"

void StatisticVisitor::visitWidget(const Widget* widget, const char* class_name)
{
	((void)class_name); // Will be used in furter versions

	if (widget)
	{
		StatRecord new_record{
			/*std::string(class_name ? class_name : "") + */ widget->getName(),
			static_cast<uint64_t>(widget->getSize().width) *
			static_cast<uint64_t>(widget->getSize().height)
		};
		stat.emplace_back(new_record);
	}
}

void StatisticVisitor::visitWindow(const Widget* window)
{
	if (window)
	{
		StatRecord new_record{
			/*"WINDOW " + */ window->getName(),
			static_cast<uint64_t>(window->getSize().width)*
			static_cast<uint64_t>(window->getSize().height)
		};
		stat.emplace_back(new_record);

		const size_t widgets_count = window->getChildrenCound();
		for (size_t i = 0; i < widgets_count; ++i)
		{
			const Widget* child = window->getChild(i);
			if (child) // must be not null, but who knows
				child->accept(*this);
		}
	}
}