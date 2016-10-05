#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>
#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"

void datumojRestauxro::priPlenumu()
{QByteArray ordonoj=ui->ordono->toPlainText().simplified().toUtf8();
 bool dauxrigu=true;
 int nombro=0;
 if(!ordonoj.isEmpty())
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery registrilo;
   QByteArray instrukcio;
   QTextStream enigo(&ordonoj);
   while(dauxrigu&&!enigo.atEnd())
   {QByteArray linio=enigo.readLine().toUtf8();
    if(linio.endsWith("\n"))
     linio.truncate(linio.length()-QByteArray("\n").length());
    if(!linio.isEmpty()&&!linio.startsWith("--"))
    {if(instrukcio.length()>0)
      instrukcio.append(" ");
     instrukcio.append(linio);
     if(instrukcio.endsWith(";"))
     {if(registrilo.exec(instrukcio))
      {instrukcio.clear();
       ++nombro;
      }
      else
      {if(registrilo.lastError().isValid())
        QMessageBox::warning(this,tr("Eraro [030]!"),registrilo.lastError().text());
       dauxrigu=false;
   }}}}
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [029]!"),datumbazo.lastError().text());
  ui->ordono->clear();
  patraObjekto->spektakloMesagxon(tr("%n instrukcioj procesis.","",nombro));
 }
 else
  patraObjekto->spektakloMesagxon(tr("Ekzistas nenio procesi."));
}
