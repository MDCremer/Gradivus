#include <QMainWindow>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "hipertekstopagxo.h"

cxefaFenestro::cxefaFenestro(QWidget *parent):QMainWindow(parent),ui(new Ui::cxefaFenestro)
{ui->setupUi(this);
 ui->informaMontro->setPage(new hipertekstoPagxo());
 connect(ui->datumojApogilo,&QPushButton::clicked,this,&cxefaFenestro::priDatumojApogilo);
 connect(ui->muta,&QCheckBox::stateChanged,this,&cxefaFenestro::priMuta);
 montruInformo("bonvenon");
}
