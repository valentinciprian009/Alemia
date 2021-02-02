#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <chrono>
#include<thread>
#include "Zombie.h"
class ZombieBanal :
	public Zombie

{
public:
	ZombieBanal(): Zombie(){}
	~ZombieBanal();
	void pune_zombie();
};

