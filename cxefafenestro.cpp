#include <QMainWindow>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "hipertekstopagxo.h"

cxefaFenestro::cxefaFenestro(QWidget *parent):QMainWindow(parent),ui(new Ui::cxefaFenestro)
{ui->setupUi(this);
 ui->informaMontro->setPage(new hipertekstoPagxo());
 montruInformo("bonvenon");
}
