#include<string>

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

class FileManager {
	private:
		const char* fileName;
		const char* errorMessage;

	public:
		FileManager (const char*, const char*);

		void read (std::string[]);
		void write (std::string[]);
};

#endif