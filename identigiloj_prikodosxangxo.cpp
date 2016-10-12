#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::priKodoSxangxo(QString kodo)
{ui->alternativoj->clear();
 if(!kodo.isEmpty())
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT nomo,lingvo FROM identigiloj WHERE uuid='"+kodo+"';"))
   {while(informpeto.next())
     ui->alternativoj->addItem(new QListWidgetItem(informpeto.value("nomo").toByteArray()+" ["+
       informpeto.value("lingvo").toByteArray()+"]"));
   }
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [038]!"),informpeto.lastError().text());
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [037]!"),datumbazo.lastError().text());
}}
