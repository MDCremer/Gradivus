#include <QFont>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "tezauxro.h"
#include "ui_tezauxro.h"

void tezauxro::sxargi()
{ui->rilatojListo->clear();
 QTreeWidgetItem *hiponimoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 QFont tiparo=hiponimoj->font(0);
 tiparo.setItalic(true);
 hiponimoj->setText(0,tr("hiponima"));
 hiponimoj->setFont(0,tiparo);
 QTreeWidgetItem *meronimoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 meronimoj->setText(0,tr("meronima"));
 meronimoj->setFont(0,tiparo);
 QTreeWidgetItem *disponebloj=new QTreeWidgetItem(ui->rilatojListo,3000);
 disponebloj->setText(0,tr("disponebla"));
 disponebloj->setFont(0,tiparo);
 QTreeWidgetItem *instrumentoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 instrumentoj->setText(0,tr("instrumenta"));
 instrumentoj->setFont(0,tiparo);
 QTreeWidgetItem *suprenirantoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 suprenirantoj->setText(0,tr("supreniranta"));
 suprenirantoj->setFont(0,tiparo);
 QStringList rilatoj,objektoj;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT rilato,objekto FROM semantikajrilatoj WHERE subjekto='"+ajxo+"';"))
  {while(informpeto.next())
   {rilatoj<<informpeto.value("rilato").toString();
    objektoj<<informpeto.value("objekto").toString();
  }}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [105]!"),informpeto.lastError().text());
  for(int indekso=0;indekso<objektoj.length();++indekso)
  {if(informpeto.exec("SELECT etno,nomo,mallongigo FROM identigiloj,lingvoj WHERE uuid='"+objektoj[indekso]+
     "' AND mallongigo=lingvo ORDER BY tipo,rango,nomo;"))
   {if(informpeto.first())
    {QTreeWidgetItem *ero=new QTreeWidgetItem(3500+rilatoj[indekso].toInt());
     ero->setText(0,informpeto.value("etno").toString()+": "+informpeto.value("nomo").toString()+" ["+
       informpeto.value("mallongigo").toString()+"]");
     ero->setToolTip(0,objektoj[indekso]);
     if(rilatoj[indekso]=="0")
      hiponimoj->addChild(ero);
     if(rilatoj[indekso]=="1")
      meronimoj->addChild(ero);
     if(rilatoj[indekso]=="2")
      disponebloj->addChild(ero);
     if(rilatoj[indekso]=="3")
      instrumentoj->addChild(ero);
     if(rilatoj[indekso]=="4")
      suprenirantoj->addChild(ero);
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [106]!"),informpeto.lastError().text());
  }
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [104]!"),datumbazo.lastError().text());
 hiponimoj->sortChildren(0,Qt::AscendingOrder);
 meronimoj->sortChildren(0,Qt::AscendingOrder);
 disponebloj->sortChildren(0,Qt::AscendingOrder);
 instrumentoj->sortChildren(0,Qt::AscendingOrder);
 suprenirantoj->sortChildren(0,Qt::AscendingOrder);
 ui->rilatojListo->expandAll();
}
