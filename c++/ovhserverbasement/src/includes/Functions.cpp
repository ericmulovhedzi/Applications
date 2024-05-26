#include <ctime>
#include "Functions.h"

char* Functions::NOW()
{
    time_t now = time(0); // --- current date/time based on current system
    char* dt = ctime(&now); // --- convert now to string form
    
    return dt;
}

char* Functions::NOW_UTC()
{
    time_t now = time(0); // --- current date/time based on current system
    
    tm *gmtm = gmtime(&now); // --- convert now to tm struct for UTC
    char* dt = asctime(gmtm);
    
    return dt;
}

std::string Functions::trimStr(std::string s)
{
    std::string t = "";
    unsigned int i;
    for (i=0; i < s.length(); i++){ if (!isspace(s[i]))t += s[i];}
    return t;
}