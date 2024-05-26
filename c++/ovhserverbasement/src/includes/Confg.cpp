#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string.h>

#include "Confg.h"
#include "Functions.cpp"

using namespace std;

Functions* _Functions;

Confg::Confg()
{
    if(access("/Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh/sb/confg", 0) == 0) // --- Check if confg directory exists
    {
        ConfgReader(confgfile);
    }
}

Confg::Confg(std::string _systemName, const char* _confgfile)
{
    systemName = _systemName;
    confgfile = _confgfile;
    
    if(access("/Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh/sb/confg", 0) == 0) // --- Check if confg directory exists
    {
        // --- Nothing to do for now
    }
    else // --- If not, then create it
    {
        std::string strBackup = "sudo mkdir /Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh;"
                                "sudo mkdir /Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh/sb;"
                                "sudo mkdir /Users/ericmulovhedzi/research/c++/ovhserverbasement/serverroot/etc/ovh/sb/confg;";
                                
        system(strBackup.c_str());
    }
    
    std::ifstream input(_confgfile);
    
    if(input.is_open()) // --- File already exists
    {
        ConfgReader(_confgfile);
    }
    else // Else, create & preset the file with default values
    {
        ConfgReset(_confgfile);
        ConfgReader(_confgfile);
    }
    
    input.close();
}

void Confg::PreviewConfg() // --- 1. Preview .confg file
{
    std::map <int,std::string>::iterator itPre;
    
    cout<<"____________ 'ovh.sb.confg' PREVIEW (OVH Server Basement 2.0) ___________"<<endl;
    cout<<"|                                                                       |"<<endl;
    for (itPre = valueValidCodeConfg.begin(); itPre != valueValidCodeConfg.end(); ++itPre)
    {
        cout << "   " << indexValidCodeConfg[itPre->first] << " : " << itPre->second << endl;
    
    }
    cout<<"|                                                                       |"<<endl;
    cout<<"_________________________________________________________________________"<<endl;
    cout <<endl;
}

void Confg::EditConfg() // --- Edit .confg file
{
    char opt; // --- Editing menu - option input
    string optValue; // --- Editing menu - input value
    
    std::map <int,std::string>::iterator it;
    
    cout<<"____________ 'ovh.sb.confg' EDIT (OVH Server Basement 2.0) ______________"<<endl;
    cout<<"|                                                                       |"<<endl;
    cout<<"|  y : Yes                                                              |"<<endl;
    cout<<"|  n : No                                                               |"<<endl;
    cout<<"|  v : Preview Edited Changes                                           |"<<endl;
    cout<<"|  s : Save                                                             |"<<endl;
    cout<<"|  x : Exit                                                             |"<<endl;
    cout<<"|                                                                       |"<<endl;
    for (it = valueValidCodeConfg.begin(); it != valueValidCodeConfg.end(); ++it)
    {
        startOfLoop:
            opt=' ';
            cout << "   " << "Would like to edit \"" <<indexValidCodeConfg[it->first] << "\"? (y/n) : ";cin >> opt;
            
            if(opt=='y' || opt=='Y')
            {
                //cout<<endl;
                cout << "   " << "CURRENT - " << indexValidCodeConfg[it->first] << " : " << it->second << endl;
                cout << "   " << "Enter your NEW \"" <<indexValidCodeConfg[it->first] << "\": ";cin >> optValue;
                cout << "   " << "Thank you..! " << endl;
                cout<<endl;
                
                __Confg[indexValidCodeConfg[it->first]] = optValue;
                optValue="";
                
            }
            else if(opt=='v' || opt=='V')
            {
                PreviewEditedChanges(0);
                goto startOfLoop;
            }if(opt=='s' || opt=='S')
            {
                SaveChanges(); // --- Save edited changes
                break;
            }if(opt=='x' || opt=='X')
            { 
                PreviewEditedChanges(1); // --- Preview & Save before exit
                break;
            }
            else
            {
                continue;
            }
    }
    cout<<"|                                                                       |"<<endl;
    cout<<"_________________________________________________________________________"<<endl;
    cout <<endl;
}

