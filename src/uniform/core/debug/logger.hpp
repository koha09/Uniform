#include <string>
#include <vector>
#include <fstream>

#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger
{
private:

    Logger() = default;
    ~Logger();

    Logger(Logger&) = delete;
    Logger &operator=(Logger&) = delete;

public:

    std::ofstream &get_stream(const std::string &name);

    bool make_stream(const std::string &name, const std::string &file);
	bool delete_stream(const std::string &name);

    std::ostream &error();
	std::ostream &warning();
	std::ostream &information();

    std::string get_time();
	std::string get_date();

    static Logger &get_instance() {
        static Logger r_instance;
        return r_instance;
    }

private:

    std::vector<
		std::pair<std::string, std::ofstream>
	> _file_streams;

};

# if defined(_DEBUG_)

#  define LOGGER_CASE_ERROR(case) \
    Logger::get_instance().error() << case

#  define LOGGER_CASE_WARNING(case) \
    Logger::get_instance().warning() << case

#  define LOGGER_CASE_INFORMATION(case) \
    Logger::get_instance().information() << case

#  define LOGGER_GET_TIME() \
	Logger::get_instance().get_time()

#  define LOGGER_GET_DATE() \
	Logger::get_instance().get_date()

#  define LOGGER_CASE_STREAM(name, case) \
	Logger::get_instance().get_stream(name) << case

#  define LOGGER_MAKE_STREAM(name, file) \
	Logger::get_instance().make_stream(name, file)

#  define LOGGER_DELETE_STREAM(name) \
	Logger::get_instance().delete_stream(name)

# else

#  define LOGGER_CASE_ERROR(...)
#  define LOGGER_CASE_WARNING(...)
#  define LOGGER_CASE_INFORMATION(...)
#  define LOGGER_GET_TIME()
#  define LOGGER_GET_DATE()
#  define LOGGER_CASE_STREAM(...)
#  define LOGGER_MAKE_STREAM(...)
#  define LOGGER_DELETE_STREAM(...)

# endif

#endif