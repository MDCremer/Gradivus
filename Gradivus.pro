CONFIG       += qt release

QT           += core gui widgets sql\
                webenginewidgets

TARGET        = Gradivus
DESTDIR       = $$(HOME)/Gradivus/binaroj
TEMPLATE      = app

SOURCES      += main.cpp\
                cxefafenestro.cpp\
                cxefafenestro_destrojero.cpp

HEADERS      += cxefafenestro.h

FORMS        += cxefafenestro.ui

TRANSLATIONS += gradivus_de.ts

RESOURCES    += gradivus.qrc

desktop.commands     = $(COPY_FILE) $$PWD/Gradivus.desktop $$(HOME)/Gradivus
skriptoj.commands    = $(COPY_DIR) $$PWD/skriptoj $$(HOME)/Gradivus/skriptoj
first.depends        = $(first) skriptoj desktop
export (first.depends)
export (desktop.commands)
export (skriptoj.commands)
QMAKE_EXTRA_TARGETS += first desktop skriptoj
