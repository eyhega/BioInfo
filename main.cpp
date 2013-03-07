#include <iostream>
#include <time.h>
#include "traduction.hpp"
#include "ReverseTraduction.hpp"
#include "tabwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TabWidget w;
    w.setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    w.show();


    return app.exec();
}
