#pragma once
class Position
{
	int _x, _y;
public:
	Position() {

	}
	~Position() {

	}

	Position(int x, int y) {
		_x = x;
		_y = y;
	}
	void set_x(int x) { _x = x; }
	void set_y(int y) { _y = y; }
	int get_x() { return _x; }
	int get_y() { return _y; }
};

