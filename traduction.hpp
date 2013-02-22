#pragma once
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

class Traduction
{
	map<string,string> _traducteur;

	public:
    Traduction();
	void init_trad();
    string translate(const char *inChaine, int mode,const  char * out_file_name = NULL, stringstream *stream = NULL);
    string translate_all_ORC(const char *inChaine,const char * out_file_name = NULL,stringstream *stream= NULL);
	void reverser(char s[]);
    bool isChainFormated(const char * s);
};
	
