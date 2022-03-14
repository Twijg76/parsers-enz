#include <cstring>
#include "Utilities.h"


/**
 * From Ben Voigt's answer to https://stackoverflow.com/questions/4654636/
 * @return if string is a representation of a number or not
 */
bool Util::isNumber(const std::string & line) {
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
