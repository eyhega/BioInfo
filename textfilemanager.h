#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H

#include "basefile.h"

class TextFileManager : public BaseFile
{
public:
    TextFileManager(QString inFileName);
    virtual QString readChain();
    virtual void writeChain(QString& inChain);
};

#endif // TEXTFILEMANAGER_H
