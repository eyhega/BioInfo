#pragma once
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <QThread>
#include "filemanager.h"

using namespace std;

typedef enum
{
    translate_all,
    translate_files
} callMethod_t;

//!\brief Classe permettant la traduction d'une séquence ADN en séquence peptidique

class Traduction : public QThread
{
    Q_OBJECT

private:

	map<string,string> _traducteur; //!<Dictionnaire contenant la correspondance entre un codon et l'AA correspondant.
    callMethod_t _type; //!<Paramètre permettant de définir le type de méthode à appeler par le thread appelant.
	 QString _param1;	 //!<Paramètre des méthode à éxécuter.
    QString _param2; //!< Paramètre des méthode à éxécuter (optionnel).
    using QThread::start;

public:
    Traduction();
	//!\brief Initialise le dictionnaire _traducteur.
	void init_trad();
	/*!\brief Effectue la traduction d'une chaine depuis un fichier et écrit les résultats dans un autre fichier.
	 \par Remarque :
	 La traduction est effectuée pour tous les ORC.
	 \param fileNameIn Chemin du fichier source.
	 \param fileNameOut Chemin du fichier de sortie.
	 */
    inline void translateFiles(const char* fileNameIn,const char * fileNameOut);
	/*!\brief Effectue la traduction d'une chaine.
	 \par
	 Traduit la chaine passée en paramètre suivant l'ORC passé en paramètre et sort le résultat sur la console.
	 Une analyse de la chaine est faite afin de déterminer la proportion de la chaine codante.
	 La sortie est possible sur un fichier passé en paramètre.
	 \param inChaine Chaîne à traduire.
	 \param mode ORC pour lequel la chaîne doit être traduite.
	 \param file Fichier de sortie (optionnel).
	 */
    inline void translate(const char *inChaine, int mode,FileManager *file = NULL);
	/*!\brief Effectue la traduction d'une chaine pour tous les ORC.
	 \par
	 Traduit la chaine passée en paramètre suivant tous les ORC et sort les résultats sur la console.
	 La sortie est possible sur un fichier passé en paramètre.
	 \param inChaine Chaîne à traduire.
	 \param file Fichier de sortie (optionnel).
	 */
    inline void translate_all_ORC(const char *inChaine,FileManager * file = NULL);
	/*!\brief L'ordre des caractères de la chaine passée en paramètre est inversé.
	 \param s Chaine à inverser.
	 */
    void reverser(char s[]);
	/*!\brief Vérifie si la chaine passée en paramètre peut être traduite sans problème apparant.
	 \par
	 Teste si la chaîne est terminée par le caractère '*'.
	 \param s Chaine à tester.
	 \return Vrai si la chaîne peut être traduite.
	 */
    bool isChainFormated(const char * s);
	/*!\brief Méthode implementant le parallèlisme.
	 \par
	 Exécute de manière assynchrone les méthodes définies par la variable _type. 
	 */
    void run();
	/*!\brief Méthode permettant de lancer le thread.
	 \param type Définit quelles méthodes seront exécutées.
	 \param inParam1 Paramètre des méthode à éxécuter.
	 \param inParam2 Paramètre des méthode à éxécuter (optionnel).
	 
	 */
    void start(callMethod_t type,const char * inParam1,const char * inParam2= NULL);

signals:
    void consoleChanged(QString s);
    void proteineDecrypted(QString prot);
    void startTimer();
    void stopTimer();
};
	
