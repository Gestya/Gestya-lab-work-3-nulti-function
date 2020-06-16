#include "EditLine.h"
#include "IVisitor.h"
#include <iostream>

EditLine::EditLine(Widget* parent /* = nullptr*/)
	: Widget(parent)
{
}

EditLine::~EditLine()
{
	// nothing to delete
}

void EditLine::draw()
{
	// some specific implementation of render;
	std::cout << "Draw EditLine" << std::endl;
}

void EditLine::accept(IVisitor& visitor) const
{
	visitor.visitWidget(this, "EditLine");
}