#include "basefile.h"

BaseFile::BaseFile(QString inFileName) : _fileName(inFileName)
{
}

 BaseFile::~BaseFile()
 {
     if(_inStream.is_open())
        _inStream.close();

     if(_outStream.is_open())
         _outStream.close();
 }
