#ifndef WWWHPHPPRESET_H
    #define WWWPHPPRESET_H
	
	class wwwPHPPreset
	{
	    private:
		
		std::ofstream file;
		
		std::string systemName;
		std::string wwwFolder;
		
	    public:
		
		wwwPHPPreset(std::string _systemName, std::string _wwwFolder); // --- Constructor and destructors
		
		void autoPresetPHP(std::string domain);
		
	};//End of the class
	
    #endif