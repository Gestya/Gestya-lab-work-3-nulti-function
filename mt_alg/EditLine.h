#pragma once
#include "Widget.h"
class EditLine : public Widget
{
public:
	EditLine(Widget* parent = nullptr);
	~EditLine() override;

	void draw() override;

	// Visitor pattern
	void accept(IVisitor& visitor) const override;
};

