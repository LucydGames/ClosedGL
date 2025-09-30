#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//namespace Cgl
//{
static std::ofstream logFile;
class Log
{
public:
	static Log& getInstance();
	~Log();
	static void printInfo(const std::string& message);
	static void printWarning(const std::string& message);
	static void printError(const std::string& message);
private:
	
	Log();
	static void LogMessage(const std::string& level, const std::string& message);;
	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;
};
	
	
//}