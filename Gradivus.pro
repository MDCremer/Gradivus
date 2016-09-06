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
                cxefafenestro_spektaklomesagxon.cpp\
                cxefafenestro_pridatumojapogilo.cpp\
                cxefafenestro_prikonfiguro.cpp\
                cxefafenestro_primuta.cpp\
                datumojapogilo.cpp\
                datumojapogilo_destrojero.cpp\
                datumojapogilo_priabortu.cpp\
                datumojapogilo_prieksportu.cpp\
                datumojapogilo_prielektucxiuj.cpp\
                hipertekstopagxo_acceptnavigationrequest.cpp\
                konfiguro.cpp\
                konfiguro_destrojero.cpp\
                konfiguro_priabortu.cpp\
                statikajdatumoj.cpp

HEADERS      += cxefafenestro.h\
                datumojapogilo.h\
                hipertekstopagxo.h\
                konfiguro.h\
                statikajdatumoj.h

FORMS        += cxefafenestro.ui\
                datumojapogilo.ui\
                konfiguro.ui

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
