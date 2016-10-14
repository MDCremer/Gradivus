#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QToolButton>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "statikajdatumoj.h"

identigiloj::identigiloj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::identigiloj)
{ui->setupUi(this);
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->reiru,&QToolButton::clicked,this,&identigiloj::priReiru);
 connect(ui->identigilo,&QPushButton::clicked,this,&identigiloj::priObjektoKodo);
 connect(ui->fonto,&QPushButton::clicked,this,&identigiloj::priFonto);
 connect(ui->kontribui,&QCheckBox::toggled,this,&identigiloj::priKontribui);
 connect(ui->akceptu,&QPushButton::clicked,this,&identigiloj::priAkceptu);
 connect(ui->objektoKodo,&QLineEdit::textChanged,this,&identigiloj::priKodoSxangxo);
 connect(ui->vakigu,&QPushButton::clicked,this,&identigiloj::priVakigu);
 connect(ui->lingvoLimigo,&QComboBox::currentTextChanged,this,&identigiloj::priLingvoLimigo);
 connect(ui->limigiTipoj,&QComboBox::currentTextChanged,this,&identigiloj::priLingvoLimigo);
 connect(ui->identigilojListo,&QListWidget::itemSelectionChanged,this,&identigiloj::priElektajxoSxangxo);
 connect(ui->historiaListo,&QComboBox::currentTextChanged,this,&identigiloj::priHistoriaListo);
 connect(ui->novaKodo,&QToolButton::clicked,this,&identigiloj::priNovaKodo);
 ui->lingvoLimigo->addItem(tr("neniu"));
 for(int indekso=0;indekso<patraObjekto->administranto.akiruLingvaKvanto();++indekso)
 {QString lingvoNomo=statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)];
  ui->lingvoLimigo->addItem(lingvoNomo);
  ui->lingvo->addItem(lingvoNomo);
 }
 ui->etno->addItems(patraObjekto->etnoNomoj);
}
