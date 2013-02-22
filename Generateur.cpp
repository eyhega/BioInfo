#include "Generateur.hpp"

void Generateur::genACGT(string nomFic, int nombre_acide_nucleique)
{
	FILE * fichier=fopen(nomFic.c_str(),"w");
	if(!fichier)
	{
		exit(1);
	}
	else
	{
		srand(time(0));
		for(int i=0;i<nombre_acide_nucleique;i++)
		{
			char c;
			int alea;
			alea=rand()%4;
			switch(alea)
			{
				case 1:
					c='A';
					break;
				case 2:
					c='C';
					break;
				case 3:
					c='G';
					break;
				case 0:
					c='T';
					break;
			}
			fprintf(fichier,"%c",c); 
		}
		fprintf(fichier,"*\n"); 
		fclose(fichier);
	}
}


void Generateur::genPept(string inFileName, int inNbPept)
{
	
}
