#include<iostream>
#include<stdlib.h>
#include<string>
#include"add.hpp"

using namespace std;

void addTemplate (int argc, const char* argv[], const char* mkdir_command, const char* cp_command, const char* path) {
	string destination = string(path) + "templates/" + argv[2];
	string currentPath = ( argc==5 )? argv[4] : "./";
	string firstCommand = string(mkdir_command) + " " + destination;
	string wholeCommand = "sudo" + firstCommand + " && " + (cp_command) + " " + currentPath + " " + destination;
	system(wholeCommand.c_str());
}