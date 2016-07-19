#include "log.hpp"


void Log::warn(std::string msg){
	std::cout << warnCol << msg << resetCol << "\n";
}
void Log::err(std::string msg){
	std::cout << errCol << msg << resetCol << "\n";
}
void Log::log(std::string msg){
	std::cout << logCol << msg << resetCol << "\n";
}
void Log::dbg(std::string msg){
	std::cout << dbgCol << msg << resetCol << "\n";
}
