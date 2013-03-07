#include "textfilemanager.h"

TextFileManager::TextFileManager(QString inFileName) : BaseFile(inFileName)
{

}


QString TextFileManager::readChain()
{
    string tmp;

    if(!_inStream.is_open())
        _inStream.open(_fileName.toStdString().c_str(),ios::in);
    getline(_inStream,tmp);

    return QString(tmp.c_str());
}

void TextFileManager::writeChain(QString& inChain)
{
    if(!_outStream.is_open())
        _outStream.open(_fileName.toStdString().c_str(),ios::out|ios::trunc);

    _outStream << inChain.toStdString() << endl;
}
