#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Logger
{
public:
	Logger( char* log_file );
	virtual ~Logger();
	int write( char* buff );
	int write(char c);
private:
	char* log_file;
	std::ofstream fd;
};