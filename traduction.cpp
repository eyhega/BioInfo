#include "traduction.hpp"
using namespace std;

Traduction::Traduction() : QThread()
{
    init_trad();
}

void Traduction::reverser(char s[])
{
        int c,i,j;

        for(i=0,j=strlen(s)-1;i<j;i++,j--)
        {
                c=s[i];
                s[i]=s[j];
                s[j]=c;
        }
}


void Traduction::init_trad()
{
    _traducteur.insert(pair<string,string>("TTT","PHE"));
    _traducteur.insert(pair<string,string>("TTC","PHE"));
    _traducteur.insert(pair<string,string>("TTA","LEU"));
    _traducteur.insert(pair<string,string>("TTG","LEU"));
    _traducteur.insert(pair<string,string>("TCT","SER"));
    _traducteur.insert(pair<string,string>("TCC","SER"));
    _traducteur.insert(pair<string,string>("TCA","SER"));
    _traducteur.insert(pair<string,string>("TCG","SER"));
    _traducteur.insert(pair<string,string>("TAT","TYR"));
    _traducteur.insert(pair<string,string>("TAC","TYR"));
    _traducteur.insert(pair<string,string>("TAA","STOP"));
    _traducteur.insert(pair<string,string>("TAG","STOP"));
    _traducteur.insert(pair<string,string>("TGT","CYS"));
    _traducteur.insert(pair<string,string>("TGC","CYS"));
    _traducteur.insert(pair<string,string>("TGA","STOP"));
    _traducteur.insert(pair<string,string>("TGG","TRP"));
    _traducteur.insert(pair<string,string>("CTT","LEU"));
    _traducteur.insert(pair<string,string>("CTC","LEU"));
    _traducteur.insert(pair<string,string>("CTA","LEU"));
    _traducteur.insert(pair<string,string>("CTG","LEU"));
    _traducteur.insert(pair<string,string>("CCT","PRO"));
    _traducteur.insert(pair<string,string>("CCC","PRO"));
    _traducteur.insert(pair<string,string>("CCA","PRO"));
    _traducteur.insert(pair<string,string>("CCG","PRO"));
    _traducteur.insert(pair<string,string>("CAT","HIS"));
    _traducteur.insert(pair<string,string>("CAC","HIS"));
    _traducteur.insert(pair<string,string>("CAA","GLN"));
    _traducteur.insert(pair<string,string>("CAG","GLN"));
    _traducteur.insert(pair<string,string>("CGT","ARG"));
    _traducteur.insert(pair<string,string>("CGC","ARG"));
    _traducteur.insert(pair<string,string>("CGA","ARG"));
    _traducteur.insert(pair<string,string>("CGG","ARG"));
    _traducteur.insert(pair<string,string>("ATT","ILE"));
    _traducteur.insert(pair<string,string>("ATC","ILE"));
    _traducteur.insert(pair<string,string>("ATA","ILE"));
    _traducteur.insert(pair<string,string>("ATG","MET"));
    _traducteur.insert(pair<string,string>("ACT","THR"));
    _traducteur.insert(pair<string,string>("ACC","THR"));
    _traducteur.insert(pair<string,string>("ACA","THR"));
    _traducteur.insert(pair<string,string>("ACG","THR"));
    _traducteur.insert(pair<string,string>("AAT","ASN"));
    _traducteur.insert(pair<string,string>("AAC","ASN"));
    _traducteur.insert(pair<string,string>("AAA","LYS"));
    _traducteur.insert(pair<string,string>("AAG","LYS"));
    _traducteur.insert(pair<string,string>("AGT","SER"));
    _traducteur.insert(pair<string,string>("AGC","SER"));
    _traducteur.insert(pair<string,string>("AGA","ARG"));
    _traducteur.insert(pair<string,string>("AGG","ARG"));
    _traducteur.insert(pair<string,string>("GTT","VAL"));
    _traducteur.insert(pair<string,string>("GTC","VAL"));
    _traducteur.insert(pair<string,string>("GTA","VAL"));
    _traducteur.insert(pair<string,string>("GTG","VAL"));
    _traducteur.insert(pair<string,string>("GCT","ALA"));
    _traducteur.insert(pair<string,string>("GCC","ALA"));
    _traducteur.insert(pair<string,string>("GCA","ALA"));
    _traducteur.insert(pair<string,string>("GCG","ALA"));
    _traducteur.insert(pair<string,string>("GAT","ASP"));
    _traducteur.insert(pair<string,string>("GAC","ASP"));
    _traducteur.insert(pair<string,string>("GAA","GLU"));
    _traducteur.insert(pair<string,string>("GAG","GLU"));
    _traducteur.insert(pair<string,string>("GGT","GLY"));
    _traducteur.insert(pair<string,string>("GGC","GLY"));
    _traducteur.insert(pair<string,string>("GGA","GLY"));
    _traducteur.insert(pair<string,string>("GGG","GLY"));
}

