#include "stdafx.h"
#include "ScheduleManager.h"


ScheduleManager::ScheduleManager()
{
	activate = true;
	hostNumber = -1;
	enabledHost = 0;
	memory = -1;
	core = -1;
}


ScheduleManager::~ScheduleManager()
{
	delete[]hostList;
}

void ScheduleManager::Initialize()
{
	init();
	activate = true;
	hostList = new Host[hostNumber];
	for (int i = 0; i < hostNumber; i++)
	{
		hostList[i] = Host(core, memory);
	}
	hostList[0].EnableHost();
	enabledHost = 0;
}

void ScheduleManager::init()
{
	ifstream clusterfile;
	clusterfile.open("C:\\Users\\Asuka\\Desktop\\Code\\Scheduler\\Debug\\Cluster.txt");
	//clusterfile.open("Cluster.txt");
	if (clusterfile.is_open() == false)
	{
		cerr << "File not found." << endl;
		exit(EXIT_FAILURE);
	}
	clusterfile >> hostNumber >> memory >> core;
}

bool ScheduleManager::assignCheck(float coreRequested, float memoryRequested, float coreAvailable, float memoryAvailable)
{
	return coreRequested <= coreAvailable && memoryRequested <= memoryAvailable ? true : false;
}


void ScheduleManager::Run()
{
	while (activate)
	{
		cout << "Input Request: " << endl;
		Request inputRequest = GetRequest();
		if (inputRequest.IsValid() && inputRequest.GetName() != "EXIT")
		{
			if (AssignRequest(inputRequest))
			{
				cout << "Request Accepted" << endl;
			}
		}
		else if (inputRequest.GetName() == "EXIT")
		{
			Deactivate();
			cout << "System Shut Down." << endl;
		}
		else
		{
			cout << "Cannot assign request." << endl;
		}
		Display();
	}
}

void ScheduleManager::Deactivate()
{
	activate = false;
}

Request ScheduleManager::GetRequest()
{
	string requestName;
	float coreRequest;
	float memoryRequest;
	int timeRequest;
	int instanceRequest;
	cin >> requestName >> coreRequest >> memoryRequest >> timeRequest >> instanceRequest;
	return Request(requestName, coreRequest, memoryRequest, timeRequest, instanceRequest);
}

bool ScheduleManager::AssignRequest(Request r)
{
	bool RequestAssigned = false;
	for (int i = 0; i < hostNumber; i++)
	{
		hostList[i].Update();
	}
	for (int i = 0; i < r.GetInstance(); i++)
	{
		bool assigned = false;
		for (int j = 0; j < hostNumber && !assigned; j++)
		{
			if (hostList[j].IsEnabled())
			{
				if (assignCheck(r.GetCore(), r.GetMemory(), hostList[j].GetAvailableCore(), hostList[j].GetAvailableMemory()))
				{
					hostList[j].HandleRequest(r);
					assigned = true;
				}
				else
				{
					assigned = false;
					RequestAssigned = false;
				}
			}
		}
		if (!assigned && enabledHost < hostNumber)
		{
			bool enable = false;
			for (int i = 0; i < hostNumber; i++)
			{
				if (hostList[i].IsEnabled() == false && !enable)
				{
					enable = true;
					hostList[i].EnableHost();
					enabledHost++;
					hostList[i].HandleRequest(r);
					RequestAssigned = true;
				}
			}
		}
		if (enabledHost == hostNumber && !assigned)
		{
			RequestAssigned = false;
			cout << "Out of resources." << endl;
		}
	}
	return RequestAssigned;
}

void ScheduleManager::Display()
{
	cout << "HostNumber: " << hostNumber << endl;
	cout << "Memory: " << memory << endl;
	cout << "Core: " << core << endl;
	for (int i = 0; i < hostNumber; i++)
	{
		cout << "Host Info: " << endl;
		cout << "Host " << i;
		hostList[i].Display();
		cout << endl;
	}
}
