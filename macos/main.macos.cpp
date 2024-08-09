#include<iostream>
#include<stdlib.h>
#include<string>
#include"./main.macos.hpp"
#include"../lib/common_includes.hpp"

using namespace std;

int macos::main (int argc, char const *argv[]) {


	//*---------------------------------------------------------


	/*
	* Command <help>, usage:
	*		$ template
	* 	$ template help
	*/
	if (argc == 1 || !strcmp(argv[1], "help")) {
		if (tooMuchArgs(argc, 2, TOO_MUCH_ARGS)) return 1;

		printHelp(HELP);
		return 0;
	}


	//*---------------------------------------------------------


	/*
	* Command <list>, usage:
	* 	$ template list
	*/
	if (!strcmp(argv[1], "list")) {
		if (tooMuchArgs(argc, 2, TOO_MUCH_ARGS)) return 1;

		try {
			printList(TEMPLATE_PATH_MAC);
		}
		catch (exception& err) {
			cout<<err.what()<<endl;
			return 1;
		}
		return 0;
	}


	//*---------------------------------------------------------


	/*
	* Below this comment, the program uses the FileManager class
	* for reanding and writing in an external file that stores the
	* list of available templates.
	*/

	FileManager templateListFile(TEMPLATE_LIST_FILE_PATH, NO_EXISTS_TEMPLATE_FILE);
	string templateList[100];

	try {
		templateListFile.read(templateList);
	}
	catch (const char* err) {
		if (!strcmp(err, NO_EXISTS_TEMPLATE_FILE)) {
			listTemplates(TEMPLATE_PATH_MAC, templateList);
			templateListFile.write(templateList);
		}
	}
	catch (exception& err) {
		cout<<err.what()<<endl;
		return 1;
	}


	//*---------------------------------------------------------


	/*
	* Variables for avoid runtime errors when validating commands
	*/
	int templateCount = 0;
	string templateListString = "";
	string currentTemplate = "";
	string currentArg = "";
	string currentArgValue = "";

	for (int i=0; templateList[i]!="\0"; i++) {
		templateListString += (i == 0)? templateList[i] : ","+templateList[i];
	}

	currentTemplate = (argc >= 3)? argv[2] : "";
	currentArg = (argc >= 4)? argv[3] : "";
	currentArgValue = (argc >= 5)? argv[4] : "";

	int i=1;
	while (templateList[i-1]!="\0") i++;
	
	templateCount = i-1;


	//*---------------------------------------------------------


	/*
	* Command <create>, usage:
	*		$ template create [template_name]
	* 	$ template create [template_name] -d [directory]
	*/
	if (argc >= 2 && !strcmp(argv[1], "create")) {
		if (insufficientArgs(argc, 3, INSUF_ARGS)) return 1;
		if (tooMuchArgs(argc, 5, TOO_MUCH_ARGS)) return 1;
		if (!templateExist(currentTemplate, templateListString, false, NO_EXISTS_TEMPLATE)) return 1;
		if (nonCorrectArg(currentArg, "-d", argc, INCORRECT_ARGS)) return 1;

		createTemplate(argc, argv, CP_COMMAND_MAC, PATH_MAC);
		return 0;
	}


	//*---------------------------------------------------------


	/*
	* Command <add>, usage:
	*		$ template add [template_name]
	* 	$ template add [template_name] -d [directory]
	*/
	if (argc >= 2 && !strcmp(argv[1], "add")) {
		if (insufficientArgs(argc, 3, INSUF_ARGS)) return 1;
		if (tooMuchArgs(argc, 5, TOO_MUCH_ARGS)) return 1;
		if (templateExist(currentTemplate, templateListString, true, ALREADY_EXISTS_TEMPLATE)) return 1;
		if (nonCorrectArg(currentArg, "-d", argc, INCORRECT_ARGS)) return 1;
		
		addTemplate(argc, argv, MKDIR_COMMAND_MAC, CP_COMMAND_MAC, PATH_MAC);
		
		//* Add new template name to the list file
		templateList[templateCount] = currentTemplate;
		templateListFile.write(templateList);
		return 0;
	}


	//*---------------------------------------------------------


	return 0;
}