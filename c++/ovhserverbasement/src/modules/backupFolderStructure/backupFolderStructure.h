#ifndef BACKUPFOLDERSTRUCTURE_H
    #define BACKUPFOLDERSTRUCTURE_H
	
	class backupFolderStructure
	{
	    private:
		
		std::string backupFolder;
		
	    public:
		
		backupFolderStructure(std::string _backupFolder); // --- Constructor and destructors
		
		void autoCreateBackupFolders(std::string domain);
		
	};//End of the class
	
    #endif