#ifndef FASTAFILEMANAGER_H
#define FASTAFILEMANAGER_H

#include "basefile.h"
#include <map>
#include <QRegExp>
#include <sstream>
#include <QDateTime>

//!\brief Classe permettant la gestion d'un fichier FASTA.

class FastaFileManager : public BaseFile
{
private:
    map<char,string> _translate; //!<Dictionnaire contenant la correspondance entre un codon et l'AA correspondant.
public:
    FastaFileManager(QString inFileName);
	//!\brief Initialise le dictionnaire _translate.
	 void loadMap();	
	/*!\brief Lit une ligne du fichier FASTA.
	 \return La ligne du fichier FASTA.
	 */
    virtual QString readChain();
	/*!\brief Ecrit une chaîne dans le fichier FASTA.
	 \param inChain Chaîne à écrire dans le fichier FASTA.
	 */
    virtual void writeChain(QString& inChain);
};

#endif // FASTAFILEMANAGER_H