void Confg::PreviewEditedChanges(int mustApply) // --- Preview edited changes
{
    if(__Confg.size()>=1)
    {
        std::map <std::string,std::string>::iterator itNew;
        int k=1;
        
        cout<<"____________ *NEW* Changes (OVH Server Basement 2.0) ____________________"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|  These are the changes you have made:                                 |"<<endl;
        cout<<"|                                                                       |"<<endl;
        for (itNew = __Confg.begin(); itNew != __Confg.end(); ++itNew)
        {
            cout << "   " << k << ". " << itNew->first << " : " << itNew->second << endl;
            k++;
        }
        
        if(mustApply==1)ApplyEditedChanges(); // --- Apply edited changes
        
        cout <<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"_________________________________________________________________________"<<endl;
        cout <<endl;
    }
    else
    {
        cout<<endl;
        cout << "   " <<  "No changes made yet..!";
        cout<<endl<<endl;
    }
}

void Confg::ApplyEditedChanges() // --- Apply edited changes to .confg file
{
    char optApply; // --- Editing menu - option input
    
    cout<<endl;
    cout << "   " << "SAVE CHANGES before exiting, Please confirm? (y/n) : ";cin >> optApply;
    cout<<endl;
    
    if(optApply=='y' || optApply=='Y')
    {
        std::ofstream output;
        output.open(confgfile);
        
        std::map <int,std::string>::iterator itEdit;
        
        for(itEdit = indexConfg.begin(); itEdit != indexConfg.end(); ++itEdit)
        {
            string newValue = itEdit->second;
            
            if(indexValidCodeConfg.find(itEdit->first) != indexValidCodeConfg.end())
            {
                if(__Confg.find(indexValidCodeConfg[itEdit->first]) != __Confg.end())
                {
                    newValue = indexValidCodeConfg[itEdit->first]+"="+__Confg[indexValidCodeConfg[itEdit->first]];
                    cout << "   " << indexValidCodeConfg[itEdit->first] << " : " << __Confg[indexValidCodeConfg[itEdit->first]]  << endl;
                }
            }
            
            output << newValue << "\n";
        }
        
        output.close();
        
        ConfgReader(confgfile);
        
        cout<<endl;
        cout << "   " << "Successfully applied (" << __Confg.size() << ") changes to 'ovh.sb.confg'..!";
    }
    else
    {
        cout << "   " << "No changes applied..!";
    }
    
    cout <<endl;
}

void Confg::SaveChanges() // --- Apply edited changes to .confg file
{
    char optApply; // --- Editing menu - option input
    
    std::ofstream output;
    output.open(confgfile);
    
    std::map <int,std::string>::iterator itEdit;
    
    for (itEdit = indexConfg.begin(); itEdit != indexConfg.end(); ++itEdit)
    {
        string newValue = itEdit->second;
        
        if(indexValidCodeConfg.find(itEdit->first) != indexValidCodeConfg.end())
        {
            if(__Confg.find(indexValidCodeConfg[itEdit->first]) != __Confg.end())
            {
                newValue = indexValidCodeConfg[itEdit->first]+"="+__Confg[indexValidCodeConfg[itEdit->first]];
                cout << "   " << indexValidCodeConfg[itEdit->first] << " : " << __Confg[indexValidCodeConfg[itEdit->first]]  << endl;
            }
        }
        
        output << newValue << "\n";
    }
    
    output.close();
    
    ConfgReader(confgfile);
    
    cout<<endl;
    cout << "   " << "Successfully applied (" << __Confg.size() << ") changes to 'ovh.sb.confg'..!";
    cout <<endl;
}

std::string Confg::getVal(const char* val)
{
    return valueValidCodeConfg[findKey(indexValidCodeConfg,val)];
}

std::string Confg::getNode(const char* val)
{
    return indexConfg[findKey(indexValidCodeConfg,val)];
}

const int Confg::findKey(std::map<int, std::string> mapContainter, const char* val)
{
    std::map <int,std::string>::iterator it;
    for (it = mapContainter.begin(); it != mapContainter.end(); ++it )
    if (it->second == val) return it->first;
}

bool Confg::isInMapValInt(std::map<int, std::string> mapContainter,int val)
{
    if(mapContainter.find(val) != mapContainter.end()){return true;}else{return false;}
}

