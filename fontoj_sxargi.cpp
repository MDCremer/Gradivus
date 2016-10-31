#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "fontoj.h"
#include "ui_fontoj.h"

void fontoj::sxargi()
{ui->listo->clear();
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT aludo FROM fontoj WHERE uuid='"+ajxo+"';"))
  {while(informpeto.next())
    ui->listo->addItem(new QListWidgetItem(informpeto.value("aludo").toString()));
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [066]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [065]!"),datumbazo.lastError().text());
}
