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
                cxefafenestro_pridatumojapogilo.cpp\
                cxefafenestro_pridatumojrestauxro.cpp\
                cxefafenestro_priidentigiloj.cpp\
                cxefafenestro_prikonfiguro.cpp\
                cxefafenestro_primuta.cpp\
                cxefafenestro_prireferencoj.cpp\
                cxefafenestro_pristartopagxo.cpp\
                cxefafenestro_spektaklomesagxon.cpp\
                datumojapogilo.cpp\
                datumojapogilo_destrojero.cpp\
                datumojapogilo_prieksportu.cpp\
                datumojapogilo_prielektucxiuj.cpp\
                datumojapogilo_prirezignu.cpp\
                datumojrestauxro.cpp\
                datumojrestauxro_destrojero.cpp\
                datumojrestauxro_priplenumu.cpp\
                datumojrestauxro_prireiru.cpp\
                datumojrestauxro_prisintakseanalizu.cpp\
                datumojrestauxro_prisxargi.cpp\
                hipertekstopagxo_acceptnavigationrequest.cpp\
                htmlmarkilo.cpp\
                htmlmarkilo_highlightblock.cpp\
                identigiloj.cpp\
                identigiloj_destrojero.cpp\
                identigiloj_prifonto.cpp\
                identigiloj_priobjektokodo.cpp\
                identigiloj_prireiru.cpp\
                konfiguro.cpp\
                konfiguro_destrojero.cpp\
                konfiguro_lingvoetikedosxangxo.cpp\
                konfiguro_prikonfirmu.cpp\
                konfiguro_primalfaru.cpp\
                konfiguro_primalsupren.cpp\
                konfiguro_primalsupro.cpp\
                konfiguro_prireiru.cpp\
                konfiguro_prisupren.cpp\
                konfiguro_prisupro.cpp\
                pagxoreferenco.cpp\
                pagxoreferenco_destrojero.cpp\
                provajxo.cpp\
                provajxo_destrojero.cpp\
                provajxo_prireiru.cpp\
                referencoj.cpp\
                referencoj_destrojero.cpp\
                referencoj_aludojelektajxosxangxo.cpp\
                referencoj_enigi.cpp\
                referencoj_kompletigitarespondo.cpp\
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
                referencoj_prireiru.cpp\
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
                sqlmarkilo.cpp\
                sqlmarkilo_highlightblock.cpp\
                statikajdatumoj.cpp

HEADERS      += agordoj.h\
                cxefafenestro.h\
                datumojapogilo.h\
                datumojrestauxro.h\
                hipertekstopagxo.h\
                htmlmarkilo.h\
                identigiloj.h\
                konfiguro.h\
                pagxoreferenco.h\
                provajxo.h\
                referencoj.h\
                rikordoregistrilo.h\
                sqlmarkilo.h\
                statikajdatumoj.h

FORMS        += cxefafenestro.ui\
                datumojapogilo.ui\
                datumojrestauxro.ui\
                identigiloj.ui\
                konfiguro.ui\
                pagxoreferenco.ui\
                provajxo.ui\
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
