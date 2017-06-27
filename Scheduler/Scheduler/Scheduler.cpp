// Scheduler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "ScheduleManager.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ScheduleManager manager;

	manager.Initialize();
	manager.Display();
	manager.Run();
	return 0;
}

