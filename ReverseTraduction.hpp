#ifndef __REVERSE_TRADUCTION_H__
#define __REVERSE_TRADUCTION_H__
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

class ReverseTraduction
{
	private:
		multimap<string,string> _reverseTraducter;
		vector< vector<string> > _resultChains;
		
		//pour l'affichage des chaines résultantes
		vector<unsigned> _tableCount;
	
	public:
		ReverseTraduction();
		~ReverseTraduction();
		void loadReverseTrad();
		void reverseTranslate(const char * aa);
		void displayChains();
		void parcours(string inFileName);
		bool incremente();
		void loadFicAndTranslate(string inFileName);
};
#endif // __REVERSE_TRADUCTION_H__
