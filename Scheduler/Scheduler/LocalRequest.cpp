#include "stdafx.h"
#include "LocalRequest.h"


LocalRequest::LocalRequest()
{
	Request();
	finished = false;
	startTime = currTime = time(NULL);
}

LocalRequest::LocalRequest(Request r)
{
	requestName = r.GetName();
	coreRequest = r.GetCore();
	memoryRequest = r.GetMemory();
	timeRequest = r.GetTime();
	startTime = time(NULL);
}

LocalRequest::~LocalRequest()
{
}

void LocalRequest::SetStartTime()
{
	startTime = time(NULL);
}

void LocalRequest::SetCurrentTime()
{
	currTime = time(NULL);
}

bool LocalRequest::IsFinished()
{
	finished = currTime - startTime >= timeRequest ? true : false;
	return finished;
}
