#pragma once
class IDrawable
{
protected:
	int x;
	int y;
public:
	IDrawable() {};
	IDrawable(int X, int Y) { this->x = X; this->y = Y; };
	IDrawable(const IDrawable& old) { this->x = old.x; this->y = old.y; };
	int getX() { return this->x; };
	int getY() { return this->y; };
};