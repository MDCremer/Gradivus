#include <QString>
#include <QWidget>
#include "kodoselektado.h"
#include "ui_kodoselektado.h"
#include "cxefafenestro.h"
#include "statikajdatumoj.h"

kodoSelektado::kodoSelektado(QWidget *gepatro,cxefaFenestro *avo):QDialog(gepatro),ui(new Ui::kodoSelektado)
{ui->setupUi(this);
 avaObjekto=avo;
 ui->lingvoLimigo->addItem(tr("neniu"));
 for(int indekso=0;indekso<avaObjekto->administranto.akiruLingvaKvanto();++indekso)
 {QString lingvoNomo=statikajDatumoj::lingvoNomoj[avaObjekto->administranto.akiruLingvaNombro(indekso)];
  ui->lingvoLimigo->addItem(lingvoNomo);
 }
 ui->etnoLimigo->addItem(tr("neniu"));
 ui->etnoLimigo->addItems(avaObjekto->etnoNomoj);
 sxargi();
}
