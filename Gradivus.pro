CONFIG       += qt release

QT           += core gui widgets sql\
                webenginewidgets network

TARGET        = Gradivus
DESTDIR       = $$(HOME)/Gradivus/binaroj
TEMPLATE      = app

SOURCES      += main.cpp\
                agordoj_akirulingvanombro.cpp\
                agordoj_akirulingvarango.cpp\
                agordoj_sxargu.cpp\
                cxefafenestro.cpp\
                cxefafenestro_destrojero.cpp\
                cxefafenestro_konsento.cpp\
                cxefafenestro_montruinformo.cpp\
                cxefafenestro_spektaklomesagxon.cpp\
                cxefafenestro_pridatumojapogilo.cpp\
                cxefafenestro_prikonfiguro.cpp\
                cxefafenestro_prireferencoj.cpp\
                cxefafenestro_primuta.cpp\
                datumojapogilo.cpp\
                datumojapogilo_destrojero.cpp\
                datumojapogilo_priabortu.cpp\
                datumojapogilo_prieksportu.cpp\
                datumojapogilo_prielektucxiuj.cpp\
                hipertekstopagxo_acceptnavigationrequest.cpp\
                htmlmarkilo.cpp\
                htmlmarkilo_highlightblock.cpp\
                konfiguro.cpp\
                konfiguro_destrojero.cpp\
                konfiguro_lingvoetikedosxangxo.cpp\
                konfiguro_priabortu.cpp\
                konfiguro_prikonfirmu.cpp\
                konfiguro_primalfaru.cpp\
                konfiguro_primalsupren.cpp\
                konfiguro_primalsupro.cpp\
                konfiguro_prisupren.cpp\
                konfiguro_prisupro.cpp\
                referencoj.cpp\
                referencoj_destrojero.cpp\
                referencoj_aludojelektajxosxangxo.cpp\
                referencoj_enigi.cpp\
                referencoj_kompletigitarespondo.cpp\
                referencoj_priabortu.cpp\
                referencoj_priakceptu.cpp\
                referencoj_pricitajxo.cpp\
                referencoj_priforigu.cpp\
                referencoj_priforta.cpp\
                referencoj_prigrasa.cpp\
                referencoj_prikontribui.cpp\
                referencoj_prikursiva.cpp\
                referencoj_primalfaru.cpp\
                referencoj_priminora.cpp\
                referencoj_prireferenceita.cpp\
                referencoj_prisubstretika.cpp\
                referencoj_prisuperskribita.cpp\
                referencoj_prisuba.cpp\
                referencoj_privakigu.cpp\
                referencoj_referencoenigisxangxo.cpp\
                referencoj_sxargialudoj.cpp\
                rikordoregistrilo.cpp\
                rikordoregistrilo_fermu.cpp\
                rikordoregistrilo_komencu.cpp\
                rikordoregistrilo_malfaru.cpp\
                rikordoregistrilo_plenumu.cpp\
                statikajdatumoj.cpp

HEADERS      += agordoj.h\
                cxefafenestro.h\
                datumojapogilo.h\
                hipertekstopagxo.h\
                htmlmarkilo.h\
                konfiguro.h\
                referencoj.h\
                rikordoregistrilo.h\
                statikajdatumoj.h

FORMS        += cxefafenestro.ui\
                datumojapogilo.ui\
                konfiguro.ui\
                referencoj.ui

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
