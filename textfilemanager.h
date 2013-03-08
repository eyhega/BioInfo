#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H

#include "basefile.h"

//!\brief Classe permettant la lecture ou l'écriture de texte dans un fichier
class TextFileManager : public BaseFile
{
public:
	/*!\brief Constructeur à partir d'un chemin de fichier
	\param inFileName Chemin du fichier.
	 */
    TextFileManager(QString inFileName);
	/*!\brief Lit une ligne du fichier
	 \return La ligne du fichier.
	 */
    virtual QString readChain();
	/*!\brief Ecrit une chaîne dans le fichier.
	 \param inChain Chaîne à écrire dans le fichier.
	 */
    virtual void writeChain(QString& inChain);
};

#endif // TEXTFILEMANAGER_H
