#include<string>

#ifndef VALIDATIONS_HPP
#define VALIDATIONS_HPP

bool tooMuchArgs (int, int, const char*);
bool insufficientArgs (int, int, const char*);
bool templateExist (std::string&, std::string&, bool, const char*);
bool nonCorrectArg (std::string&, const char*, int, const char*);

#endif