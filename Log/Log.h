#pragma once

#include "spdlog/spdlog.h"

//日志类
//优先级 error > warn > info > debug > trace
static class Log
{
public:
	enum Level { Error, Warn, Info, Debug, Trace };

	static void init();

	//设置文件日志等级
	static void setFileLogLevel(Level level);
	//设置命令行日志等级
	static void setConsoleLogLevel(Level level);

	template<typename FormatString, typename... Args>
	inline static void error(const FormatString& fmt, const Args&... args) {
		_fileLogger->error(fmt, args...);
		_consoleLogger->error(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	inline static void warn(const FormatString& fmt, const Args&... args) {
		_fileLogger->warn(fmt, args...);
		_consoleLogger->warn(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	inline static void info(const FormatString& fmt, const Args&... args) {
		_fileLogger->info(fmt, args...);
		_consoleLogger->info(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	inline static void debug(const FormatString& fmt, const Args&... args) {
		_fileLogger->debug(fmt, args...);
		_consoleLogger->debug(fmt, args...);
	}

	template<typename FormatString, typename... Args>
	inline static void trace(const FormatString& fmt, const Args&... args) {
		_fileLogger->trace(fmt, args...);
		_consoleLogger->trace(fmt, args...);
	}

private:
	static std::shared_ptr<spdlog::logger> _fileLogger;
	static std::shared_ptr<spdlog::logger> _consoleLogger;
};
