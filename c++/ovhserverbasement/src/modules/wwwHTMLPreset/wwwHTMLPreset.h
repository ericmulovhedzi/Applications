#ifndef WWWHTMLPRESET_H
    #define WWWHTMLPRESET_H
	
	class wwwHTMLPreset
	{
	    private:
		
		std::ofstream file;
		
		std::string systemName;
		std::string wwwFolder;
		
	    public:
		
		wwwHTMLPreset(std::string _systemName, std::string _wwwFolder); // --- Constructor and destructors
		
		void autoPresetHTML(std::string domain);
		
	};//End of the class
	
    #endif