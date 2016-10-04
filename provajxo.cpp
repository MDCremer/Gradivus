#include "provajxo.h"
#include "ui_provajxo.h"
#include "hipertekstopagxo.h"

provajxo::provajxo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::provajxo)
{ui->setupUi(this);
 markilo=new htmlMarkilo(ui->kodo->document());
 connect(ui->abortu,&QToolButton::clicked,this,&provajxo::priAbortu);
 ui->vido->setPage(new hipertekstoPagxo());
 ui->malnovaDatumoj->setPage(new hipertekstoPagxo());
}
