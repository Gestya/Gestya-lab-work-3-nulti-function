#include "Widget.h"

Widget::Widget(Widget* parent /* = nullptr */)
	: parent(parent)
	, position{0,0}
	, size{0,0}
	, name{""}
{
	if (parent)
		parent->addChild(this);
}

Widget::~Widget()
{
}


bool Widget::addChild(Widget* child)
{
	return false; // this class can't have children
}

bool Widget::removeChild(size_t index)
{
	return false; // this class can't have children
}

const Widget* Widget::getChild(size_t index) const
{
	return nullptr; // this class can't have children
}

Widget* Widget::getChild(size_t index)
{
	return nullptr; // this class can't have children
}

size_t Widget::getChildrenCound() const
{
	return 0; // this class can't have children
}