#include "filemanager.h"

FileManager::FileManager(QString &inFile)
{
     _fileOut=NULL;
    if(inFile.split(".").last()[0].toLower() == 'f')
        _fileIn = new FastaFileManager(inFile);
    else
        _fileIn = new TextFileManager(inFile);
}

FileManager::FileManager(QString &inFile,QString &inFileOut)
{
    if(inFile.split(".").last()[0].toLower() == 'f')
        _fileIn = new FastaFileManager(inFile);
    else
        _fileIn = new TextFileManager(inFile);

    if(inFileOut.split(".").last()[0].toLower() == 'f')
        _fileOut = new FastaFileManager(inFileOut);
    else
        _fileOut = new TextFileManager(inFileOut);

}

FileManager::~FileManager()
{
    delete _fileIn;
    if(_fileOut) delete _fileOut;
}


QString FileManager::read()
{
    return _fileIn->readChain();
}

void FileManager::write(QString& inChain)
{
    if(_fileOut)
        _fileOut->writeChain(inChain);
    else
        _fileIn->writeChain(inChain);
}
