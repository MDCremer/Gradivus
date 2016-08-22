CONFIG       += qt release

QT           += core gui widgets sql\
                webenginewidgets

TARGET        = Gradivus
DESTDIR       = $$(HOME)/Gradivus/binaroj
TEMPLATE      = app

SOURCES      += main.cpp\
                cxefafenestro.cpp\
                cxefafenestro_destrojero.cpp\
                cxefafenestro_montruinformo.cpp\
                cxefafenestro_pridatumojapogilo.cpp\
                cxefafenestro_primuta.cpp\
                hipertekstopagxo_acceptnavigationrequest.cpp

HEADERS      += cxefafenestro.h\
                hipertekstopagxo.h

FORMS        += cxefafenestro.ui

TRANSLATIONS += gradivus_de.ts

RESOURCES    += gradivus.qrc

desktop.commands     = $(COPY_FILE) $$PWD/Gradivus.desktop $$(HOME)/Gradivus
dokumentoj.commands  = $(COPY_DIR) $$PWD/dokumentoj $$(HOME)/Gradivus
skriptoj.commands    = $(COPY_DIR) $$PWD/skriptoj $$(HOME)/Gradivus
first.depends        = $(first) skriptoj dokumentoj desktop
export (first.depends)
export (desktop.commands)
export (dokumentoj.commands)
export (skriptoj.commands)
QMAKE_EXTRA_TARGETS += first desktop dokumentoj skriptoj
