#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "cxefafenestro.h"

void referencoj::priForigu()
{QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  int rilatoj=0;
  if(informpeto.exec("SELECT COUNT(*) FROM identigiloj WHERE literaturo='"+faktaAludo.replace("'","''")+"';"))
  {if(informpeto.first())
    rilatoj+=informpeto.value("COUNT(*)").toInt();
   else
    if(informpeto.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [025]!"),informpeto.lastError().text());
  }
  if(rilatoj>0)
   patraObjekto->spektakloMesagxon(tr("\304\234i trovi\304\235as %1 referencoj al tiu cita\304\265o!").arg(rilatoj));
  else
  {QByteArray html,subskribo;
   qlonglong stato=0;
   if(informpeto.exec("SELECT QUOTE(html),subskribo,stato FROM literaturoj WHERE aludo='"+faktaAludo.replace("'","''")+
     "';"))
   {if(informpeto.first())
    {html=informpeto.value("QUOTE(html)").toByteArray();
     subskribo=informpeto.value("subskribo").toByteArray();
     stato=informpeto.value("stato").toLongLong();
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [026]!"),informpeto.lastError().text());
   QByteArray inverso("INSERT INTO literaturoj (aludo,html,subskribo,stato) VALUES ('"+faktaAludo.replace("'","''"));
   inverso.append("',"+html+",'"+subskribo+"',"+QString::number(stato).toUtf8()+");");
   QByteArray ordono("DELETE FROM literaturoj WHERE aludo='"+faktaAludo.replace("'","''")+"';");
   registrilo->komencu();
   registrilo->aldonu(inverso);
   registrilo->plenumu(&informpeto,ordono);
   registrilo->fermu();
   patraObjekto->spektakloMesagxon(tr("Cita\304\265o estis forigita!"));
   sxargiAludoj();
  }
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [024]!"),datumbazo.lastError().text());
}
