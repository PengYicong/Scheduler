#pragma once
#include <iostream>
#include <string>

using namespace std;
class Request
{
private:
	int instance;
protected:
	string requestName;
	float coreRequest;
	float memoryRequest;
	int timeRequest;
public:
	Request();
	Request(string name, float core, float memory, int time, int inst);
	~Request();
	string GetName();
	float GetCore();
	float GetMemory();
	int GetTime();
	int GetInstance();
	bool IsValid();
	int GetInstanceNumber();
	void Display();
};

