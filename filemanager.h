#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "textfilemanager.h"
#include "fastafilemanager.h"
#include<QStringList>

//!\brief Classe permettant la gestion des fichiers d'entrée et de sortie

class FileManager
{
private:
    BaseFile * _fileIn;//!<Fichier d'entrée.
    BaseFile * _fileOut;//!<Fichier de sortie.
public:
	/*!\brief Constructeur n'initialisant qu'un fichier d'entrée.
	 \param inFile Chemin du fichier source.
	 */
    FileManager(QString& inFile);
	/*!\brief Constructeur initialisant un fichier d'entrée et un fichier de sortie.
	 \param inFile Chemin du fichier source.
	 \param inFileOut Chemin du fichier sortie.
	 */
    FileManager(QString& inFile,QString& inFileOut);
    ~FileManager();
	/*!\brief Lit une ligne du fichier d'entrée
	 \return La ligne du fichier d'entrée.
	 */
    QString read();
	/*!\brief Ecrit une chaîne dans le fichier adapté.
	 \par
	 Ecrit dans le fichier de sortie si défini, dans le fichier d'entrée sinon.
	 \param inChain Chaîne à écrire dans le fichier.
	 */
    void write(QString& inChain);
};

#endif // FILEMANAGER_H
