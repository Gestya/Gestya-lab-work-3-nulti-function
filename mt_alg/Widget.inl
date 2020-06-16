// -------------------------------------------
// Parent
inline Widget* Widget::getParent() const
{
	return parent;
}

// -------------------------------------------
// Position
inline const Position& Widget::getPosition() const
{
	return position;
}

inline Position& Widget::getPosition()
{
	return position;
}

inline void Widget::setPosition(const Position& position)
{
	this->position = position;
}

// -------------------------------------------
// Size
inline const Size& Widget::getSize() const
{
	return size;
}

inline Size& Widget::getSize()
{
	return size;
}

inline void Widget::setSize(const Size& size)
{
	this->size = size;
}

// -------------------------------------------
// Name
inline const std::string& Widget::getName() const
{
	return name;
}

inline std::string& Widget::getName()
{
	return name;
}

inline void Widget::setName(const std::string& name)
{
	this->name = name;
}