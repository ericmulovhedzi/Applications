#include <fstream>
#include <string.h>

#include "wwwHTMLPreset.h"

wwwHTMLPreset::wwwHTMLPreset(std::string _systemName, std::string _wwwFolder)
{
    systemName = _systemName;
    wwwFolder = _wwwFolder;
}

void wwwHTMLPreset::autoPresetHTML(std::string domain)
{
    std::string path = wwwFolder+domain+"/public_html/index.html";
    file.open(path.c_str());
    
    file << "<!-- \n"
    " "+domain+" HTML Code\n\n"
    " Copyright. 2014, "+systemName+"\n"
    " http://ovhserverbasement.co.za\n"
    " \n"
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
    " -->\n"
    "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n"
    "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">\n"
    "        <head>\n" 
    "                <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n"
    "                <title>OVH Server Basement Version 1.0</title>\n"
    "                <meta name=\"language\" content=\"en, sv\" />\n"
    "                <meta name=\"copyright\" content=\"&copy; 2014 - "+systemName+"\" />\n"
    "                <meta name=\"author\" content=\"OVH Studio, Spider Black Online, Commac Creations\" />\n"
    "                <link href=\"styles/styles.css\" rel=\"stylesheet\" type=\"text/css\" />\n"
    "                <script type=\"text/javascript\" src=\"js/js.js\"></script>\n"
    "        </head>\n"
    "        <body>\n"
    "                <center><font size=\"5\">Hello World..!</font></center><br /><br />\n"
    "                <center><font size=\"3\">HTML is now working.</font></center><br /><br />\n"
    "                <center><font size=\"2\" color=\"red\">"+systemName+"</font></center><br />\n"
    "        </body>\n"
    "</html>\n";
    
    file.close();
}
