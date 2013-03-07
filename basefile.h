#ifndef BASEFILE_H
#define BASEFILE_H

#include <QString>
#include <iostream>
#include <fstream>

using namespace std;

class BaseFile
{
protected:
    QString _fileName;
    ifstream  _inStream;
    ofstream  _outStream;

public:
    BaseFile(QString inFileName);
    ~BaseFile();
    const QString& getFileName() {return _fileName;}
    void setFileName(const QString& inFileName) { _fileName=inFileName;}

    //methods
    virtual QString readChain()=0;
    virtual void writeChain(QString& inChain)=0;
};

#endif // BASEFILE_H
