#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
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
 connect(ui->listo,&QListWidget::itemSelectionChanged,this,&kodoSelektado::priElektajxoSxangxo);
 connect(ui->apliku,&QPushButton::clicked,this,&kodoSelektado::priApliku);
 connect(ui->rezignu,&QPushButton::clicked,this,&kodoSelektado::priRezignu);
 connect(ui->devasEnhavi,&QCheckBox::toggled,this,&kodoSelektado::priDevasEnhavi);
 connect(ui->enhavo,&QLineEdit::editingFinished,this,&kodoSelektado::priKompletigitaEnigu);
 connect(ui->etnoLimigo,&QComboBox::currentTextChanged,this,&kodoSelektado::priKompletigitaEnigu);
 connect(ui->lingvoLimigo,&QComboBox::currentTextChanged,this,&kodoSelektado::priKompletigitaEnigu);
 connect(ui->limigiTipoj,&QComboBox::currentTextChanged,this,&kodoSelektado::priKompletigitaEnigu);
 sxargi();
}
