#ifndef __REVERSE_TRADUCTION_H__
#define __REVERSE_TRADUCTION_H__
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <fstream>
#include <string.h>
#include <QThread>
#include <sstream>
#include "filemanager.h"

using namespace std;

typedef enum
{
    reverseTranslateM,
    loadFileAndTranslate
} ReverseMethod_t;

//!\brief Classe permettant la traduction d'une séquence peptidique en séquence ADN.

class ReverseTraduction : public QThread
{
    Q_OBJECT

	private:
	multimap<string,string> _reverseTraducter;//!<Dictionnaire contenant la correspondance entre l'AA et les codons suceptible de le coder.
	vector< vector<string> > _resultChains;//!<Contient l'ensemble des condons possibles pour chaque AA de la séquence.
		
		//pour l'affichage des chaines résultantes
		vector<unsigned> _tableCount;//!<Compteur permettant de parcourir l'ensemble des possibilités de chaines codantes.

        QString _param1;//!<Paramètre des méthode à éxécuter.
        QString _fileName;//!<Chemin du fichier à utiliser dans les méthodes threadés.
        ReverseMethod_t _type;//!<Attribut permettant de définir le type de méthode à appeler par le thread appelant.
        using QThread::start;
	
	public:
		ReverseTraduction();
		~ReverseTraduction();
	
	//!\brief Initialise le dictionnaire _reverseTraducter.
		void loadReverseTrad();
	
	/*!\brief Effectue la traduction de la chaine.
	 \param aa Chaîne à traduire.
	 */
		void reverseTranslate(const char * aa);
	
	//!\brief Affiche le contenu de _resultChains sur la console.

		void displayChains();
	/*!\brief Parcours l'ensemble des chaines codantes possibles.
	 \par
	 Le résultat est affiché sur console par défault. Possibilité de le passer dans un fichier.
	 \param file Fichier de sortie.
	 */
		void parcours(FileManager * file = NULL);
	
	/*!\brief Incrémente le compteur _tableCout.
	 \return Vrai si la fin est atteinte.
	 */
		bool incremente();
	/*!\brief Effectue la traduction de la chaine chargée à partir d'un fichier.
	 \param file Fichier dans lequel se trouve la chaine à traduire.
	 */
        void loadFicAndTranslate(FileManager * file);
	/*!\brief Méthode implementant le parallèlisme.
	 \par
	 Exécute de manière assynchrone les méthodes définies par la variable _type. 
	 */
        void run();
	/*!\brief Méthode permettant de lancer le thread.
	 \param type Définit quelles méthodes seront exécutées.
	 \param param1 Paramètre des méthode à éxécuter.
	 \param fileName Chemin du fichier à utiliser(optionnel).
	 
	 */
        void start(ReverseMethod_t type,const char * param1,const char * fileName= NULL);

signals:
        void chainDecrypted(QString s);
        void consoleChanged(QString s);
        void startTimer();
        void stopTimer();

};
#endif // __REVERSE_TRADUCTION_H__
