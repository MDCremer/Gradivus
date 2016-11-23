#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "kodoselektado.h"

void priskribo::priSelektado()
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
     QMessageBox::warning(this,tr("Eraro [086]!"),informpeto.lastError().text());
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [085]!"),datumbazo.lastError().text());
  ui->priskriboGrupo->setEnabled(true);
  ui->lingvo->setCurrentIndex(-1);
  ui->lingvo->setCurrentIndex(0);
  ui->teksto->setFocus();
}}
