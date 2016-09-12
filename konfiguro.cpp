#include <QByteArray>
#include <QList>
#include <QListWidget>
#include <QLocale>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QToolButton>
#include "konfiguro.h"
#include "ui_konfiguro.h"
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
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT mallongigo FROM lingvoj ORDER BY rango;"))
  {QByteArray mallongigo=informpeto.value("mallongigo").toByteArray();
   for(int indekso=0;indekso<LINGVAKVANTO;++indekso)
    if(statikajDatumoj::lingvoNomoj[indekso].startsWith(mallongigo))
     ui->lingvoj->addItem(statikajDatumoj::lingvoNomoj[indekso]);
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [011]!"),informpeto.lastError().text());
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [010]!"),datumbazo.lastError().text());
}
