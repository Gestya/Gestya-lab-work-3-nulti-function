#include "Label.h"
#include "IVisitor.h"
#include <iostream>

Label::Label(Widget* parent /* = nullptr*/)
	: Widget(parent)
{
}

Label::~Label()
{
	// nothing to delete
}

void Label::draw()
{
	// some specific implementation of render;
	std::cout << "Draw Label" << std::endl;
}

void Label::accept(IVisitor& visitor) const
{
	visitor.visitWidget(this, "Label");
}