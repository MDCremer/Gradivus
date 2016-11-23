#include <QDialog>
#include <QPushButton>
#include <QTabWidget>
#include <QToolButton>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"
#include "htmlmarkilo.h"
#include "rikordoregistrilo.h"
#include "statikajdatumoj.h"

priskribo::priskribo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::priskribo)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 markilo=new htmlMarkilo(ui->teksto->document());
 registrilo=new rikordoRegistrilo(ui->malfaru);
 ui->montru->setPage(new hipertekstoPagxo(this,patraObjekto));
 for(int indekso=0;indekso<patraObjekto->administranto.akiruLingvaKvanto();++indekso)
  ui->lingvo->addItem(statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)]);
 for(int indekso=0;indekso<36;++indekso)
  enigojAktivigita[indekso]=false;
 connect(ui->selektado,&QPushButton::clicked,this,&priskribo::priSelektado);
 connect(ui->reiru,&QToolButton::clicked,this,&priskribo::priReiru);
 connect(ui->kontribui,&QCheckBox::toggled,this,&priskribo::priKontribui);
 connect(ui->a,&QToolButton::clicked,this,&priskribo::priReferenceita);
 connect(ui->cite,&QToolButton::clicked,this,&priskribo::priCitajxo);
 connect(ui->img,&QToolButton::clicked,this,&priskribo::priBildo);
 connect(ui->tekstoEnigi,&QTabWidget::currentChanged,this,&priskribo::pagxoSxangxo);
 connect(ui->fonto,&QToolButton::clicked,this,&priskribo::priFonto);
 connect(ui->h1,&QToolButton::clicked,this,&priskribo::priTitoloUnua);
 connect(ui->h2,&QToolButton::clicked,this,&priskribo::priTitoloDua);
 connect(ui->h3,&QToolButton::clicked,this,&priskribo::priTitoloTria);
 connect(ui->h4,&QToolButton::clicked,this,&priskribo::priTitoloKvara);
 connect(ui->h5,&QToolButton::clicked,this,&priskribo::priTitoloKvina);
 connect(ui->h6,&QToolButton::clicked,this,&priskribo::priTitoloSesa);
}
