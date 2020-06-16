#pragma once

class Widget; // Forward declaration

class IVisitor
{
public:
	virtual void visitWidget(const Widget* widget, const char* class_name) = 0;
	virtual void visitWindow(const Widget* window) = 0;
};

