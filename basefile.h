#ifndef BASEFILE_H
#define BASEFILE_H

#include <QString>
#include <iostream>
#include <fstream>

using namespace std;

//!\brief Classe permettant les échange de flux avec un fichier.

class BaseFile
{
protected:
    QString _fileName;//!<Chemin du fichier avec lequel se font les échanges de flux.
    ifstream  _inStream;//!<Flux d'entrée.
    ofstream  _outStream;//!<Flux de sortie.

public:
    BaseFile(QString inFileName);
    virtual ~BaseFile();
    const QString& getFileName() {return _fileName;}
    void setFileName(const QString& inFileName) { _fileName=inFileName;}

    //methodes virtuelles pures
	
	/*!\brief Lit une ligne du fichier
	 \return La ligne du fichier.
	 */
    virtual QString readChain()=0;
	/*!\brief Ecrit une chaîne dans le fichier.
	 \param inChain Chaîne �  écrire dans le fichier.
	 */
    virtual void writeChain(QString& inChain)=0;
};

#endif // BASEFILE_H
