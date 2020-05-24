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

#define UF_MAKE_STREAM(...) \
	Logger::GetInstance().make_stream(__VA_ARGS__)

#define UF_GET_STREAM(...) \
	*Logger::GetInstance().get_stream(__VA_ARGS__)

#define UF_DELETE_STREAM(...) \
	Logger::GetInstance().delete_stream(__VA_ARGS__)

#define UF_GET_TIME() \
	Logger::GetInstance().get_time()

#define UF_GET_DATE() \
	Logger::GetInstance().get_date()

#define UF_ERROR() \
	Logger::GetInstance().error()

#define UF_WARNING() \
	Logger::GetInstance().warning()

#define UF_INFORMATION() \
	Logger::GetInstance().information()

#define UF_MAKE_TIMER(...) \
	Logger::GetInstance().make_timer(__VA_ARGS__)

#define UF_GET_TIMER(...) \
	Logger::GetInstance().get_timer(__VA_ARGS__)

#define UF_DELETE_TIMER(...) \
	Logger::GetInstance().delete_timer(__VA_ARGS__)

#else

#define UF_MAKE_STREAM(...)
#define UF_GET_STREAM(...)
#define UF_DELETE_STREAM(...)

#define UF_GET_TIME()
#define UF_GET_DATE()

#define UF_ERROR()
#define UF_WARNING()
#define UF_INFORMATION()
#define UF_RESET()

#define UF_MAKE_TIMER(...)
#define UF_GET_TIMER(...)
#define UF_DELETE_TIMER(...)

#endif