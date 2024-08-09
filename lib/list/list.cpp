#include<iostream>
#include<stdlib.h>
#include<string>
#include<dirent.h>
#include"list.hpp"

using namespace std;

void printList (const char* path) {
	DIR *directory;
	dirent *element;
	string name;

	directory = opendir(path);

	while (true) {
		element = readdir(directory);
		
		if (element) {
			name = element->d_name;

			if (name!="." && name!=".." && name!=".DS_Store") {
				cout<<name<<endl;
			}
		}
		else break;
	}

	closedir(directory);
}

void listTemplates (const char* path, string array[]) {
	DIR *directory;
	dirent *element;
	string name;

	directory = opendir(path);

	for (int i=0; true;) {
		element = readdir(directory);
		
		if (element) {
			name = element->d_name;

			if (name!="." && name!=".." && name!=".DS_Store") {
				array[i++] = name;
			}
		}
		else break;
	}

	closedir(directory);
}