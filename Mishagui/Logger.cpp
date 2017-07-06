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

int Logger::write( int c ) {

	fd << (char)c;
	fd.flush();
	return 0;
}