#-------------------------------------------------
#
# Project created by QtCreator 2013-02-21T15:30:20
#
#-------------------------------------------------

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bioinfo
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app


SOURCES += \
    traduction.cpp \
    ReverseTraduction.cpp \
    main.cpp \
    Generateur.cpp \
    tabwidget.cpp

HEADERS += \
    traduction.hpp \
    ReverseTraduction.hpp \
    Generateur.hpp \
    tabwidget.h

OTHER_FILES += \
    toto.txt \
    sortie.txt

FORMS += \
    tabwidget.ui
