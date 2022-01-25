#include "Teren.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

void Teren::DrawScoreboard()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	int row=1, col=40;
	for (int i = 0; i < 7; i++) {
		conOut(row, col) << "*";
		col++;
	}
	for (int j = 0; j < 4; j++) {
		row += 1;
		col = 39;
		conOut(row, col) << "*";
		for (int i = 0; i < 7; i++) {
			col += 1;
			conOut(row, col) << " ";
		}
		conOut(row, col + 1) << "*";
	}
	col = 40;
	for (int i = 0; i < 7; i++) {
		conOut(row + 1, col) << "*";
		col++;
	}
}

void Teren::DrawCasset(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	int r = row;
	int c = col;
	for (int i = 0; i < 7; i++) {
		conOut(r, c) << "*";
		c++;
	}
	for (int j = 0; j < 4; j++) {
		r += 1;
		c = col-1;
		conOut(r, c) << "*";
		for (int i = 0; i < 7; i++) {
			c += 1;
			conOut(r, c) << " ";
		}
		conOut(r, c + 1) << "*";
	}
	c = col;
	for (int i = 0; i < 7; i++) {
		conOut(r + 1, c) << "*";
		c++;
	}
}

void Teren::DrawSunZone()
{
	
	int c = 50;
	for (int i = 0; i < 8; i++) {
		DrawCasset(1, c);
		c += 8;
	}
	
}

void Teren::DrawPlantsZone()
{
	int r = 10;
	for (int i = 0; i < 5; i++) {
		DrawCasset(r, 40);
		r += 5;
	}
}

void Teren::DrawTable(int i)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	DrawScoreboard();
	DrawSunZone();
	DrawPlantsZone();

	if (i == 1) {
		int r = 20;
		int c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
	}

	if (i == 2) {
		int r = 15;
		int c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
	}

	if (i == 3) {
		int r = 10;
		int c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}
		r += 5;
		c = 50;
		for (int j = 0; j < 8; j++) {
			DrawCasset(r, c);
			c += 8;
		}

	}
	
}
