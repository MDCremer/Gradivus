#include "provajxo.h"
#include "ui_provajxo.h"
#include "hipertekstopagxo.h"
#include "cxefafenestro.h"

provajxo::provajxo(QWidget *gepatro,cxefaFenestro *avo):QDialog(gepatro),ui(new Ui::provajxo)
{ui->setupUi(this);
 markilo=new htmlMarkilo(ui->kodo->document());
 connect(ui->reiru,&QToolButton::clicked,this,&provajxo::priReiru);
 ui->vido->setPage(new hipertekstoPagxo(gepatro,avo));
 ui->malnovaDatumoj->setPage(new hipertekstoPagxo(gepatro,avo));
}
