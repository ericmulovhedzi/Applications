#include <fstream>
#include <string.h>

#include "wwwPHPPreset.h"

wwwPHPPreset::wwwPHPPreset(std::string _systemName, std::string _wwwFolder)
{
    systemName = _systemName;
    wwwFolder = _wwwFolder;
}

void wwwPHPPreset::autoPresetPHP(std::string domain)
{
    std::string path = wwwFolder+domain+"/public_html/index.php";
    file.open(path.c_str());
    
    file << "<?php\n"
    "/*\n"
    " "+domain+" PHP Script\n"
    " \n"
    " "+systemName+"\n"
    " http://ovhserverbasement.co.za\n"
    " \n"
    " Copyright (C) 2014, "+systemName+"\n"
    " Released under the MIT, BSD, and GPL Licenses.\n"
    " \n"
    " Author: OVH Studio\n"
    " \n"
    " Tel: +27 11 071 1218\n"
    " Email: info@ovhstudio.co.za\n"
    " Website: www.ovhstudio.co.za\n"
    " \n"
    " Location: South Africa, Johannesburg\n"
    " \n"
    " Date: Wed May 2014\n"
    "*/\n\n"
    "echo \"<font size='5'>Hello World..!</font><br /><br />\";\n"
    "echo \"<font size='3'>PHP Works..!</font><br /><br />\";\n"
    "echo \"<font size='2' color='red'>"+systemName+"</font><br />\";\n"
    "?>\n";
    
    file.close();
}
