#include <QByteArray>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

void fontoj::priForigu()
{QList<QListWidgetItem *> elektajxoj=ui->listo->selectedItems();
 if(elektajxoj.length()>0)
 {QByteArray inverso,ordono;
  ordono.append("DELETE FROM fontoj WHERE uuid='");
  ordono.append(ajxo);
  ordono.append("' AND aludo='");
  ordono.append(aktualaFonto);
  ordono.append("';");
  inverso.append("INSERT INTO fontoj (uuid,aludo,");
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT literaturo,QUOTE(pagxo),subskribo,stato FROM fontoj WHERE uuid='"+ajxo+"' AND aludo='"+
     aktualaFonto+"';"))
   {if(informpeto.first())
    {if(!informpeto.value("literaturo").isNull())
      inverso.append("literaturo,");
     if(!informpeto.value("QUOTE(pagxo)").isNull())
      inverso.append("pagxo,");
     inverso.append("subskribo,stato) VALUES ('");
     inverso.append(ajxo);
     inverso.append("','");
     inverso.append(aktualaFonto);
     inverso.append("',");
     if(!informpeto.value("literaturo").isNull())
     {inverso.append("'");
      inverso.append(informpeto.value("literaturo").toByteArray().replace("'","''"));
      inverso.append("',");
     }
     if(!informpeto.value("QUOTE(pagxo)").isNull())
     {inverso.append(informpeto.value("QUOTE(pagxo)").toByteArray());
      inverso.append(",");
     }
     inverso.append("'");
     inverso.append(informpeto.value("subskribo").toByteArray());
     inverso.append("',");
     inverso.append(informpeto.value("stato").toByteArray());
     inverso.append(");");
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [073]!"),informpeto.lastError().text());
   registrilo->komencu();
   registrilo->aldonu(inverso);
   registrilo->plenumu(&informpeto,ordono);
   registrilo->fermu();
   patraObjekto->spektakloMesagxon(tr("Fonto estis forigita!"));
   datumbazo.close();
   sxargi();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [072]!"),datumbazo.lastError().text());
}}