void Traduction::translate(const char * inChaine, int mode,const char *out_file_name)
{
    stringstream ss,stream;
    FILE * fichier=NULL;
	bool reverse=(mode>2);
	string codon;
	char  temp[4];
	string proteine;
	int nb_codons_codant=0;
	int nb_codons_total_codant=0;
	bool codant=false;
	int index;
	int i;
	map<string,string>::iterator it;

    if(out_file_name)
        fichier=fopen(out_file_name,"a");

	reverse?index=mode-3:index=mode;
    i=index;
	while((inChaine[i]!='*')&&(inChaine[i+1]!='*')&&(inChaine[i+2]!='*'))
	{
		strncpy(temp,inChaine+i,3);
		temp[3]='\0';
		if(reverse)
			reverser(temp);
		codon=temp;

		it=_traducteur.find(codon);
        proteine=it->second;
        stream << proteine << ' ';

        cout<<proteine<<' ';
        if(fichier)
            fprintf(fichier,"%s ",proteine.c_str());
        ss << proteine << " ";
		//calcul du pourcentage codant
		if(proteine=="MET")
		{
			codant=true;
			nb_codons_codant=0;
		}
		if (codant) 
		{
			nb_codons_codant++;
		}
		if (proteine=="STOP")
		{
			codant=false;
			nb_codons_total_codant+=nb_codons_codant;
			nb_codons_codant=0;
			
		}
		i+=3;
	}
    if(fichier)
        fprintf(fichier, "*\n");
    ss << "*";


    stream << "<BR/>" << "Partie codante :"<<((double)nb_codons_total_codant/(double)(i/3))*100<<"%<BR/>";

	cout<<endl;
    cout << "Partie codante (%) :"<<((double)nb_codons_total_codant/(double)(i/3))*100<<endl;
    if(fichier)
        fclose(fichier);
    else
        emit proteineDecrypted(QString(ss.str().c_str()));

    emit consoleChanged(QString(stream.str().c_str()));

}

void Traduction::translate_all_ORC(const char * inChaine, const char *out_file_name)
{
	for(int i=0;i<6;i++)
	{
       translate(inChaine,i,out_file_name);
	}
}


//Verifie qu'une chaine est bien formatée
bool Traduction::isChainFormated(const char *s)
{
    return (s[strlen(s)-1] == '*');
}


void Traduction::translateFiles(const char* fileNameIn,const char * fileNameOut)
{
    string res,chaine;
    FILE * out;
    int i=1;
    ifstream fic(fileNameIn,ios::in);
    QString tmp;
    QStringList list= _param1.split(".");
    bool fasta= list.last()[0] == 'f';

    if(fic && !fasta)
    {
        emit consoleChanged("Ouverture des fichiers...<BR/>");
        while(getline(fic,chaine))
        {
            tmp.append("Traitement ligne ").append(i).append("...<BR/>");
            emit consoleChanged(tmp);
            tmp.clear();
            translate_all_ORC(chaine.c_str(),fileNameOut);
            out=fopen(fileNameOut,"a");
            if(out)
            {
                fputs("********************************\n",out);
                fclose(out);
            }
            tmp.append("Fin traitement ligne ").append(i).append("...<BR/><BR/>");
            emit consoleChanged(tmp);
            tmp.clear();
            ++i;
        }
       emit consoleChanged("Fermeture des fichiers...<BR/>");
    }
    else if(fasta)
    {
        tmp=prepareFasta(QString(fileNameIn));
        translate_all_ORC(tmp.toStdString().c_str(),fileNameOut);
    }
}

QString Traduction::prepareFasta(QString inFileName)
{
    ifstream file(inFileName.toStdString().c_str(),ios::in);
    QString chain;
    string tmp;
    if(file)
    {
        getline(file,tmp);
        if(tmp.c_str()[0] != '>')
            chain.append(tmp.c_str());
        while(getline(file,tmp) && tmp.c_str()[0] != '>')
            chain.append(tmp.c_str());

        chain.append("*");
        file.close();
    }
    else
        emit consoleChanged("Erreur lors de l'ouverture du fichier");

    return chain;
}

void Traduction::start(callMethod_t type,const char * inParam1,const char * inParam2)
{
    _type=type;
    _param1=QString(inParam1);
    _param2=QString(inParam2);
    start(QThread::HighestPriority);

}

void Traduction::run()
{

    emit startTimer();
    switch(_type)
    {
    case translate_all:  translate_all_ORC(_param1.toStdString().c_str(),_param2.toStdString().c_str()); break;
    case translate_files:translateFiles(_param1.toStdString().c_str(),_param2.toStdString().c_str());break;
    }
    emit stopTimer();
}
