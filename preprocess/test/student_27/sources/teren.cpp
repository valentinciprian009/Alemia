#include "teren.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>
#define COL_DISTANCE_BETWEEN_ROWS	5
#define COL_LAST_MATRIX_POSITION    123


teren::teren()
{

}


teren::~teren()
{
}

void teren::level1()
{
	int i, ROW_MATRIX = { 5 };
	int ROW_MATRIX_COPY = ROW_MATRIX;
	int COL_FIRST_MATRIX_POSITION = { 20 }, copy_first_pos = COL_FIRST_MATRIX_POSITION+13;
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	
	
	for (i = ROW_MATRIX; i <= 35; i++)
		conOut(i,COL_FIRST_MATRIX_POSITION) << casuta;
	for (i = ROW_MATRIX; i <= 35; i++)
		conOut(i, COL_FIRST_MATRIX_POSITION+10) << casuta;
	for (int j = 1; j <= 7; j++)
	{
		for (i = COL_FIRST_MATRIX_POSITION; i <= COL_FIRST_MATRIX_POSITION + 10; i++)
			conOut(ROW_MATRIX_COPY, i) << casuta;
		ROW_MATRIX_COPY = ROW_MATRIX_COPY + 5;
	}
	ROW_MATRIX_COPY = ROW_MATRIX;
	for (int j = 1; j <= 3; j++)
	{
		for (i = COL_FIRST_MATRIX_POSITION+13; i <= COL_LAST_MATRIX_POSITION; i++)
			conOut(ROW_MATRIX_COPY, i) << casuta;
		ROW_MATRIX_COPY = ROW_MATRIX_COPY + 5;
	}
	for (int j = 1; j <= 10; j++)
	{
		for (i =ROW_MATRIX; i <=15 ; i++)
			conOut(i, copy_first_pos) << casuta;
		copy_first_pos = copy_first_pos + 10;
	}
	

}

void teren::level2()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int i, ROW_MATRIX = { 15 };
	int ROW_MATRIX_COPY = ROW_MATRIX;
	int COL_FIRST_MATRIX_POSITION = { 20 }, copy_first_pos = COL_FIRST_MATRIX_POSITION + 13;
	for (int j = 1; j <= 3; j++)
	{
		for (i = COL_FIRST_MATRIX_POSITION + 13; i <= COL_LAST_MATRIX_POSITION; i++)
			conOut(ROW_MATRIX_COPY, i) << casuta;
		ROW_MATRIX_COPY = ROW_MATRIX_COPY + 5;
	}
	for (int j = 1; j <= 10; j++)
	{
		for (i = ROW_MATRIX; i <= 25; i++)
			conOut(i, copy_first_pos) << casuta;
		copy_first_pos = copy_first_pos + 10;
	}
}

void teren::level3()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int i, ROW_MATRIX = { 25 };
	int ROW_MATRIX_COPY = ROW_MATRIX;
	int COL_FIRST_MATRIX_POSITION = { 20 }, copy_first_pos = COL_FIRST_MATRIX_POSITION + 13;
	for (int j = 1; j <= 3; j++)
	{
		for (i = COL_FIRST_MATRIX_POSITION + 13; i <= COL_LAST_MATRIX_POSITION; i++)
			conOut(ROW_MATRIX_COPY, i) << casuta;
		ROW_MATRIX_COPY = ROW_MATRIX_COPY + 5;
	}
	for (int j = 1; j <= 10; j++)
	{
		for (i = ROW_MATRIX; i <= 35; i++)
			conOut(i, copy_first_pos) << casuta;
		copy_first_pos = copy_first_pos + 10;
	}
}

bool teren::click()
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();
	if (action.find("double clicked") != std::string::npos)
	{
		std::string x, y;
		for (int i = action.find("(") + 1; i < action.find(","); i++)
			x = x + action;
		for (int i = action.find(",") + 1; i < action.find(")"); i++)
			y = y + action;
		int m_x, m_y;
		m_x = stoi(x);
		m_y = stoi(y);
		if (m_x >= 10 && m_x <= 130 && m_y >= 5 && m_y <= 50)
			return true;

	}
	return false;
}
