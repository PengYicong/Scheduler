#include "stdafx.h"
#include "Request.h"

Request::Request()
{
	requestName = "";
	coreRequest = 0;
	memoryRequest = 0;
	timeRequest = 0;
	instance = 0;
}

Request::Request(string name, float core, float memory, int time, int inst)
{
	requestName = name;
	coreRequest = core;
	memoryRequest = memory;
	timeRequest = time;
	instance = inst;
	
	//SetName(name);
	//SetCore(core);
	//SetMemory(memory);
	//SetTime(time);
	//SetInstance(inst);
}


Request::~Request()
{
}

string Request::GetName()
{
	return requestName;
}

float Request::GetCore()
{
	return coreRequest;
}

float Request::GetMemory()
{
	return memoryRequest;
}

int Request::GetTime()
{
	return timeRequest;
}

int Request::GetInstance()
{
	return instance;
}

bool Request::IsValid()
{
	return (requestName != "" && coreRequest > 0 && memoryRequest > 0 && timeRequest > 0 && instance > 0) ? true : false;
}

int Request::GetInstanceNumber()
{
	return instance;
}

void Request::Display()
{
	cout << "Request Name: " << requestName << endl;
	cout << "Core Request: " << coreRequest << endl;
	cout << "Memory Request: " << memoryRequest << endl;
	cout << "Time Request: " << timeRequest << endl;
	cout << "Instance Number: " << instance << endl;
}