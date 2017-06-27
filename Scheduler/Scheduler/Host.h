#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "LocalRequest.h"

using namespace std;

class Host
{
private:
	float core;
	float memory;
	bool enable;
	vector<LocalRequest> requestList;
	bool CoreCheck(Request req);
	bool MemoryCheck(Request req);
public:
	Host();
	Host(float corenumber, float memorysize);
	~Host();
	void EnableHost();
	bool IsEnabled();
	void Disable();
	void HandleRequest(Request req);
	float GetAvailableCore();
	float GetAvailableMemory();
	bool IdleCheck();
	void Update();
	void Display();
};

