#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Host.h"
#include "Request.h"

using namespace std;

class ScheduleManager
{
private:
	bool activate;
	void init();
	int hostNumber;
	int enabledHost;
	float memory;
	float core;
	Host* hostList;
	bool assignCheck(float coreRequested, float memoryRequested, float coreAvailable, float memoryAvailable);
public:
	ScheduleManager();
	~ScheduleManager();
	void Run();
	Request GetRequest();
	bool AssignRequest(Request req);
	void Display();
	void Deactivate();
	void Initialize();
};

