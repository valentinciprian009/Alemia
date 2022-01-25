#pragma once
#include <iostream>

class iDrawable
{
public:
	virtual void print() const = 0;
	virtual ~iDrawable() = 0 {}
	friend std::ostream& operator<<(std::ostream& out, const iDrawable& toPrint);
};

