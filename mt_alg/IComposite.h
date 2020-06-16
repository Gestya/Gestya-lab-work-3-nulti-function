#pragma once

// Interface class IComposite
// Implementats the Coposite design pattern 

template<class Child>
class IComposite
{
public:
	virtual bool addChild(Child* child) = 0;
	virtual bool removeChild(size_t index) = 0;
	virtual const Child* getChild(size_t index) const = 0;
	virtual Child* getChild(size_t index) = 0;
	virtual size_t getChildrenCound() const = 0;
};