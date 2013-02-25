#pragma once
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <QObject>
using namespace std;

class Traduction : public QObject
{
    Q_OBJECT

private:

	map<string,string> _traducteur;

public:
    Traduction();
    void init_trad();
    void translateFiles(const char* fileNameIn,const char * fileNameOut);
    string translate(const char *inChaine, int mode,const  char * out_file_name = NULL);
    string translate_all_ORC(const char *inChaine,const char * out_file_name = NULL);
    void reverser(char s[]);
    bool isChainFormated(const char * s);

signals:
    void consoleChanged(QString s);
};
	