bool Confg::isInMapKeyStr(const char* val)
{
    if(__Confg.find(val) != __Confg.end()){return true;}else{return false;}
}

bool Confg::isInMapValStr(std::map<std::string, std::string> mapContainter,const char* val)
{
    if(mapContainter.find(val) != mapContainter.end()){return true;}else{return false;}
}

void Confg::ConfgReset(const char* _confgfile)
{
    cout<<endl<<"Welcome to "<<systemName<<endl;
    cout<<"NB: "<<systemName<<" is running for the 1st time in this server (Machine)"<<endl<<endl;
    cout<<"--- Creating configuration file 'ovh.sb.confg'"<<endl;
    
    std::ofstream output;
    output.open(_confgfile);
    
    output << "\n"
    "# "+systemName+" Configuration settings \n"
    "# http://ovhserverbasement.co.za\n"
    "\n"
    "# Copyright (C) 2014, "+systemName+"\n"
    "# Released under the MIT, BSD, and GPL Licenses.\n"
    "\n"
    "# Author: OVH Studio\n"
    "\n"
    "# Tel: +27 11 071 1218\n"
    "# Email: info@ovhstudio.co.za\n"
    "# Website: www.ovhstudio.co.za\n"
    "\n"
    " Location: South Africa, Johannesburg\n"
    "\n"
    "# Date (Local): "+_Functions->NOW()+"\n"
    "# Date (UTC): "+_Functions->NOW_UTC()+"\n"
    "\n"
    "# Base Path (Defalut is the begining of your Ubuntu Server (\"./\") OR\n"
    "# (\"/home/root/testing\") for your Ubuntu server root folder in-case you woul like to try it before using it OR\n"
    "# (\"/Users/username/testing/\") for your home computer testing.\n"
    "PATH=./ \n"
    "\n"
    "IP=196.55.34.5\n"
    "PORT=80\n"
    "\n"
    "# Server Administrator details NB: ADMIN[EMAIL] for cases like Auto-emmail your domain Service Provider (SP) to register\n"
    "# your domain. The email to SP will be CC\"d and returned to this address.\n"
    "# \n"
    "# This email will also be placed on the Virtual Host's [ServerAdmin] field.\n"
    "\n"
    "ADMIN[COMPANY:NAME]=OVH Server Basement\n"
    "ADMIN[COMPANY:DESCRIPTION]=an Open Source servicer administration utility tool\n"
    "ADMIN[NAME]=Name Surname\n"
    "ADMIN[EMAIL]=ovhsbsupport@ovhstudio.co.za\n"
    "ADMIN[COMPANY:WEBSITE]=www.ovhserverbasement.co.za\n"
    "\n"
    "# SERVICE-PROVIDER (SP) details.\n"
    "\n"
    "DOMAIN[SP:NAME]=IS - Internet Solutions\n"
    "DOMAIN[SP:DESCRIPTION]=a leading African Internet Protocol-based Communications Service Provider\n"
    "DOMAIN[SP:EMAIL]=support[at]is.co.za\n"
    "DOMAIN[SP:WEBSITE]=www.is.co.za";
    
    output.close();
    
    cout<<"--- File 'ovh.sb.confg' has been created..!"<<endl;
}

void Confg::ConfgReader(const char* _confgfile)
{
    std::ifstream input;
    input.open(_confgfile);
    
    if(input.is_open()) // --- File already Exists
    {
        int i=0,j=0;
        while(!input.eof())
        {
            getline(input,line);
            
            stringstream tokens(line);
            string token;
            
            j=0;
            while(getline(tokens,token, '=')) // --- Fetch tokens
            {
                if(j==0) // --- 1st code parameter i.e. after '='
                {
                    indexValidCodeConfg[i] = token;
                    j++;
                }
                else if(j==1) // --- 2nd code parameter i.e. after '='
                {
                    valueValidCodeConfg[i] = token;
                    break;
                }
                else // --- It's a Non Valid Code
                {
                    break;
                }
            }
            
            indexConfg[i] = line; // --- Backup the original line from the .cnfg file
            
            i++;
        }
    }
    
    input.close();
}