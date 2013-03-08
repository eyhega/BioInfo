#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
//!\brief Classe permettant la génération de chaînes aléatoires peptidiques ou nucléiques
class Generateur
{
	public:
	/*!\brief Génère une chaine nucléique aléatoire dans un fichier.
	 \param nomFic Chemin du fichier de sortie.
	 \param nombre_acide_nucleique Nombre d'acides nucléiques à générer aléatoirement.
	 */
		static void genACGT(string nomFic, int nombre_acide_nucleique);
	/*!\brief Génère une chaine peptidique aléatoire dans un fichier.
	 \param nomFic Chemin du fichier de sortie.
	 \param inNbPept Nombre de peptides à générer aléatoirement.
	 */
		static void genPept(string inFileName, int inNbPept);
};
