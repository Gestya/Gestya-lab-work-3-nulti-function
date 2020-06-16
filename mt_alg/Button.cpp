#include "Button.h"
#include "IVisitor.h"
#include <iostream>

Button::Button(Widget* parent /* = nullptr*/)
	: Widget(parent)
{
}

Button::~Button()
{
	// nothing to delete
}

void Button::draw()
{
	// some specific implementation of render;
	std::cout << "Draw Button" << std::endl;
}

void Button::accept(IVisitor& visitor) const
{
	visitor.visitWidget(this, "Button");
}