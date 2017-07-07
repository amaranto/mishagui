#include "Logger.h"


Logger::Logger( char* log_file ) {
	fd.open(log_file, std::ios::app);
}

Logger::~Logger() {
	if ( fd.is_open() ) fd.close();
}

int Logger::write(char* buff) {
	
	fd << buff ;
	fd.flush();
	return 0;
}

int Logger::write( char c ) {

	fd << c;
	fd.flush();
	return 0;
}