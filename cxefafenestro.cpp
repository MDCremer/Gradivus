#include <QCheckBox>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"

cxefaFenestro::cxefaFenestro(QWidget *gepatro):QMainWindow(gepatro),ui(new Ui::cxefaFenestro)
{ui->setupUi(this);
 ui->informaMontro->setPage(new hipertekstoPagxo());
 connect(ui->datumojApogilo,&QPushButton::clicked,this,&cxefaFenestro::priDatumojApogilo);
 connect(ui->konfiguro,&QPushButton::clicked,this,&cxefaFenestro::priKonfiguro);
 connect(ui->referencoj,&QPushButton::clicked,this,&cxefaFenestro::priReferencoj);
 connect(ui->muta,&QCheckBox::stateChanged,this,&cxefaFenestro::priMuta);
 administranto.sxargu();
 montruInformo("bonvenon");
}
