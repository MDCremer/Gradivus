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
  if(informpeto.exec("SELECT nomo,valoro FROM agordoj;"))
  {while(informpeto.next())
   {QByteArray nomo=informpeto.value("nomo").toByteArray();
    QByteArray valoro=informpeto.value("valoro").toByteArray();
    if(nomo=="nomo")
     valoroj[AGORDO_NOMO]=valoro;
    if(nomo=="lingvo")
     valoroj[AGORDO_LINGVO]=valoro;
  }}
  else
  if(informpeto.lastError().isValid())
   QMessageBox::warning(0,"Eraro [015]!",informpeto.lastError().text());
  lingvaKvanto=0;
  if(informpeto.exec("SELECT mallongigo FROM lingvoj ORDER BY rango;"))
  {while(informpeto.next())
    lingvaRangoj[lingvaKvanto++]=akiruLingvaNombro(informpeto.value("mallongigo").toByteArray());
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(0,QObject::tr("Eraro [011]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(0,QObject::tr("Eraro [010]!"),datumbazo.lastError().text());
}
