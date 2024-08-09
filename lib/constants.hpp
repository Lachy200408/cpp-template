#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const char* const COMMANDS[] = { "create", "list", "add", "help" };
const char* const TEMPLATES[] = { "1" , "react-jsx" };
const char* const HELP = "Template is a program for creating workspaces for developers. Usage:\n\n   template [command...] [arguments...]\n\nCommands:\n\n   create:  Create a project in the specified directory, copying it from an existing template.\n\n   list:    List all of the existing templates.\n\n   add:     Create a new template based on the specified directory.\n\n   help:    Print the usage manual.\n\n";

//* Errors
const char* const NO_EXISTS_TEMPLATE_FILE = "It is not posible to open the file.";
const char* const NO_EXISTS_TEMPLATE = "The specified project template doesn't exist.";
const char* const ALREADY_EXISTS_TEMPLATE = "The specified project template already exists.";
const char* const TOO_MUCH_ARGS = "Too much arguments for the command.";
const char* const INSUF_ARGS = "Insufficient arguments for the command.";
const char* const INCORRECT_ARGS = "Incorrect arguments for the command.";

//* For MACOs
const char* const PATH_MAC = "/Applications/Utilities/template_bin/";
const char* const TEMPLATE_PATH_MAC = "/Applications/Utilities/template_bin/templates/";
const char* const TEMPLATE_LIST_FILE_PATH = "/Applications/Utilities/template_bin/template.list";
const char* const LS_COMMAND_MAC = "ls";
const char* const CP_COMMAND_MAC = "cp -rf";
const char* const MKDIR_COMMAND_MAC = "mkdir";

#endif