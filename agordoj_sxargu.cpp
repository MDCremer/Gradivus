#include <QByteArray>
#include <QDir>
#include <QFile>
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
    if(nomo=="pasvorto")
     valoroj[AGORDO_PASVORTO]=valoro;
    if(nomo=="transdono adreso")
     valoroj[AGORDO_TRANSDONOADRESO]=valoro;
    if(nomo=="vortaro")
     valoroj[AGORDO_VORTARO]=valoro;
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
 valoroj[AGORDO_STILO]="<!doctype html>\n<html>\n<head>\n<meta charset='utf-8'>\n";
 QFile stilo(QDir::homePath()+"/Gradivus/dokumentoj/rimedoj/stilo.css");
 if(stilo.open(QIODevice::ReadOnly|QIODevice::Text))
 {valoroj[AGORDO_STILO].append("<style>\n");
  valoroj[AGORDO_STILO].append(stilo.readAll());
  valoroj[AGORDO_STILO].append("\n</style>\n");
  stilo.close();
}}
