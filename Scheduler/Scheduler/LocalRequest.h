#pragma once
#include "Request.h"
#include <ctime>
class LocalRequest : public Request
{
private:
	time_t startTime;
	time_t currTime;
	bool finished;
public:
	LocalRequest();
	LocalRequest(Request r);
	~LocalRequest();
	void SetStartTime();
	void SetCurrentTime();
	bool IsFinished();
};

