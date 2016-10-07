#include <QComboBox>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "statikajdatumoj.h"

identigiloj::identigiloj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::identigiloj)
{ui->setupUi(this);
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 ui->lingvoLimigo->addItem(tr("neniu"));
 for(int indekso=0;indekso<patraObjekto->administranto.akiruLingvaKvanto();++indekso)
 {QString lingvoNomo=statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)];
  ui->lingvoLimigo->addItem(lingvoNomo);
  ui->lingvo->addItem(lingvoNomo);
 }
 ui->etno->addItems(patraObjekto->etnoNomoj);
}
