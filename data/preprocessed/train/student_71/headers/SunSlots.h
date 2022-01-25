#pragma once
class SunSlots
{
	bool data[9];
	static SunSlots* instance;
	SunSlots();
	~SunSlots();
public:
	static SunSlots& getInstance();
	void destroyInstance();
	void spawnSun();
	void clearSlot(int x);
	bool isSun(int x);
};

