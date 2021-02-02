#pragma once


#include<conio.h>
#include<thread>
#include<stdlib.h>
#include<iostream>

#include <chrono>
#include<Windows.h> 
#include <time.h>
#include<locale.h>
#include<vector>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

#define BEGIN_LOGIN_BOX_ROW		5//row
#define END_LOGIN_BOX_ROW		40//row
#define BEGIN_LOGIN_BOX_COL		20//col
#define END_LOGIN_BOX_COL   	155//col
using namespace std::chrono;

class MY_UTILS
{
	static int id_;
public:
	MY_UTILS();
	virtual ~MY_UTILS();
	static int GenerateId();
	static void SetColor(int Value);
	static void ClearScreen();
	static void DrawBox();
	static int RandomSelectElementDisplay();
	static int RandomCoord_x();
	static float RandomCoord_Y();
	static int RandomCoord_Y_level2();
};

