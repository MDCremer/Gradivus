#include <QComboBox>
#include <QPushButton>
#include <QToolButton>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "statikajdatumoj.h"

identigiloj::identigiloj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::identigiloj)
{ui->setupUi(this);
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->reiru,&QToolButton::clicked,this,&identigiloj::priReiru);
 connect(ui->identigilo,&QPushButton::clicked,this,&identigiloj::priObjektoKodo);
 connect(ui->fonto,&QPushButton::clicked,this,&identigiloj::priFonto);
 ui->lingvoLimigo->addItem(tr("neniu"));
 for(int indekso=0;indekso<patraObjekto->administranto.akiruLingvaKvanto();++indekso)
 {QString lingvoNomo=statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)];
  ui->lingvoLimigo->addItem(lingvoNomo);
  ui->lingvo->addItem(lingvoNomo);
 }
 ui->etno->addItems(patraObjekto->etnoNomoj);
}
