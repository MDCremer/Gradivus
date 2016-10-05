#include "provajxo.h"
#include "ui_provajxo.h"
#include "hipertekstopagxo.h"

provajxo::provajxo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::provajxo)
{ui->setupUi(this);
 markilo=new htmlMarkilo(ui->kodo->document());
 connect(ui->reiru,&QToolButton::clicked,this,&provajxo::priReiru);
 ui->vido->setPage(new hipertekstoPagxo());
 ui->malnovaDatumoj->setPage(new hipertekstoPagxo());
}
