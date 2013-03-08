#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include <QString>
#include "filemanager.h"

using namespace std;
//!\brief Classe permettant la génération de chaînes aléatoires peptidiques ou nucléiques
class Generateur
{
    private:
    static char PROT[][5];
    static const int NB_PROT;

	public:
	/*!\brief Génère une chaine nucléique aléatoire dans un fichier.
	 \param nomFic Chemin du fichier de sortie.
	 \param nombre_acide_nucleique Nombre d'acides nucléiques �  générer aléatoirement.
	 */
        static void genACGT(QString nomFic, int nombre_acide_nucleique, int inNb_chain);

        static QString genACGT(int nombre_acide_nucleique);


	/*!\brief Génère une chaine peptidique aléatoire dans un fichier.
	 \param nomFic Chemin du fichier de sortie.
	 \param inNbPept Nombre de peptides �  générer aléatoirement.
	 */
        static void genPept(QString inFileName, int inNbPept, int inNb_chain);

        static QString genPept(int inNbPept);

};
