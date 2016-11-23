#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "priskribo.h"
#include "ui_priskribo.h"

void priskribo::priLingvo(QString lingvo)
{ui->tekstoEnigi->setCurrentIndex(0);
 bildoj.clear();
 if(!lingvo.isEmpty())
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT teksto,subskribo,stato FROM priskriboj WHERE uuid='"+ajxo+"' AND lingvo='"+lingvo.left(2)+"';"))
   {if(informpeto.first())
    {QString teksto=QString(qUncompress(informpeto.value("teksto").toByteArray()));
     int indekso=teksto.indexOf("src=");
     while(indekso>-1)
     {int starto=teksto.indexOf("\"",indekso);
      if(starto>-1)
      {int fino=teksto.indexOf("\"",starto+1);
       if(fino>-1)
       {QString bildo=teksto.mid(starto+1,fino-(starto+1));
        teksto.replace(bildo,"\342\234\202"+QString::number(bildoj.count())+"\360\237\223\267");
        bildoj<<bildo.toUtf8();
      }}
      indekso=teksto.indexOf("src=",++indekso);
     }
     ui->teksto->setPlainText(teksto);
     ui->subskribo->setText(informpeto.value("subskribo").toString());
     QDateTime tempo;
     tempo.setTime_t(informpeto.value("stato").toUInt());
     ui->stato->setText(tempo.toString(Qt::SystemLocaleLongDate));
     ui->forigu->setEnabled(true);
    }
    else
    {ui->teksto->clear();
     ui->subskribo->clear();
     ui->stato->clear();
     ui->forigu->setEnabled(false);
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [095]!"),informpeto.lastError().text());
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [094]!"),datumbazo.lastError().text());
 }
 else
 {ui->teksto->clear();
  ui->subskribo->clear();
  ui->stato->clear();
  ui->forigu->setEnabled(false);
}}
