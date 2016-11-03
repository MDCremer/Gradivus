#include <QByteArray>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

void identigiloj::priForigu()
{QList<QListWidgetItem *> elektajxoj=ui->identigilojListo->selectedItems();
 if(elektajxoj.length()>0)
 {QListWidgetItem *aktualo=elektajxoj.first();
  QString etno=aktualo->text().left(2);
  QString nomo,lingvo;
  QByteArray inverso("INSERT INTO identigiloj (etno,nomo,lingvo,tipo,");
  if(ui->lingvoLimigo->currentIndex()>0)
  {nomo=aktualo->text().right(aktualo->text().length()-4).replace("'","''");
   lingvo=ui->lingvoLimigo->currentText().left(2);
  }
  else
  {nomo=aktualo->text().mid(4,aktualo->text().length()-9).replace("'","''");
   lingvo=aktualo->text().right(3).left(2);
  }
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   if(informpeto.exec("SELECT tipo,literaturo,QUOTE(pagxo),uuid,subskribo,stato FROM identigiloj WHERE etno='"+etno+
     "' AND nomo='"+nomo+"' AND lingvo='"+lingvo+"';"))
   {if(informpeto.first())
    {if(!informpeto.value("literaturo").isNull())
      inverso.append("literaturo,");
     if(!informpeto.value("QUOTE(pagxo)").isNull())
      inverso.append("pagxo,");
     inverso.append("uuid,subskribo,stato) VALUES ('");
     inverso.append(etno);
     inverso.append("','");
     inverso.append(nomo);
     inverso.append("','");
     inverso.append(lingvo);
     inverso.append("',");
     inverso.append(informpeto.value("tipo").toByteArray());
     inverso.append(",");
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
     inverso.append(informpeto.value("uuid").toByteArray());
     inverso.append("','");
     inverso.append(informpeto.value("subskribo").toByteArray());
     inverso.append("',");
     inverso.append(informpeto.value("stato").toByteArray());
     inverso.append(");");
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [050]!"),informpeto.lastError().text());
   QByteArray ordono("DELETE FROM identigiloj WHERE  etno='"+etno.toUtf8()+"' AND nomo='"+nomo.toUtf8()+"' AND lingvo='"+
     lingvo.toUtf8()+"';");
   registrilo->komencu();
   registrilo->aldonu(inverso);
   registrilo->plenumu(&informpeto,ordono);
   registrilo->fermu();
   patraObjekto->spektakloMesagxon(tr("Identigilo estis forigita!"));
   datumbazo.close();
   sxargi();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [049]!"),datumbazo.lastError().text());
}}
