#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "kodoselektado.h"

void tezauxro::priSelektado()
{kodoSelektado selektado(this,patraObjekto);
 if(selektado.exec()==QDialog::Accepted)
 {ui->identigiloj->clear();
  ajxo=selektado.akiruKodo().toUtf8();
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
     QMessageBox::warning(this,tr("Eraro [103]!"),informpeto.lastError().text());
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [102]!"),datumbazo.lastError().text());
//  sxargi();
  ui->aliro->setCurrentIndex(1);
}}
