#ifndef FASTAFILEMANAGER_H
#define FASTAFILEMANAGER_H

#include "basefile.h"
#include <map>
#include <QRegExp>
#include <sstream>
#include <QDateTime>

class FastaFileManager : public BaseFile
{
private:
    map<char,string> _translate;
public:
    FastaFileManager(QString inFileName);
    void loadMap();
    virtual QString readChain();
    virtual void writeChain(QString& inChain);
};

#endif // FASTAFILEMANAGER_H
