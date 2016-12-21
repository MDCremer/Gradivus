#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "kodoselektado.h"

void tezauxro::priObjekto()
{kodoSelektado selektado(this,patraObjekto);
 if(selektado.exec()==QDialog::Accepted)
 {ui->objektoListo->clear();
  objekto=selektado.akiruKodo().toUtf8();
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT etno,nomo,lingvo FROM identigiloj WHERE uuid='"+objekto+"';"))
   {while(informpeto.next())
     ui->objektoListo->addItem(new QListWidgetItem(informpeto.value("etno").toByteArray()+": "+
       informpeto.value("nomo").toByteArray()+" ["+informpeto.value("lingvo").toByteArray()+"]"));
   }
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [108]!"),informpeto.lastError().text());
   datumbazo.close();
   ui->akceptu->setEnabled(true);
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [107]!"),datumbazo.lastError().text());
}}
