#pragma once
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <QThread>
#include <QStringList>

using namespace std;

typedef enum
{
    translate_all,
    translate_files
} callMethod_t;

class Traduction : public QThread
{
    Q_OBJECT

private:

	map<string,string> _traducteur;
    callMethod_t _type;
    unsigned int _method;
    QString _param1;
    QString _param2;
    using QThread::start;

public:
    Traduction();
    void init_trad();
    inline void translateFiles(const char* fileNameIn,const char * fileNameOut);
    inline void translate(const char *inChaine, int mode,const  char * out_file_name = NULL);
    inline void translate_all_ORC(const char *inChaine,const char * out_file_name = NULL);
    void reverser(char s[]);
    bool isChainFormated(const char * s);
    QString prepareFasta(QString inFileName);
    void run();
    void start(callMethod_t type,const char * inParam1,const char * inParam2= NULL);

signals:
    void consoleChanged(QString s);
    void proteineDecrypted(QString prot);
    void startTimer();
    void stopTimer();
};
	
