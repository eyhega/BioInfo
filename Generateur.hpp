#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Generateur
{
	public:
		static void genACGT(string nomFic, int nombre_acide_nucleique);
		static void genPept(string inFileName, int inNbPept);
};
