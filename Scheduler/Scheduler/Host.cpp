#include "stdafx.h"
#include "Host.h"

Host::Host()
{
	core = -1;
	memory = -1;
	enable = false;
	requestList.clear();
}


Host::Host(float corenumber, float memorysize)
{
	core = corenumber;
	memory = memorysize;
	enable = false;
	requestList.clear();
}


Host::~Host()
{
}

void Host::EnableHost()
{
	enable = true;
}

bool Host::IsEnabled()
{
	return enable;
}

void Host::Disable()
{
	enable = false;
}

void Host::HandleRequest(Request req)
{
	LocalRequest lreq(req);
	requestList.push_back(lreq);
	core -= lreq.GetCore();
	memory -= lreq.GetMemory();
}

bool Host::IdleCheck()
{
	bool idle = true;
	for (size_t i = 0; i < requestList.size(); i++)
	{
		if (!requestList[i].IsFinished())
		{
			idle = false;
		}
	}
	return idle;
}

void Host::Update()
{
	time_t currentTime = time(NULL);
	for (size_t i = 0; i < requestList.size(); i++)
	{
		requestList[i].SetCurrentTime();
		if (requestList[i].IsFinished())
		{
			core += requestList[i].GetCore();
			memory += requestList[i].GetMemory();
		}
	}
	if (IdleCheck())
	{
		Disable();
	}
}


float Host::GetAvailableCore()
{
	return core;
}

float Host::GetAvailableMemory()
{
	return memory;
}

void Host::Display()
{
	cout << endl << "Core: " << core << " " << "Memory: " << memory;
	if (enable)
	{
		cout << " ENABLED" << endl;
	}
	else
	{
		cout << " DISABLED" << endl;
	}
	for (size_t i = 0; i < requestList.size(); i++)
	{
		if (requestList[i].IsFinished())
		{
			cout << "Finished: " << requestList[i].GetName() << endl;
		}
		else
		{
			cout << "Running: " << requestList[i].GetName() << endl;
		}
	}
}