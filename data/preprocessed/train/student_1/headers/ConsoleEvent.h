#pragma once
#define NOMINMAX
#include <windows.h>
#include <iostream>

using namespace std;

class ConsoleEvent
{
private:
	string info;
	INPUT_RECORD inputRecord;
	static ConsoleEvent* instance;
	ConsoleEvent() : inputRecord(), info() { ; }
	virtual ~ConsoleEvent() { ; }
public:
	static ConsoleEvent& getInstance();
	static void destroyInstance();
	const WORD& getType() const { return inputRecord.EventType; }
	const INPUT_RECORD& getInputRecord() const { return inputRecord; }
	const string& getInfo() const { return info; }
	void setType(const WORD& eventType) { inputRecord.EventType = eventType; }
	void setInfo(const string& i) { info = i; }
	void setInputRecord(const INPUT_RECORD& ir) { inputRecord = ir; }
};