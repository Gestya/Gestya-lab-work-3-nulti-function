#include "Window.h"
#include "IVisitor.h"
#include <iostream>

Window::Window(Widget* parent /* = nullptr*/)
	: Widget(parent)
{
}

Window::~Window()
{
	for (auto& child : children)
		delete child;
}

void Window::draw()
{
	std::cout << "Draw WINDOW" << std::endl;
	for (auto& child : children)
		if (child) // mustnt' be a null but who knows
			child->draw();
}

bool Window::addChild(Widget* child)
{
	if (child)
	{
		children.push_back(child);
		return true;
	}

	return false;
}

bool Window::removeChild(size_t index)
{
	if (index < children.size())
	{
		children.erase(children.begin() + index);
		return true;
	}

	return false;
}

const Widget* Window::getChild(size_t index) const
{
	if (index < children.size())
	{
		return children[index];
	}

	return nullptr;
}

Widget* Window::getChild(size_t index)
{
	if (index < children.size())
	{
		return children[index];
	}

	return nullptr;
}

size_t Window::getChildrenCound() const
{
	return children.size();
}

void Window::accept(IVisitor& visitor) const
{
	visitor.visitWindow(this);
}