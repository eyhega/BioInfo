#include "Generateur.hpp"

char Generateur::PROT[][5]={"ALA","ARG","ASN","ASP","CYS","GLN","GLU","GLY","HIS","ILE","LEU","LYS","MET","PHE","PRO","PYL","SEC","SER","THR","TRP","TYR","VAL","STOP"};
const int Generateur::NB_PROT=23;

void Generateur::genACGT(QString nomFic, int nombre_acide_nucleique,int inNb_chain)
{
    FileManager file(nomFic);
    QString chain;
    for(int i=0; i < inNb_chain; ++i)
    {
        chain=genACGT(nombre_acide_nucleique);
        file.write(chain);
    }
}

QString Generateur::genACGT(int nombre_acide_nucleique)
{
    QString ret;
    for(int i=0;i<nombre_acide_nucleique;i++)
    {
        char c;
        int alea;
        alea=rand()%4;
        switch(alea)
        {
            case 1:
                ret.append("A");
                break;
            case 2:
                ret.append("C");
                break;
            case 3:
                ret.append("G");
                break;
            case 0:
                ret.append("T");
                break;
        }
    }
    ret.append("*");
    return ret;
}

void Generateur::genPept(QString inFileName, int inNbPept, int nb_chain)
{
    QString chain;
    FileManager file(inFileName);
    for(int i=0; i < nb_chain ; ++i)
    {
        chain=genPept(inNbPept);
        file.write(chain);
    }
}

QString Generateur::genPept(int inNbPept)
{
    QString ret;
    for(int i=0 ; i < inNbPept ; ++i)
        ret.append(PROT[rand()%NB_PROT]).append(" ");
    return ret.append("*");
}
