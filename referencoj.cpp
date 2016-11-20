#include <QCheckBox>
#include <QListWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QToolButton>
#include <QtWebEngineWidgets>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "hipertekstopagxo.h"
#include "htmlmarkilo.h"
#include "rikordoregistrilo.h"

referencoj::referencoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::referencoj)
{ui->setupUi(this);
 ui->spektaklo->setPage(new hipertekstoPagxo(this,(cxefaFenestro *)gepatro));
 markilo=new htmlMarkilo(ui->teksto->document());
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->reiru,&QToolButton::clicked,this,&referencoj::priReiru);
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
 connect(ui->aludoj,&QListWidget::itemSelectionChanged,this,&referencoj::aludojElektajxoSxangxo);
 connect(ui->forigu,&QPushButton::clicked,this,&referencoj::priForigu);
 connect(ui->malfaru,&QPushButton::clicked,this,&referencoj::priMalfaru);
 connect(ui->kontribui,&QCheckBox::toggled,this,&referencoj::priKontribui);
 for(int indekso=0;indekso<9;++indekso)
  enigojAktivigita[indekso]=false;
 sxargiAludoj();
}
