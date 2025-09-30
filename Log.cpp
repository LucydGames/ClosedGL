#include "Log.h"

Log& Log::getInstance()
{
	static Log instance; // Guaranteed to be initialized once
	return instance; // Having class return instance of itself is strange, but it's static and works for a singleton log class. Could consider creating a static Log member in another class instead (like Window).
}

Log::~Log()
{
	if (logFile.is_open()) {
		logFile.close();
	}
}

void Log::printInfo(const std::string& message)
{
	LogMessage("INFO:", message);
	std::cout << "Log: " << message << std::endl;
}

void Log::printWarning(const std::string& message)
{
	LogMessage("WARNING:", message);
	std::cerr << message << std::endl;
}

void Log::printError(const std::string& message)
{
	LogMessage("ERROR:", message);
	std::cerr << message << std::endl;
}

Log::Log()
{
	logFile.open("log.txt", std::ios::out | std::ios::app);
	if (!logFile.is_open())
	{
		std::cerr << "Failed to open log file: log.txt" << std::endl;
	}
}

void Log::LogMessage(const std::string& level, const std::string& message)
{
	if (logFile.is_open())
	{
		time_t now = time(NULL);
		tm localTime; // Declare your own tm struct
		char buf[20];
		if (localtime_s(&localTime, &now) == 0) { // Pass its address
			//std::cout << "Year: " << localTime.tm_year + 1900;
			std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &localTime);
		}
		else {
			std::cerr << "Error getting local time." << std::endl;
		}


		logFile << "[" << buf << "] [" << level << "] " << message << std::endl;
	}
	else
	{
		std::cerr << "Log file is not open. Message: " << message << std::endl;
	}
}
