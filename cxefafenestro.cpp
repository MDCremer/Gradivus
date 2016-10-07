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
 etnoNomoj=QStringList()
   <<tr("AT: a\305\255stroj")
   <<tr("BE: belgoj")
   <<tr("BG: bulgaroj")
   <<tr("CA: kanadanoj")
   <<tr("CH: svisoj")
   <<tr("DE: germanoj")
   <<tr("ES: hispanoj")
   <<tr("FR: francoj")
   <<tr("GB: britoj")
   <<tr("GR: grekoj")
   <<tr("IT: italoj")
   <<tr("JP: japanoj")
   <<tr("RO: rumanuoj")
   <<tr("RU: rusoj")
   <<tr("SE: svedoj")
   <<tr("TR: turkoj")
   <<tr("US: usonanoj");
 administranto.sxargu();
 montruInformo("bonvenon");
}
