#include <QByteArray>
#include <QMessageBox>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStack>
#include "rikordoregistrilo.h"

bool rikordoRegistrilo::malfaru()
{bool sukceso=false;
 if(!aktiva)
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery registrilo;
   QByteArray ordono;
   bool dauxrigi=(stako.top()=="BEGIN;");
   while(dauxrigi)
   {ordono=stako.pop();
    if(registrilo.exec(ordono))
    {if(ordono=="COMMIT;")
      dauxrigi=false;
    }
    else
    {if(registrilo.lastError().isValid())
      QMessageBox::warning(malfaroButono,QObject::tr("Eraro [014]!"),registrilo.lastError().text());
     dauxrigi=false;
   }}
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(malfaroButono,QObject::tr("Eraro [013]!"),datumbazo.lastError().text());
 }
 return sukceso;
}
