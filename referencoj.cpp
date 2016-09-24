#include <QTabWidget>
#include <QToolButton>
#include <QtWebEngineWidgets>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "hipertekstopagxo.h"
#include "rikordoregistrilo.h"

referencoj::referencoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::referencoj)
{ui->setupUi(this);
 ui->spektaklo->setPage(new hipertekstoPagxo());
 markilo=new htmlMarkilo(ui->teksto->document());
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->abortu,&QToolButton::clicked,this,&referencoj::priAbortu);
 connect(ui->referencoEnigi,&QTabWidget::currentChanged,this,&referencoj::referencoEnigiSxangxo);
 connect(ui->citajxo,&QToolButton::clicked,this,&referencoj::priCitajxo);
 connect(ui->forta,&QToolButton::clicked,this,&referencoj::priForta);
 connect(ui->vakigu,&QToolButton::clicked,this,&referencoj::priVakigu);
 for(int indekso=0;indekso<9;++indekso)
  enigojAktivigita[indekso]=false;
 sxargiAludoj();
}
