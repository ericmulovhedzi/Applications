#include <fstream>
#include <string.h>

#include "wwwJSPreset.h"

wwwJSPreset::wwwJSPreset(std::string _systemName, std::string _wwwFolder)
{
    systemName = _systemName;
    wwwFolder = _wwwFolder;
}

void wwwJSPreset::autoPresetJS(std::string domain)
{
    std::string path = wwwFolder+domain+"/public_html/js/js.js";
    file.open(path.c_str());
    
    file << "/*!\n"
    " * "+systemName+"\n"
    " * http://ovhserverbasement.co.za\n"
    " *\n"
    " * Copyright (C) 2014, "+systemName+"\n"
    " * Released under the MIT, BSD, and GPL Licenses.\n"
    " *\n"
    " * Author: OVH Studio\n"
    " *\n"
    " * Tel: +27 11 071 1218\n"
    " * Email: info@ovhstudio.co.za\n"
    " * Website: www.ovhstudio.co.za\n"
    " *\n"
    " * Location: South Africa, Johannesburg\n"
    " *\n"
    " * Date: Wed May 2014\n"
    " */\n\n"
    "// ---Start writing your JavaScript code below here:\n\n";
    
    file.close();
}
