#include "Log.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

using namespace std;

std::shared_ptr<spdlog::logger> Log::_fileLogger;
std::shared_ptr<spdlog::logger> Log::_consoleLogger;

void Log::init()
{
	//�첽�ļ�logger��true��ʾɾ��֮ǰ��log
	Log::_fileLogger = spdlog::basic_logger_mt("_fileLogger", "log.txt", true);
	//������logger
	Log::_consoleLogger = spdlog::stdout_color_mt("_consoleLogger");

	//����log��ʽ
	spdlog::set_pattern("[%H:%M:%S] [%^%L%$] [thread %t] %v");

	//Ĭ����־����
	Log::_fileLogger->set_level(spdlog::level::trace);
	Log::_consoleLogger->set_level(spdlog::level::info);
}

void Log::setFileLogLevel(Level level)
{
	switch (level)
	{
	case Log::Level::Error:
		Log::_fileLogger->set_level(spdlog::level::err);
		break;
	case Log::Level::Warn:
		Log::_fileLogger->set_level(spdlog::level::warn);
		break;
	case Log::Level::Info:
		Log::_fileLogger->set_level(spdlog::level::info);
		break;
	case Log::Level::Debug:
		Log::_fileLogger->set_level(spdlog::level::debug);
		break;
	case Log::Level::Trace:
		Log::_fileLogger->set_level(spdlog::level::trace);
		break;
	default:
		throw;
	}
}

void Log::setConsoleLogLevel(Level level)
{
	switch (level)
	{
	case Log::Level::Error:
		Log::_consoleLogger->set_level(spdlog::level::err);
		break;
	case Log::Level::Warn:
		Log::_consoleLogger->set_level(spdlog::level::warn);
		break;
	case Log::Level::Info:
		Log::_consoleLogger->set_level(spdlog::level::info);
		break;
	case Log::Level::Debug:
		Log::_consoleLogger->set_level(spdlog::level::debug);
		break;
	case Log::Level::Trace:
		Log::_consoleLogger->set_level(spdlog::level::trace);
		break;
	default:
		throw;
	}
}
