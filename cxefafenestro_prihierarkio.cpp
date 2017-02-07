#include <QMessageBox>
#include <QProgressDialog>
#include <QRegExp>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include "cxefafenestro.h"

void cxefaFenestro::priHierarkio()
{QStringList konceptoj;
 int forigoj=0;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT DISTINCT subjekto FROM semantikajrilatoj WHERE rilato=0;"))
  {while(informpeto.next())
    konceptoj.append(informpeto.value("subjekto").toString());
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [123]!"),informpeto.lastError().text());
  QProgressDialog progreso(tr("Hierarki"),tr("Abortu"),0,konceptoj.length(),this);
  int pasxo=0;
  foreach(QString koncepto,konceptoj)
  {QStringList objektoj;
   if(informpeto.exec(QString("SELECT objekto FROM semantikajrilatoj WHERE rilato=0 AND subjekto='%1';").arg(koncepto)))
   {while(informpeto.next())
     objektoj.append(informpeto.value("objekto").toString());
   }
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [124]!"),informpeto.lastError().text());
   QString forigo=testiRilatoj(&objektoj,&objektoj,&informpeto);
   while(!forigo.isEmpty())
   {if(!informpeto.exec(QString("DELETE FROM semantikajrilatoj WHERE rilato=0 AND subjekto='%1' AND objekto='%2';").arg(koncepto).arg(forigo)))
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [125]!"),informpeto.lastError().text());
    objektoj.removeAt(objektoj.indexOf(QRegExp(forigo)));
    ++forigoj;
    forigo=testiRilatoj(&objektoj,&objektoj,&informpeto);
   }
   progreso.setValue(pasxo++);
   if(progreso.wasCanceled())
    break;
  }
  progreso.setValue(konceptoj.length());
  datumbazo.close();
  spektakloMesagxon(tr("Forigitaj %1 semantikajn rilatojn!").arg(forigoj));
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [122]!"),datumbazo.lastError().text());
}
