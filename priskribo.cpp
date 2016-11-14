#include <QDialog>
#include <QPushButton>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"
#include "statikajdatumoj.h"

priskribo::priskribo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::priskribo)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 for(int indekso=0;indekso<patraObjekto->administranto.akiruLingvaKvanto();++indekso)
  ui->lingvo->addItem(statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)]);
 connect(ui->selektado,&QPushButton::clicked,this,&priskribo::priSelektado);
}
