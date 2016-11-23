#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "rikordoregistrilo.h"

void priskribo::priForigu()
{QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  QByteArray inverso("INSERT INTO priskriboj (uuid,lingvo,teksto,subskribo,stato) VALUES ('");
  inverso.append(ajxo);
  inverso.append("','");
  inverso.append(ui->lingvo->currentText().left(2).toUtf8());
  inverso.append("',");
  if(informpeto.exec("SELECT QUOTE(teksto),subskribo,stato FROM priskriboj WHERE uuid='"+ajxo+"' AND lingvo='"+
    ui->lingvo->currentText().left(2)+"';"))
  {if(informpeto.first())
   {inverso.append(informpeto.value("QUOTE(teksto)").toByteArray());
    inverso.append(",'");
    inverso.append(informpeto.value("subskribo").toByteArray().replace("'","''"));
    inverso.append("',");
    inverso.append(informpeto.value("stato").toByteArray());
    inverso.append(");");
  }}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [097]!"),informpeto.lastError().text());
  QByteArray ordono("DELETE FROM priskriboj WHERE uuid='");
  ordono.append(ajxo);
  ordono.append("' AND lingvo='");
  ordono.append(ui->lingvo->currentText().left(2).toUtf8());
  ordono.append("';");
  registrilo->komencu();
  registrilo->aldonu(inverso);
  registrilo->plenumu(&informpeto,ordono);
  registrilo->fermu();
  patraObjekto->spektakloMesagxon(tr("Priskribo estis forigita!"));
  datumbazo.close();
  ui->lingvo->setCurrentIndex(-1);
  ui->lingvo->setCurrentIndex(0);
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [096]!"),datumbazo.lastError().text());
}
