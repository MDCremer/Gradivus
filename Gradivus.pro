QT           += core gui widgets sql\
                webenginewidgets

TARGET        = Gradivus
TEMPLATE      = app

SOURCES      += main.cpp\
                cxefafenestro.cpp\
                cxefafenestro_destrojero.cpp

HEADERS      += cxefafenestro.h

FORMS        += cxefafenestro.ui

TRANSLATIONS += gradivus_de.ts

RESOURCES    += gradivus.qrc
