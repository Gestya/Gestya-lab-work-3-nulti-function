#pragma once
#include "Widget.h"
class Button : public Widget
{
public:
	Button(Widget* parent = nullptr);
	~Button() override;

	void draw() override;

	// Visitor pattern
	void accept(IVisitor& visitor) const override;
};

