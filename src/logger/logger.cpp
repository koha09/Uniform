#include <logger/logger.hpp>

#include <termcolor/termcolor.hpp>

#include <algorithm>
#include <ctime>

Logger::Logger() { }

Logger::~Logger() {
	std::cerr << termcolor::reset;
	std::cout << termcolor::reset;
}

std::ofstream *Logger::get_stream(const std::string &name) {
	for (auto &elem : _file_streams) {
		if (elem.first == name) {
			return &elem.second;
		}
	}
	return nullptr;
}

bool Logger::make_stream(const std::string &name, const std::string &file) {
	if (!_file_streams.empty()) {
		if (get_stream(name) != 0 || name.empty())
			return false;
	}

	_file_streams.push_back(
		std::pair<std::string, std::ofstream>(
			name,
			std::ofstream(file, std::ios::app | std::ios::in)
		)
	); return true;
}

bool Logger::delete_stream(const std::string &name) {
	auto iterator = std::find_if(_file_streams.begin(), _file_streams.end(),
		[&name](const std::pair<std::string, std::ofstream> &element) -> bool {
			return element.first == name;
		}
	);

	if ((*iterator).first.empty())
		return false;

	_file_streams.erase(iterator);
	return true;
}

microseconds Logger::get_timer(const std::string &name) {
	for (auto &elem : _timers) {
		if (elem.first == name) {
			return duration_cast<microseconds>(std::chrono::system_clock::now() - elem.second);
		}
	}
	return microseconds(0);
}

bool Logger::make_timer(const std::string &name) {
	if (!_timers.empty()) {
		if (get_timer(name).count() == 0 || name.empty())
			return false;
	}

	_timers.push_back(std::pair<std::string, system_clock::time_point>(
		name,
		std::chrono::system_clock::now()
	));

	return true;
}

bool Logger::delete_timer(const std::string &name) {
	auto iterator = std::find_if(_timers.begin(), _timers.end(),
		[&name](const std::pair<std::string, system_clock::time_point> &element) -> bool {
			return element.first == name;
		}
	);

	if ((*iterator).first.empty())
		return false;

	_timers.erase(iterator);
	return true;
}

std::string Logger::get_time() {
	char string[9];
	time_t now = time(NULL);
	std::strftime(string, sizeof(string), "%H:%M:%S", localtime(&now));
	return std::string(string);
}

std::string Logger::get_date() {
	char string[11];
	time_t now = time(NULL);
	std::strftime(string, sizeof(string), "%d.%m.%Y", localtime(&now));
	return std::string(string);
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