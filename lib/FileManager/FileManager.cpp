#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include"../constants.hpp"
#include"FileManager.hpp"

using namespace std;

FileManager::FileManager (const char* _fileName, const char* _errorMessage) {
	this->fileName = _fileName;
	this->errorMessage = _errorMessage;
}

void FileManager::read (string lista[]) {
	ifstream archivo;
	
	archivo.open(this->fileName, ios::in);

	if (archivo.fail()) {
		throw this->errorMessage;
	}

	for (int i=0; !archivo.eof(); i++) {
		getline(archivo, lista[i]);
	}

	archivo.close();
}

void FileManager::write (string lista[]) {
	ofstream archivo;
	
	archivo.open(this->fileName, ios::out);

	if (archivo.fail()) {
		throw this->errorMessage;
	}

	for (int i=0; lista[i]!="\0"; i++) {
		archivo<<lista[i]<<endl;
	}

	archivo.close();
}
