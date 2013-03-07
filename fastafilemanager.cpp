#include "fastafilemanager.h"

void FastaFileManager::loadMap()
{
    _translate.insert(pair<char,string>('A',"ALA"));
    _translate.insert(pair<char,string>('B',"ASP"));
    _translate.insert(pair<char,string>('C',"CYS"));
    _translate.insert(pair<char,string>('D',"ASN"));
    _translate.insert(pair<char,string>('E',"GLU"));
    _translate.insert(pair<char,string>('F',"PHE"));
    _translate.insert(pair<char,string>('G',"GLY"));
    _translate.insert(pair<char,string>('H',"HIS"));
    _translate.insert(pair<char,string>('I',"ILE"));
    _translate.insert(pair<char,string>('K',"LYS"));
    _translate.insert(pair<char,string>('L',"LEU"));
    _translate.insert(pair<char,string>('M',"MET"));
    _translate.insert(pair<char,string>('N',"ASN"));
    _translate.insert(pair<char,string>('P',"PRO"));
    _translate.insert(pair<char,string>('Q',"GLN"));
    _translate.insert(pair<char,string>('R',"ARG"));
    _translate.insert(pair<char,string>('S',"SER"));
    _translate.insert(pair<char,string>('T',"THR"));
    _translate.insert(pair<char,string>('V',"VAL"));
    _translate.insert(pair<char,string>('Y',"TYR"));
    _translate.insert(pair<char,string>('Z',"GLU"));
    _translate.insert(pair<char,string>('X',"ANY"));
    _translate.insert(pair<char,string>('*',"STOP"));
}


FastaFileManager::FastaFileManager(QString inFileName) : BaseFile(inFileName)
{
    loadMap();
}


QString FastaFileManager::readChain()
{
    QString chain;
    string tmp;
    char c;
    int length;
    QRegExp reg("^(A|G|T|C)+$");

    if(!_inStream.is_open())
        _inStream.open(_fileName.toStdString().c_str(),ios::in);

    getline(_inStream,tmp);

    if(tmp.c_str()[0] != '>')//test si commentaire
        chain.append(tmp.c_str());

    while(getline(_inStream,tmp) && tmp.c_str()[0] != '>')
    {
        chain.append(tmp.c_str());
    }


    if(!chain.contains(reg))//cas lecture de proteines
    {
        string charChain=chain.toStdString();
        length=charChain.length();
        chain.clear();
        for(int i=0;i<length;++i)
        {
            chain.append(_translate[charChain[i]].c_str());
            chain.append(" ");
        }
    }

    if(!chain.isEmpty()) chain.append("*");

    return chain;
}

void FastaFileManager::writeChain(QString& inChain)
{
    QRegExp reg("^(A|G|T|C|\\*)+$");
    string tmp;
    stringstream ss,prot;
    map<char,string>::iterator it;

    if(!_outStream.is_open())
        _outStream.open(_fileName.toStdString().c_str(),ios::out|ios::trunc);

    _outStream << "> " << QDateTime::currentDateTime().toString().toStdString() <<  endl;

    if (inChain.contains(reg)) //ACGT
    {
        inChain[inChain.length()-1]='\0';
        _outStream << inChain.toStdString() << endl;
    }
    else //cas proteines
    {
        ss.str(inChain.toStdString());
        ss >> tmp;
        while(tmp != "*")
        {
            it=_translate.begin();
            while(it!= _translate.end() && it->second != tmp) ++it;
            prot << it->first;
            ss >> tmp;
        }
        _outStream << prot.str() << endl;
    }
}
