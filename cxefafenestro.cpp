#include <QCheckBox>
#include <QMainWindow>
#include <QPushButton>
#include <QStringList>
#include <QWidget>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"

cxefaFenestro::cxefaFenestro(QWidget *gepatro):QMainWindow(gepatro),ui(new Ui::cxefaFenestro)
{QWebEngineSettings *foliumiloAgordoj=QWebEngineSettings::globalSettings();
 foliumiloAgordoj->setFontSize(QWebEngineSettings::DefaultFontSize,16);
 foliumiloAgordoj->setFontFamily(QWebEngineSettings::SansSerifFont,"Noto Sans UI");
 ui->setupUi(this);
 ui->informaMontro->setPage(new hipertekstoPagxo());
 connect(ui->datumojApogilo,&QPushButton::clicked,this,&cxefaFenestro::priDatumojApogilo);
 connect(ui->konfiguro,&QPushButton::clicked,this,&cxefaFenestro::priKonfiguro);
 connect(ui->referencoj,&QPushButton::clicked,this,&cxefaFenestro::priReferencoj);
 connect(ui->muta,&QCheckBox::stateChanged,this,&cxefaFenestro::priMuta);
 connect(ui->startoPagxo,&QPushButton::clicked,this,&cxefaFenestro::priStartoPagxo);
 connect(ui->datumojRestauxro,&QPushButton::clicked,this,&cxefaFenestro::priDatumojRestauxro);
 connect(ui->identigiloj,&QPushButton::clicked,this,&cxefaFenestro::priIdentigiloj);
 landoNomoj=QStringList()<<tr("AD - Andoro")<<tr("AE - Unui\304\235intaj Arabaj Emirlandoj")<<tr("AF - Afganujo")
   <<tr("AG - Antigvo kaj Barbudo")<<tr("AI - Angvilo")<<tr("AL - Albanujo")<<tr("AM - Armenujo")<<tr("AO - Angolo")
   <<tr("AR - Argentino")<<tr("AS - Amerika Samoo")<<tr("AT - A\305\255strujo")<<tr("AU - A\305\255stralio")
   <<tr("AW - Arubo")<<tr("AZ - Azerbaj\304\235ano")<<tr("BA - Bosnio kaj Hercegovino")<<tr("BB - Barbado")
   <<tr("BD - Banglade\305\235o")<<tr("BE - Belgujo")<<tr("BF - Burkino")<<tr("BG - Bulgarujo")<<tr("BH - Bareijno")
   <<tr("BI - Burundo")<<tr("BJ - Benino")<<tr("BL - Sankta Bartolomeo")<<tr("BM - Bermudo")<<tr("BN - Brunejo")
   <<tr("BO - Bolivio")<<tr("BQ - BES Insuloj")<<tr("BR - Brazilo")<<tr("BS - Bahamoj")<<tr("BT - Butano")
   <<tr("BW - Bocvano")<<tr("BY - Belorusujo")<<tr("BZ - Belizo") <<tr("CA - Kanado")
   <<tr("CD - Demokratia Respubliko de Kongo")<<tr("CF - Centafrika Respubliko")<<tr("CG - Kongo")<<tr("CH - Svisujo")
   <<tr("CI - Eburbordo")<<tr("CK - Insuloj Cook")<<tr("CL - \304\210ilio")<<tr("CM - Kameruno")<<tr("CN - \304\210inujo")
   <<tr("CO - Kolombio")<<tr("CR - Kostariko")<<tr("CU - Kubo")<<tr("CV - Kabo Verdo")<<tr("CW - Kuracao")
   <<tr("CX - Kristnaskinsulo")<<tr("CY - Kipro")<<tr("CZ - \304\210e\304\245ujo");
 administranto.sxargu();
 montruInformo("bonvenon");
}
