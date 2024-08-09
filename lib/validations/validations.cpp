#include<iostream>
#include<stdlib.h>
#include<string>
#include"validations.hpp"

using namespace std;

bool tooMuchArgs (int current, int maximum, const char* message) {
	if (current > maximum) {
		cout<<message<<endl;
		return true;
	}
	return false;
}

bool insufficientArgs (int current, int minimum, const char* message) {
	if (current < minimum) {
		cout<<message<<endl;
		return true;
	}
	return false;
}

bool templateExist (string &currentTemplate, string &templateList, bool flag, const char* message) {
	int totalLen = templateList.length();
	bool exist = false;
	string aux = "";

	for (int i=0; i<totalLen; i++) {
		aux = (templateList.at(i) != ',')? aux + templateList.at(i) : aux;

		if (i == totalLen-1 || templateList.at(i+1) == ',') {
			exist = (currentTemplate == aux);
			
			if (exist) break;
			
			aux = "";
		}
	}

	if (exist == flag) cout<<message<<endl;
	return exist;
}

bool nonCorrectArg (string &current, const char* expected, int argc, const char* message) {
	if (argc>3 && strcmp(current.c_str(), expected) || argc==4) {
		cout<<message<<endl;
		return true;
	}
	return false;
}