QT           += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET        = Gradivus
TEMPLATE      = app

SOURCES      += main.cpp\
                cxefafenestro.cpp\
                cxefafenestro_destrojero.cpp

HEADERS      += cxefafenestro.h

FORMS        += cxefafenestro.ui

TRANSLATIONS += gradivus_de.ts

RESOURCES    += gradivus.qrc
