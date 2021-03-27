#ifndef LOGHANDLER_H
#define LOGHANDLER_H
#include <fstream>

class LogHandler //scoped handler that opens a log file and directs cout to it.
{
	std::ofstream log;
public:
	LogHandler();
	~LogHandler();
	
};

#endif