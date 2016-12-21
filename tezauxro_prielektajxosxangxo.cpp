#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTreeWidgetItem>
#include "tezauxro.h"
#include "ui_tezauxro.h"

void tezauxro::priElektajxoSxangxo(QTreeWidgetItem *aktualo)
{if(aktualo!=0&&aktualo->type()>3000)
 {ui->forigu->setEnabled(true);
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT aludo,subskribo,stato FROM semantikajrilatoj WHERE subjekto='"+ajxo+"' AND rilato="+
     QByteArray::number(aktualo->type()-3500)+" AND objekto='"+aktualo->toolTip(0)+"';"))
   {if(informpeto.first())
    {if(informpeto.value("aludo").isNull())
      ui->fonto->setText("---");
     else
      ui->fonto->setText(informpeto.value("aludo").toString());
     ui->subskribo->setText(informpeto.value("subskribo").toString());
     QDateTime tempo;
     tempo.setTime_t(informpeto.value("stato").toUInt());
     ui->stato->setText(tempo.toString(Qt::SystemLocaleLongDate));
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [112]!"),informpeto.lastError().text());
   ui->rilato->setCurrentIndex(aktualo->type()-3500);
   if(aktualo->toolTip(0).toUtf8()!=objekto)
   {objekto=aktualo->toolTip(0).toUtf8();
    ui->akceptu->setEnabled(true);
    ui->objektoListo->clear();
    if(informpeto.exec("SELECT etno,nomo,lingvo FROM identigiloj WHERE uuid='"+objekto+"';"))
    {while(informpeto.next())
      ui->objektoListo->addItem(new QListWidgetItem(informpeto.value("etno").toByteArray()+": "+
        informpeto.value("nomo").toByteArray()+" ["+informpeto.value("lingvo").toByteArray()+"]"));
    }
    else
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [113]!"),informpeto.lastError().text());
   }
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [111]!"),datumbazo.lastError().text());
 }
 else
 {ui->forigu->setEnabled(false);
  ui->subskribo->clear();
  ui->stato->clear();
}}
