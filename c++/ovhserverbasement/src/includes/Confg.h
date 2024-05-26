#ifndef CONFG_H
    #define CONFG_H
    
	class Confg
	{
	    private:
		
		std::string line,token;
		std::string systemName;
		const char* confgfile;
		
	    public:
		
		std::map<std::string, std::string> __Confg;
		std::map<int, std::string> indexConfg,indexValidCodeConfg,valueValidCodeConfg;
		
		Confg(); // --- Constructor and destructors 1
		Confg(std::string _systemName, const char* _confgfile); // --- Constructor and destructors 2
		
		void ConfgReset(const char* _confgfile);
		void ConfgReader(const char* _confgfile);
		void PreviewConfg(); // --- Preview .confg file
		void EditConfg(); // --- Edit .confg file
		void PreviewEditedChanges(int mustApply); // --- Preview edited changes (mustApply=1 for ApplyEditedChanges, =0 otherwise)
		void ApplyEditedChanges(); // --- Apply edited changes .confg file
		void SaveChanges(); // --- Save edited changes .confg file
		
		std::string getVal(const char* val);
		std::string getNode(const char* val);
		const int findKey(std::map<int, std::string> mapContainter, const char* val);
		
		bool isInMapKeyInt(std::map<int, std::string> mapContainter,int val);
		bool isInMapValInt(std::map<int, std::string> mapContainter,int val);
		bool isInMapKeyStr(const char* val);
		bool isInMapValStr(std::map<std::string, std::string> mapContainter,const char* val);
		
	};//End of the class
	
    #endif