#pragma once
#include"UserInterface.h"

class Entity
{
protected:
	UserInterface::ConsoleInput& consoleIn;
	UserInterface::ConsoleOutput& consoleOut;
	int rowUpperLeft, colUpperLeft;
public:
	Entity() : consoleIn(UserInterface::ConsoleInput::getInstance()), consoleOut(UserInterface::ConsoleOutput::getInstance()), rowUpperLeft(), colUpperLeft() { ; }
	Entity(int row_ul, int col_ul) : consoleIn(UserInterface::ConsoleInput::getInstance()), consoleOut(UserInterface::ConsoleOutput::getInstance()), rowUpperLeft(row_ul), colUpperLeft(col_ul) { ; }
	Entity(const Entity& e) : consoleIn(UserInterface::ConsoleInput::getInstance()), consoleOut(UserInterface::ConsoleOutput::getInstance()), rowUpperLeft(e.rowUpperLeft), colUpperLeft(e.colUpperLeft) { ; }
	UserInterface::ConsoleInput& consoleInput() const { return consoleIn; }
	UserInterface::ConsoleOutput& consoleOutput() const { return consoleOut; }
	void setCoordsUpperLeft(int row, int col) { rowUpperLeft = row; colUpperLeft = col; }
	int getRowUpperLeft() const { return rowUpperLeft; }
	int getColUpperLeft() const { return colUpperLeft; }
};