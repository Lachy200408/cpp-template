#include<iostream>
#include<stdlib.h>
#include<string>
#include"create.hpp"

using namespace std;

void createTemplate (int argc, const char* argv[], const char* command, const char* path) {
	string destination = ( argc == 5 )? argv[4] : "./";
	string wholeCommand = string(command) + " " + string(path) + "templates/" + string(argv[2]) + " " + destination;
	system(wholeCommand.c_str());
}