#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::sxargiAludoj()
{QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT aludo FROM literaturoj;"))
  {while(informpeto.next())
    ui->aludoj->addItem(new QListWidgetItem(informpeto.value("aludo").toByteArray()));
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [019]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [018]!"),datumbazo.lastError().text());
}
