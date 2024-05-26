#ifndef WWWHJSPRESET_H
    #define WWWJSPRESET_H
	
	class wwwJSPreset
	{
	    private:
		
		std::ofstream file;
		
		std::string systemName;
		std::string wwwFolder;
		
	    public:
		
		wwwJSPreset(std::string _systemName, std::string _wwwFolder); // --- Constructor and destructors
		
		void autoPresetJS(std::string domain);
		
	};//End of the class
	
    #endif