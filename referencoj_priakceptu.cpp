#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::priAkceptu()
{if(!ui->aludo->text().simplified().isEmpty())
 {if(!ui->teksto->toPlainText().trimmed().isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [020]!"),datumbazo.lastError().text());
  }
  else
   patraObjekto->spektakloMesagxon(tr("Malplena cita\304\265o estas neakceptebla!"));
 }
 else
  patraObjekto->spektakloMesagxon(tr("Malplena noto estas neakceptebla!"));
}
