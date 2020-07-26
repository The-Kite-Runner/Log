#include "Log.h"

int main()
{
	Log::init();
	Log::setConsoleLogLevel(Log::Level::Debug);
	Log::setFileLogLevel(Log::Level::Trace);

	Log::error("this is error");
	Log::warn("this is warn");
	Log::debug("this is debug");
	Log::info("this is info");
	Log::trace("this is trace");

	Log::info("make a combo of {} and {}", 1, "word");

	return 0;
}
