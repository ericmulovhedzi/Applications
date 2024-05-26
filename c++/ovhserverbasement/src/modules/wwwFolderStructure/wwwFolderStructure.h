#ifndef WWWFOLDERSTRUCTURE_H
    #define WWWFOLDERSTRUCTURE_H
	
	class wwwFolderStructure
	{
	    private:
		
		std::string wwwFolder;
		
	    public:
		
		wwwFolderStructure(std::string _wwwFolder); // --- Constructor and destructors
		
		void autoCreateWWWFolders(std::string domain);
		
	};//End of the class
	
    #endif