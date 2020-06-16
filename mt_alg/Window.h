#pragma once
#include "Widget.h"
#include <vector>

class Window : public Widget
{
public:
	Window(Widget* parent = nullptr);
	~Window() override;

	void draw() override;

	// -------------------------------------
	// Composite interface
	// -------------------------------------
	bool addChild(Widget* child) override;
	bool removeChild(size_t index) override;
	const Widget* getChild(size_t index) const override;
	Widget* getChild(size_t index) override;
	size_t getChildrenCound() const override;

	// -------------------------------------
	// Visitor pattern
	// -------------------------------------
	void accept(IVisitor& visitor) const override;

public:
	std::vector<Widget*> children;
};

