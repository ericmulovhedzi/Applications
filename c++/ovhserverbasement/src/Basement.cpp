#include <iostream>
#include <map>
#include <string.h>

#include "includes/Confg.cpp"

#include "modules/VirtualHost/VirtualHost.cpp"
#include "modules/wwwFolderStructure/wwwFolderStructure.cpp"
#include "modules/wwwHTMLPreset/wwwHTMLPreset.cpp"
#include "modules/wwwCSSPreset/wwwCSSPreset.cpp"
#include "modules/wwwJSPreset/wwwJSPreset.cpp"
#include "modules/wwwPHPPreset/wwwPHPPreset.cpp"
#include "modules/backupFolderStructure/backupFolderStructure.cpp"

using namespace std;

map<string, string> _Confg;
map<int, string> indexConfg,indexValidCodeConfg,valueValidCodeConfg;
ofstream VirtualHostFile,HTMLFile,CSSFile,JSFile,PHPFile;
string basePath,wwwFolder,backupFolder,cronsFolder,virtualHostFolder,virtualHostFile,systemName,domain,ipAddress,email,path;

Confg* Confg_;

void Init()
{   
    systemName = "OVH Server Basement Version 2.0";
    
    Confg_ = new Confg(systemName,"/Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh/sb/confg/ovh.sb.confg"); // --- Do all initial setups
    
    basePath = _Functions->trimStr(Confg_->getVal("PATH"));
    ipAddress = Confg_->getNode("IP");
    email = Confg_->getNode("ADMIN[EMAIL]");

    if(basePath.compare("./")==0)basePath=""; // --- If Yes, this means we are on LIVE ubuntu server then no need for the base path
    
    wwwFolder = basePath +"/var/www/"; // --- This is for Ubuntu Server OS
    backupFolder = basePath+"/home/"; // --- This is for Ubuntu Server OS
    cronsFolder = basePath+"/var/spool/cron/crontabs/"; // --- This is for Ubuntu Server OS
    virtualHostFolder= basePath +"/etc/apache2/sites-available/"; // --- This is for Ubuntu Server OS
    virtualHostFile="default";
}

void configurationSetup()
{
    Confg_->PreviewConfg();
    Confg_->EditConfg();
}

void RunSetupWizard()
{
    //cout << "Enter your IP Addess: ";cin >> ipAddress;
    cout << "Enter your Domain Name: ";cin >> domain;
    
    VirtualHost* _VH = new VirtualHost(systemName,virtualHostFolder,wwwFolder,virtualHostFile); // 1. --- Update Virtual Hosts
    _VH->autoAppendVirtualHost(ipAddress,domain);
    
    cout << "--- [VirtualHost] Successfully Updated.."<<endl;
    
    wwwFolderStructure* _wFS = new wwwFolderStructure(wwwFolder); // 2. --- auto Create WWWFolders
    _wFS->autoCreateWWWFolders(domain);
    
    cout << "--- ['www' folder structure] Successfully created.."<<endl;
    
    wwwHTMLPreset* _wHP = new wwwHTMLPreset(systemName,wwwFolder); // 3. --- Preset HTML File and auto link its Stylesheet and JavaScript
    _wHP->autoPresetHTML(domain);
    
    cout << "--- [HTML Preset] Successfully created.."<<endl;
    
    wwwCSSPreset* _wCP = new wwwCSSPreset(systemName,wwwFolder); // 4. ------- Preset CSS File
    _wCP->autoPresetCSS(domain);
    
    cout << "--- [CSS Preset] Successfully created.."<<endl;
    
    wwwJSPreset* _wJP = new wwwJSPreset(systemName,wwwFolder); // 5. ------- Preset JavaScript File
    _wJP->autoPresetJS(domain);
    
    cout << "--- [JavaScript Preset] Successfully created.."<<endl;
    
    wwwPHPPreset* _wPP = new wwwPHPPreset(systemName,wwwFolder); // 6. ------- Preset JavaScript File
    _wPP->autoPresetPHP(domain);
    
    cout << "--- [PHP Preset] Successfully created.."<<endl;
    
    backupFolderStructure* _bFS = new backupFolderStructure(backupFolder); // 7. ------- Create a 'www' folder structure
    _bFS->autoCreateBackupFolders(domain);
    
    cout << "--- [backup folder structure] Successfully created.."<<endl;
    
    cout <<endl;
    cout << "--- Setup Complete!"<<endl;
    cout << "--- NB: You can now RESTART your Web Server i.e.(Apache)"<<endl;
    cout << "--- Thank you"<<endl<<endl;
}

