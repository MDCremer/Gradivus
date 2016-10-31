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
                cxefafenestro_kompletigitarespondo.cpp\
                cxefafenestro_konsento.cpp\
                cxefafenestro_montruinformo.cpp\
                cxefafenestro_pridatumbazoekstrakto.cpp\
                cxefafenestro_pridatumojapogilo.cpp\
                cxefafenestro_pridatumojrestauxro.cpp\
                cxefafenestro_prifontoj.cpp\
                cxefafenestro_priidentigiloj.cpp\
                cxefafenestro_priindekso.cpp\
                cxefafenestro_prikonfiguro.cpp\
                cxefafenestro_primuta.cpp\
                cxefafenestro_pripdfeldono.cpp\
                cxefafenestro_pripriskribo.cpp\
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
                eldono_indekso.cpp\
                eldono_priskribo.cpp\
                fontoj.cpp\
                fontoj_destrojero.cpp\
                fontoj_prienigo.cpp\
                fontoj_prireiru.cpp\
                fontoj_priselektado.cpp\
                fontoj_sxargi.cpp\
                hipertekstopagxo_acceptnavigationrequest.cpp\
                htmlmarkilo.cpp\
                htmlmarkilo_highlightblock.cpp\
                identigiloj.cpp\
                identigiloj_destrojero.cpp\
                identigiloj_priakceptu.cpp\
                identigiloj_prialternativojelekti.cpp\
                identigiloj_prielektajxosxangxo.cpp\
                identigiloj_prifonto.cpp\
                identigiloj_priforigu.cpp\
                identigiloj_prihistorialisto.cpp\
                identigiloj_prikodosxangxo.cpp\
                identigiloj_prikontribui.cpp\
                identigiloj_prilingvolimigo.cpp\
                identigiloj_primalfaru.cpp\
                identigiloj_prinovakodo.cpp\
                identigiloj_priobjektokodo.cpp\
                identigiloj_prireiru.cpp\
                identigiloj_privakigu.cpp\
                identigiloj_sxargi.cpp\
                kodoselektado.cpp\
                kodoselektado_destrojero.cpp\
                kodoselektado_priapliku.cpp\
                kodoselektado_pridevasenhavi.cpp\
                kodoselektado_priduoblealklako.cpp\
                kodoselektado_prielektajxosxangxo.cpp\
                kodoselektado_prikompletigitaenigo.cpp\
                kodoselektado_prirezignu.cpp\
                kodoselektado_sxargi.cpp\
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
                pagxoreferenco_enigi.cpp\
                pagxoreferenco_agordiliteraturo.cpp\
                pagxoreferenco_pagxosalto.cpp\
                pagxoreferenco_priapliku.cpp\
                pagxoreferenco_pricitajxo.cpp\
                pagxoreferenco_priforta.cpp\
                pagxoreferenco_prigrasa.cpp\
                pagxoreferenco_prikursiva.cpp\
                pagxoreferenco_priminora.cpp\
                pagxoreferenco_prireferenceita.cpp\
                pagxoreferenco_prirezignu.cpp\
                pagxoreferenco_prisuba.cpp\
                pagxoreferenco_prisubstretika.cpp\
                pagxoreferenco_prisuperskribita.cpp\
                pagxoreferenco_privakigu.cpp\
                provajxo.cpp\
                provajxo_destrojero.cpp\
                provajxo_prireiru.cpp\
                referencoj.cpp\
                referencoj_destrojero.cpp\
                referencoj_aludojelektajxosxangxo.cpp\
                referencoj_enigi.cpp\
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
                eldono.h\
                fontoj.h\
                hipertekstopagxo.h\
                htmlmarkilo.h\
                identigiloj.h\
                kodoselektado.h\
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
                fontoj.ui\
                identigiloj.ui\
                kodoselektado.ui\
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
