#ifndef WWWHCSSPRESET_H
    #define WWWCSSPRESET_H
	
	class wwwCSSPreset
	{
	    private:
		
		std::ofstream file;
		
		std::string systemName;
		std::string wwwFolder;
		
	    public:
		
		wwwCSSPreset(std::string _systemName, std::string _wwwFolder); // --- Constructor and destructors
		
		void autoPresetCSS(std::string domain);
		
	};//End of the class
	
    #endif