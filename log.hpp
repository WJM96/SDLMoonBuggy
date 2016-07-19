#ifndef LOG
#define LOG
#include <iostream>

//provides simple output functions
namespace Log{
	const std::string errCol = "\e[4;37;41mERROR: ";
	const std::string warnCol = "\e[4;30;43mWARNING: ";
	const std::string logCol = "\e[36;40m";
	const std::string dbgCol = "\e[37;40mDBG: ";
	const std::string resetCol = "\e[0m";
	
	void warn(std::string msg);
	void err(std::string msg);
	void log(std::string msg);
	void dbg(std::string msg);
};
#endif
