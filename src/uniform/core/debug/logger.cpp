#include <uniform/core/debug/logger.hpp>
#include <uniform/core/runtime.hpp>

#include <termcolor/termcolor.hpp>
#include <algorithm>

#include <ctime>

Logger::~Logger() {
    std::cerr << termcolor::reset;
	std::cout << termcolor::reset;
}

std::ofstream &Logger::get_stream(const std::string &name) {
	auto result = std::find_if(_file_streams.begin(), _file_streams.end(), [&name](std::pair<std::string, std::ofstream> &stream) -> bool {
        return stream.first == name;
    });

    if (result == _file_streams.end()) {
        throw UF_EXCEPTION_NOT_FOUND;
    } return (*result).second;
}

bool Logger::make_stream(const std::string &name, const std::string &file) {
    if (std::find_if(_file_streams.begin(), _file_streams.end(), [&name](std::pair<std::string, std::ofstream> &stream) -> bool {
        return stream.first == name;
    }) != _file_streams.end()) {
        throw UF_EXCEPTION_ALREADY_EXISTS;
        return false;
    }

	_file_streams.push_back(
        std::pair<std::string, std::ofstream>(name, std::ofstream(file, std::ios::app | std::ios::in))
    ); return true;
}

std::ostream &Logger::error() {
	return std::cerr << termcolor::red;
}

std::ostream &Logger::warning() {
	return std::cout << termcolor::yellow;
}

std::ostream &Logger::information() {
	return std::cout << termcolor::cyan;
}

std::string Logger::get_time() {
	char string[9];
	const time_t now = time(NULL);
	std::strftime(string, sizeof(string), "%H:%M:%S", localtime(&now));
	return std::string(string);
}

std::string Logger::get_date() {
	char string[11];
	const time_t now = time(NULL);
	std::strftime(string, sizeof(string), "%d.%m.%Y", localtime(&now));
	return std::string(string);
}