#include <fstream>
#include <string.h>

#include "wwwCSSPreset.h"

wwwCSSPreset::wwwCSSPreset(std::string _systemName, std::string _wwwFolder)
{
    systemName = _systemName;
    wwwFolder = _wwwFolder;
}

void wwwCSSPreset::autoPresetCSS(std::string domain)
{
    std::string path = wwwFolder+domain+"/public_html/styles/styles.css";
    file.open(path.c_str());
    
    file << "/*\n"
    " "+domain+" CSS Script\n\n"
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
    "/* GLOBAL RESET SETTINGS */\n"	
    "*{margin:0;padding:0;outline:none;}\n"
    "a img{border:none;}\n"
    "html{/* Html code here*/}\n"
    "body{/* Body code here*/}\n"
    "p{/* Paragraph code here*/}\n"
    "h1,h2,h3,h4,h5{/* Headers code here*/}\n\n"
    "/* --- Start writing the rest of the code here */\n\n";
    
    file.close();
}
