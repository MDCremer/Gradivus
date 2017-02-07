#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include "cxefafenestro.h"

QString cxefaFenestro::testiRilatoj(QStringList *celoj, QStringList *objektoj, QSqlQuery *informpeto)
{foreach(QString objekto,*objektoj)
 {QStringList enkondukoj;
  if(informpeto->exec(QString("SELECT objekto FROM semantikajrilatoj WHERE rilato=0 AND subjekto='%1';").arg(objekto)))
  {while(informpeto->next())
    enkondukoj.append(informpeto->value("objekto").toString());
  }
  else
   if(informpeto->lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [126]!"),informpeto->lastError().text());
  foreach(QString enkonduko,enkondukoj)
   if(celoj->contains(enkonduko))
    return enkonduko;
  QString forigo=testiRilatoj(celoj,&enkondukoj,informpeto);
  if(!forigo.isEmpty())
   return forigo;
 }
 return QString();
}
