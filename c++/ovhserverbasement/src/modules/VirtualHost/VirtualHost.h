#ifndef VIRTUALHOST_H
    #define VIRTUALHOST_H
	
	class VirtualHost
	{
	    private:
		
		std::ofstream VirtualHostFile;
		
		std::string systemName;
		std::string wwwFolder;
		std::string virtualHostFolder;
		std::string virtualHostFile;
		
	    public:
		
		VirtualHost(std::string _systemName, std::string _virtualHostFolder, std::string _wwwFolder, std::string _virtualHostFile); // --- Constructor and destructors
		
		void autoAppendVirtualHost(std::string ipAddress,std::string domain);
		
	};//End of the class
	
    #endif