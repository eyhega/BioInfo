#include <iostream>
#include <time.h>
#include "traduction.hpp"
#include "ReverseTraduction.hpp"
#include "tabwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    /*Traduction traduct;
    ReverseTraduction trad;*/

    QApplication app(argc, argv);
    TabWidget w;
    w.show();

	
    /*traduct.translate_all_ORC("ATGCCGCTGCGAGTCGATGCTAGCTGAG*","toto.txt");*/
	
    /*trad.loadFicAndTranslate("toto.txt");
	trad.displayChains();
	
	clock_t t1=clock();
	trad.parcours("sortie.txt");
    cout << (clock()-t1)/((float)CLOCKS_PER_SEC) <<" sec."<<endl;*/
	
    return app.exec();
}
