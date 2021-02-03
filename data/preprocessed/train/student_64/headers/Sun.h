#pragma once
#include "Square.h"
#include <vector>
#include <string>
class Sun
{
	Square square;
	std::string nume = "Sun";
public:
	Sun();
	~Sun();

	Sun(Square sq) { square = sq; }
	void setSquare(Square sq) {
		square = sq;
	}
	Square getSquare() {
		return square;
	}

};

