#include "Log.h"

Log::Log()
{		
}

bool Log::begin = true;

string Log::mPath = "log.html";

void Log::log(Priorities priority, const string& message)
{
	ofstream mOutStream;
	if(begin)
	{
		mOutStream.open(mPath.c_str(), fstream::out);
		begin = false;
	} 
	else 
	{
		mOutStream.open(mPath.c_str(), fstream::app);
	}

	switch(priority)
	{
		case Prioritiy_INFO:	
		mOutStream << "<font color=\"#344d61\">msg: " << message << "</font><br>";
		break;

		case Prioritiy_DEBUG:
		mOutStream << "<font color=\"#518554\">msg: " << message << "</font><br>";
		break;

		case Prioritiy_WARNING:
		mOutStream << "<font color=\"#ceaa52\">msg: " << message << "</font><br>";
		break;

		case Prioritiy_ERROR:
		mOutStream << "<font color=\"#db3716\">msg: " << message << "</font><br>";
		break;

		case Prioritiy_VERBOSE:
		mOutStream << "<font color=\"#4d4d4d\">msg: " << message << "</font><br>";
		break;

		default:
		break;
	}

	if(mOutStream.is_open()) 
	{
		mOutStream.flush();
		mOutStream.close();
	}
}