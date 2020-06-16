#pragma once
#include "Widget.h"
class Label : public Widget
{
public:
	Label(Widget* parent = nullptr);
	~Label() override;

	void draw() override;

	// Visitor pattern
	void accept(IVisitor& visitor) const override;
};

