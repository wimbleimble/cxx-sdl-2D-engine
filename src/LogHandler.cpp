#include "LogHandler.h"
#include <iostream>

LogHandler::LogHandler()
	: log{ "log" }
{

	log.open("test.txt", std::ofstream::out | std::ofstream::trunc);
	std::cout.rdbuf(log.rdbuf());
}

LogHandler::~LogHandler()
{
	log.close();
}