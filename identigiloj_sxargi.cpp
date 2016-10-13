#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::sxargi()
{ui->identigilojListo->clear();
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  QString ordono("SELECT etno,nomo,lingvo FROM identigiloj");
  if(ui->lingvoLimigo->currentIndex()>0)
  {ordono.append(" WHERE lingvo='");
   ordono.append(ui->lingvoLimigo->currentText().left(2));
   ordono.append("'");
  }
  if(ui->limigiTipoj->currentIndex()>0)
  {if(ui->lingvoLimigo->currentIndex()>0)
    ordono.append(" AND ");
   else
    ordono.append(" WHERE ");
   ordono.append("tipo<");
   ordono.append(QString::number(6-ui->limigiTipoj->currentIndex()));
  }
  ordono.append(";");
  if(informpeto.exec(ordono))
  {while(informpeto.next())
    ui->identigilojListo->addItem(new QListWidgetItem(informpeto.value("etno").toString()+": "+
      informpeto.value("nomo").toString()+(ui->lingvoLimigo->currentIndex()>0?"":" ["+informpeto.value("lingvo").toString()+
      "]")));
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [043]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [042]!"),datumbazo.lastError().text());
}
