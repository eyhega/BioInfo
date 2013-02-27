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

using namespace std;

typedef enum
{
    reverseTranslateM,
    loadFileAndTranslate
} ReverseMethod_t;

class ReverseTraduction : public QThread
{
    Q_OBJECT

	private:
		multimap<string,string> _reverseTraducter;
		vector< vector<string> > _resultChains;
		
		//pour l'affichage des chaines résultantes
		vector<unsigned> _tableCount;

        QString _param1;
        QString _fileName;
        ReverseMethod_t _type;
        using QThread::start;
	
	public:
		ReverseTraduction();
		~ReverseTraduction();
		void loadReverseTrad();
		void reverseTranslate(const char * aa);
		void displayChains();
        void parcours(const char *inFileName = NULL);
		bool incremente();
        void loadFicAndTranslate(const char* inFileName);
        void run();
        void start(ReverseMethod_t type,const char * param1,const char * fileName= NULL);

signals:
        void chainDecrypted(QString s);
        void startTimer();
        void stopTimer();

};
#endif // __REVERSE_TRADUCTION_H__
