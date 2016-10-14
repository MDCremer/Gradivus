#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "kodoselektado.h"
#include "ui_kodoselektado.h"

void kodoSelektado::sxargi()
{ui->listo->clear();
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  QString ordono("SELECT etno,nomo,lingvo,uuid FROM identigiloj");
  bool unua=true;
  if(ui->etnoLimigo->currentIndex()>0)
  {ordono.append(" WHERE etno='");
   ordono.append(ui->etnoLimigo->currentText().left(2));
   ordono.append("'");
   unua=false;
  }
  if(ui->devasEnhavi->isChecked()&&!ui->enhavo->text().isEmpty())
  {if(unua)
   {ordono.append(" WHERE nomo LIKE '%");
    unua=false;
   }
   else
    ordono.append(" AND nomo LIKE '%");
   ordono.append(ui->enhavo->text().replace("'","''"));
   ordono.append("%'");
  }
  if(ui->lingvoLimigo->currentIndex()>0)
  {if(unua)
   {ordono.append(" WHERE lingvo='");
    unua=false;
   }
   else
    ordono.append(" AND lingvo='");
   ordono.append(ui->lingvoLimigo->currentText().left(2));
   ordono.append("'");
  }
  if(ui->limigiTipoj->currentIndex()>0)
  {if(unua)
    ordono.append(" WHERE tipo<");
   else
    ordono.append(" AND tipo<");
   ordono.append(QString::number(6-ui->limigiTipoj->currentIndex()));
  }
  ordono.append(";");
  if(informpeto.exec(ordono))
  {while(informpeto.next())
   {QListWidgetItem *ero=new QListWidgetItem(informpeto.value("etno").toString()+": "+informpeto.value("nomo").toString()+
      " ["+informpeto.value("lingvo").toString()+"]");
    ero->setToolTip(informpeto.value("uuid").toString());
    ui->listo->addItem(ero);
  }}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [048]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [047]!"),datumbazo.lastError().text());
}
