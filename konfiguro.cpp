#include <QComboBox>
#include <QList>
#include <QListWidget>
#include <QLocale>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QToolButton>
#include "konfiguro.h"
#include "ui_konfiguro.h"
#include "agordoj.h"
#include "cxefafenestro.h"
#include "statikajdatumoj.h"

konfiguro::konfiguro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::konfiguro)
{ui->setupUi(this);
 registrilo=new rikordoRegistrilo(ui->malfaru);
 connect(ui->abortu,&QPushButton::clicked,this,&konfiguro::priAbortu);
 connect(ui->lingvoj,&QListWidget::currentItemChanged,this,&konfiguro::lingvoEtikedoSxangxo);
 connect(ui->supro,&QToolButton::clicked,this,&konfiguro::priSupro);
 connect(ui->supren,&QToolButton::clicked,this,&konfiguro::priSupren);
 connect(ui->malsupren,&QToolButton::clicked,this,&konfiguro::priMalsupren);
 connect(ui->malsupro,&QToolButton::clicked,this,&konfiguro::priMalsupro);
 QList<QLocale> cxiujKulturoj=QLocale::matchingLocales(QLocale::AnyLanguage,QLocale::AnyScript,QLocale::AnyCountry);
 QStringList lingvoKodoj;
 for(int indekso=0;indekso<cxiujKulturoj.length();++indekso)
  lingvoKodoj.append(cxiujKulturoj[indekso].name());
 lingvoKodoj.sort();
 ui->kulturo->addItem(tr("loka\u0135aro"));
 for(int indekso=0;indekso<lingvoKodoj.length();++indekso)
  if(ui->kulturo->findText(lingvoKodoj[indekso])==-1)
   ui->kulturo->addItem(lingvoKodoj[indekso]);
 lingvaKvanto=((cxefaFenestro *)gepatro)->administranto.akiruLingvaKvanto();
 ui->inicialoj->setText(((cxefaFenestro *)gepatro)->administranto.akiruValoro(AGORDO_NOMO));
 if(((cxefaFenestro *)gepatro)->administranto.akiruValoro(AGORDO_LINGVO).isEmpty())
  ui->kulturo->setCurrentIndex(0);
 else
  ui->kulturo->setCurrentIndex(ui->kulturo->findText(((cxefaFenestro *)gepatro)->administranto.akiruValoro(AGORDO_LINGVO)));
 for(int indekso=0;indekso<lingvaKvanto;++indekso)
  ui->lingvoj->addItem(statikajDatumoj::lingvoNomoj[((cxefaFenestro *)gepatro)->administranto.akiruLingvaNombro(indekso)]);
}
