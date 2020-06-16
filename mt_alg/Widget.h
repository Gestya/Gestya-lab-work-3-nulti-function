#pragma once
#include <string>
#include "IComposite.h"

struct Position
{
	Position() {}
	Position(int x, int y)
		: x{ x }
		, y{ y }
	{}
	int x{ 0 };
	int y{ 0 };
};

struct Size
{
	Size() {}
	Size(int width, int height)
		: width{ width }
		, height{ height }
	{}
	int width{ 0 };
	int height{ 0 };
};

class IVisitor; // Forward declaration

class Widget : public IComposite< Widget>
{
public:
	Widget(Widget* parent = nullptr);
	virtual ~Widget();

	virtual void draw() = 0;

	// -------------------------------------
	// Composite interface
	// -------------------------------------
	bool addChild(Widget* child) override;
	bool removeChild(size_t index) override;
	const Widget* getChild(size_t index) const override;
	Widget* getChild(size_t index) override;
	size_t getChildrenCound() const override;

	// -------------------------------------
	// Visitor parretn
	// -------------------------------------
	virtual void accept(IVisitor& visitor) const = 0;

	// -------------------------------------
	// Properties
	// -------------------------------------
	inline Widget* getParent() const;

	inline const Position& getPosition() const;
	inline Position& getPosition();
	inline void setPosition(const Position& position);

	inline const Size& getSize() const;
	inline Size& getSize();
	inline void setSize(const Size& size);

	inline const std::string& getName() const;
	inline std::string& getName();
	inline void setName(const std::string& name);

protected:
	Widget* parent{ nullptr };
	Position position;
	Size size;
	std::string name;
};

#include "Widget.inl"

