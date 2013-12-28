#ifndef LOG_H
#define LOG_H

//Use that macro for line logging.
//Example:
//Logger.log(Log::Prioritiy_INFO, "All right");
#define Logger Log::GetInstance()

#include <iostream>
#include <fstream>
#include <string>

class Log
{
public:
	enum Priorities
	{
		Prioritiy_INFO, 
		Prioritiy_DEBUG,
		Prioritiy_WARNING, 
		Prioritiy_ERROR, 
		Prioritiy_VERBOSE
	};

	static Log& GetInstance()
	{
		static Log mInstance;
		return mInstance;
	}

	static void log(Priorities priority, const std::string& message);
private:
	Log();
	Log(const Log& root);
	Log& operator=(const Log&);

	static bool begin;
	static std::string mPath;
};

#endif