#include <fstream>
#include <string.h>

#include "backupFolderStructure.h"

backupFolderStructure::backupFolderStructure(std::string _backupFolder)
{
    backupFolder = _backupFolder;
}

void backupFolderStructure::autoCreateBackupFolders(std::string domain)
{
    std::string strBackup = "sudo mkdir "+backupFolder+domain+"/;"
                 "sudo mkdir "+backupFolder+domain+"/backup/;";
                 
    system(strBackup.c_str());
}
