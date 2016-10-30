#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "fontoj.h"
#include "ui_fontoj.h"
#include "kodoselektado.h"

void fontoj::priSelektado()
{kodoSelektado selektado(this,patraObjekto);
 if(selektado.exec()==QDialog::Accepted)
 {ajxo=selektado.akiruKodo().toUtf8();
  ui->fonto->setEnabled(true);
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT etno,nomo,lingvo FROM identigiloj WHERE uuid='"+ajxo+"';"))
   {while(informpeto.next())
     ui->identigiloj->addItem(new QListWidgetItem(informpeto.value("etno").toByteArray()+": "+
       informpeto.value("nomo").toByteArray()+" ["+informpeto.value("lingvo").toByteArray()+"]"));
   }
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [064]!"),informpeto.lastError().text());
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [063]!"),datumbazo.lastError().text());
}}
