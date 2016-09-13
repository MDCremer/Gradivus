#include <QByteArray>
#include <QMessageBox>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include "agordoj.h"
#include "statikajdatumoj.h"

void agordoj::sxargu()
{QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  lingvaKvanto=0;
  if(informpeto.exec("SELECT mallongigo FROM lingvoj ORDER BY rango;"))
  {while(informpeto.next())
   {QByteArray mallongigo=informpeto.value("mallongigo").toByteArray();
    for(int indekso=0;indekso<LINGVAKVANTO;++indekso)
    {if(statikajDatumoj::lingvoNomoj[indekso].startsWith(mallongigo))
     {lingvaRangoj[lingvaKvanto++]=indekso;
      indekso=LINGVAKVANTO;
  }}}}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(0,QObject::tr("Eraro [011]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(0,QObject::tr("Eraro [010]!"),datumbazo.lastError().text());
}
