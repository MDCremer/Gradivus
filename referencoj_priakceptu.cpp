#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::priAkceptu()
{if(!ui->aludo->text().simplified().isEmpty())
 {if(!ui->teksto->toPlainText().simplified().isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    QByteArray malnovaHtml,malnovaSubskribo;
    uint malnovaStato;
    bool havebla=false;
    if(informpeto.exec("SELECT html,subskribo,stato FROM literaturoj WHERE aludo='"+
      ui->aludo->text().simplified().replace("'","''")+"';"))
    {if(informpeto.first())
     {havebla=true;
      malnovaHtml=qUncompress(informpeto.value("html").toByteArray());
      malnovaSubskribo=informpeto.value("subskribo").toByteArray();
      malnovaStato=informpeto.value("stato").toUInt();
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::critical(this,tr("Eraro [021]!"),informpeto.lastError().text());
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
