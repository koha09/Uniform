#pragma once

#include <vector>
#include <string>

#include <fstream>

#include <chrono>
using namespace std::chrono;

class Logger 
{
private:

    Logger();
	~Logger();

    Logger(const Logger&);  
    Logger &operator=(Logger&);

public:

    std::ofstream *get_stream(const std::string &name);

    bool make_stream(const std::string &name, const std::string &file);
	bool delete_stream(const std::string &name);

	microseconds get_timer(const std::string &name);
	
	bool make_timer(const std::string &name);
	bool delete_timer(const std::string &name);

    std::string get_time();
	std::string get_date();

    std::ostream &error();
	std::ostream &warning();
	std::ostream &information();
	
    static Logger &GetInstance() {
        static Logger r_instance;
        return r_instance;
    }

private:

    std::vector<
		std::pair<std::string, std::ofstream>
	> _file_streams;

	std::vector<
		std::pair<std::string, system_clock::time_point>
	> _timers;

};

#if defined(_DEBUG_)

#define LOG_MAKE_STREAM(...) \
	Logger::GetInstance().make_stream(__VA_ARGS__)

#define LOG_GET_STREAM(...) \
	*Logger::GetInstance().get_stream(__VA_ARGS__)

#define LOG_DELETE_STREAM(...) \
	Logger::GetInstance().delete_stream(__VA_ARGS__)

#define LOG_GET_TIME() \
	Logger::GetInstance().get_time()

#define LOG_GET_DATE() \
	Logger::GetInstance().get_date()

#define LOG_ERROR() \
	Logger::GetInstance().error()

#define LOG_WARNING() \
	Logger::GetInstance().warning()

#define LOG_INFORMATION() \
	Logger::GetInstance().information()

#define LOG_MAKE_TIMER(...) \
	Logger::GetInstance().make_timer(__VA_ARGS__)

#define LOG_GET_TIMER(...) \
	Logger::GetInstance().get_timer(__VA_ARGS__)

#define LOG_DELETE_TIMER(...) \
	Logger::GetInstance().delete_timer(__VA_ARGS__)

#else

#define LOG_MAKE_STREAM(...)
#define LOG_GET_STREAM(...)
#define LOG_DELETE_STREAM(...)

#define LOG_GET_TIME()
#define LOG_GET_DATE()

#define LOG_ERROR()
#define LOG_WARNING()
#define LOG_INFORMATION()
#define LOG_RESET()

#define LOG_MAKE_TIMER(...)
#define LOG_GET_TIMER(...)
#define LOG_DELETE_TIMER(...)

#endif