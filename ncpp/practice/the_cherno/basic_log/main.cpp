#include <iostream>

class Log {
	public:
		enum Level {
			levelError = 0, levelWarning, levelInfo
		};

	private:
		Level m_LogLevel = levelInfo;  // default to info

	public:
		void setLevel(Level level) {
			m_LogLevel = level;
		}

		void error(const char* msg) {
			if (m_LogLevel >= levelError) {
				std::cout << "[Error]: " << msg << std::endl;
			}
		}

		void warn(const char* msg) {
			if (m_LogLevel >= levelWarning) {
				std::cout << "[Warning]: " << msg << std::endl;
			}
		}

		void info(const char* msg) {
			if (m_LogLevel >= levelInfo) {
				std::cout << "[Info]: " << msg << std::endl;
			}
		}
};

int main(int argc, char **argv) {
	Log log;
	log.setLevel(Log::levelWarning);  // as enum Level isn't really a namespace
	log.warn("Hello !");
	log.error("Hello !");
	log.info("Hello !");
	return 0;
}
