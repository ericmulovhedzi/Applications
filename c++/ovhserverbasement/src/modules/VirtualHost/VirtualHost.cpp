#include <fstream>
#include <string.h>

//#include "/Users/ericmulovhedzi/research/c++/ovhserverbasement/includes/Confg.cpp"

#include "VirtualHost.h"

VirtualHost::VirtualHost(std::string _systemName, std::string _virtualHostFolder, std::string _wwwFolder, std::string _virtualHostFile)
{
    systemName = _systemName;
    virtualHostFolder = _virtualHostFolder;
    wwwFolder = _wwwFolder;
    virtualHostFile = _virtualHostFile;
}
  
void VirtualHost::autoAppendVirtualHost(std::string ipAddress,std::string domain)
{
    //Confg* Confg_ = new Confg();
    
    string adminEmail = "webmaster@"+domain;
    
    //if(basePath.compare("")==0) = Confg_->getNode("ADMIN[EMAIL]") string adminEmail = Confg_->getNode("ADMIN[EMAIL]");
    
    std::string path = virtualHostFolder+virtualHostFile;
    VirtualHostFile.open(path.c_str(),std::ios::app); //  --- Open the file for writing, (os::app) means is for appending
    
    VirtualHostFile << "\n"
    "# ------ "+domain+" Settings - "+systemName+" \n\n"
    "<VirtualHost "+ipAddress+":80>\n"
    "        ServerName "+domain+"\n"
    "        ServerAlias www."+domain+"\n"
    "        ServerAdmin "+adminEmail+"\n"
    "        DocumentRoot "+wwwFolder+domain+"/public_html/\n\n"
    "        <Directory "+wwwFolder+domain+"/public_html/>\n"
    "                Options Indexes FollowSymLinks MultiViews +Includes\n"
    "                AllowOverride None\n"
    "                Order allow,deny\n"
    "                Allow from all\n"
    "        </Directory>\n"
    "</VirtualHost>\n";
    
    VirtualHostFile.close();
}
