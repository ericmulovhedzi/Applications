#include <fstream>
#include <string.h>

#include "wwwFolderStructure.h"

wwwFolderStructure::wwwFolderStructure(std::string _wwwFolder)
{
    wwwFolder = _wwwFolder;
}

void wwwFolderStructure::autoCreateWWWFolders(std::string domain)
{
    std::string strWWW = "sudo mkdir "+wwwFolder+domain+"/;"
                 "sudo mkdir "+wwwFolder+domain+"/public_html/;"
                 "sudo mkdir "+wwwFolder+domain+"/public_html/images/;"
                 "sudo mkdir "+wwwFolder+domain+"/public_html/styles/;"
                 "sudo mkdir "+wwwFolder+domain+"/public_html/js/;";
                 
    system(strWWW.c_str());
}