void RunSetupAdvanced()
{
    if(Confg_->getNode("IP").empty())
    {
        cout << "Enter your IP Addess: ";cin >> ipAddress;
    }
    
    cout << "Enter your Domain Name: ";cin >> domain;
    cout <<endl;
    
    VirtualHost* _VH = new VirtualHost(systemName,virtualHostFolder,wwwFolder,virtualHostFile); // 1. --- Update Virtual Hosts
    _VH->autoAppendVirtualHost(ipAddress,domain);
    
    cout << "--- [VirtualHost] Successfully Updated.."<<endl;
    
    wwwFolderStructure* _wFS = new wwwFolderStructure(wwwFolder); // 2. --- auto Create WWWFolders
    _wFS->autoCreateWWWFolders(domain);
    
    cout << "--- ['www' folder structure] Successfully created.."<<endl;
    
    wwwHTMLPreset* _wHP = new wwwHTMLPreset(systemName,wwwFolder); // 3. --- Preset HTML File and auto link its Stylesheet and JavaScript
    _wHP->autoPresetHTML(domain);
    
    cout << "--- [HTML Preset] Successfully created.."<<endl;
    
    wwwCSSPreset* _wCP = new wwwCSSPreset(systemName,wwwFolder); // 4. ------- Preset CSS File
    _wCP->autoPresetCSS(domain);
    
    cout << "--- [CSS Preset] Successfully created.."<<endl;
    
    wwwJSPreset* _wJP = new wwwJSPreset(systemName,wwwFolder); // 5. ------- Preset JavaScript File
    _wJP->autoPresetJS(domain);
    
    cout << "--- [JavaScript Preset] Successfully created.."<<endl;
    
    wwwPHPPreset* _wPP = new wwwPHPPreset(systemName,wwwFolder); // 6. ------- Preset JavaScript File
    _wPP->autoPresetPHP(domain);
    
    cout << "--- [PHP Preset] Successfully created.."<<endl;
    
    backupFolderStructure* _bFS = new backupFolderStructure(backupFolder); // 7. ------- Create a 'www' folder structure
    _bFS->autoCreateBackupFolders(domain);
    
    cout << "--- [backup folder structure] Successfully created.."<<endl;
    
    cout <<endl;
    cout << "--- Setup Complete!"<<endl;
    cout << "--- NB: You can now RESTART your Web Server i.e.(Apache)"<<endl;
    cout << "--- Thank you"<<endl<<endl;
}

int mainMenu() // System main menu
{
    int optMenu;
    // --- Main Menu
    
    cout<<endl;
    cout<<"__________ OVH Server Basement 2.0 _________"<<endl;
    cout<<"|                                          |"<<endl;
    cout<<"|  1 : Run Setup - Wizard (Recommended)    |"<<endl;
    cout<<"|  2 : Run Setup - Auto (Advanced)         |"<<endl;
    cout<<"|  3 : Priveiw Current Configuration       |"<<endl;
    cout<<"|  4 : Configuration Settings              |"<<endl;
    cout<<"|  0 : Exit                                |"<<endl;
    cout<<"____________________________________________"<<endl;
    cout<<endl;
    cout << "Please, enter your option: ";cin >> optMenu;
    cout<<endl;
    
    return optMenu;
}

int main()
{
    Init(); // Init method to initialize system default settings i.e. system name and standadrd folders
    
    char none; // --- This is simply for wizard traversal purposes
    int optMenu;// --- Main Menu option
    int wrongCount = 0;// --- Main Menu option
    
    while(true)
    {
        if(wrongCount!=3)
        {
            optMenu =  mainMenu(); // Enter main menu
            
            if(optMenu==1)
            {
                RunSetupWizard();
                wrongCount=0;
            }
            else if(optMenu==2)
            {
                RunSetupAdvanced();
                wrongCount=0;
            }
            else if(optMenu==3)
            {
                Confg_->PreviewConfg();
            }
            else if(optMenu==4)
            {
                configurationSetup();Init();
                wrongCount=0;
            }
            else if(optMenu==0) // --- Menu exit
            {
                cout<<"Exiting, Thank you."<<endl<<endl;
                exit(0);
            }else
            {
                cout<<endl<<"Wrong option, please try again."<<endl<<endl;
                wrongCount++;
            }
        }else // --- Exit the system if Error count = 3
        {
            cout<<"You have entered WRONG option 3 times!"<<endl;
            cout<<"Exiting, Thank you."<<endl<<endl;
            exit(0);
        }
    }
    
    return 0;
}