#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "textfilemanager.h"
#include "fastafilemanager.h"
#include<QStringList>

class FileManager
{
private:
    BaseFile * _fileIn;
    BaseFile * _fileOut;
public:
    FileManager(QString& inFile);
    FileManager(QString& inFile,QString& inFileOut);
    ~FileManager();
    QString read();
    void write(QString& inChain);
};

#endif // FILEMANAGER_H
