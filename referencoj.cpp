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
 connect(ui->grasa,&QToolButton::clicked,this,&referencoj::priGrasa);
 connect(ui->kursiva,&QToolButton::clicked,this,&referencoj::priKursiva);
 connect(ui->substretika,&QToolButton::clicked,this,&referencoj::priSubstretika);
 connect(ui->superskribita,&QToolButton::clicked,this,&referencoj::priSuperskribita);
 connect(ui->suba,&QToolButton::clicked,this,&referencoj::priSuba);
 connect(ui->referenceita,&QToolButton::clicked,this,&referencoj::priReferenceita);
 connect(ui->minora,&QToolButton::clicked,this,&referencoj::priMinora);
 connect(ui->vakigu,&QToolButton::clicked,this,&referencoj::priVakigu);
 connect(ui->akceptu,&QPushButton::clicked,this,&referencoj::priAkceptu);
 for(int indekso=0;indekso<9;++indekso)
  enigojAktivigita[indekso]=false;
 sxargiAludoj();
}
