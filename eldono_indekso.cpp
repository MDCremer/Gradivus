#include <QByteArray>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include "eldono.h"
#include "cxefafenestro.h"
#include "agordoj.h"

QByteArray eldono::indekso(QSqlQuery *informpeto,cxefaFenestro *patraObjekto)
{QByteArray tablo("<table id='indekso'>\n<thead>\n<tr>\n<th class='etno_kolumno'>");
 tablo.append(QObject::tr("Etno"));
 tablo.append("</th>\n<th class='nomo_kolumno'>");
 tablo.append(QObject::tr("Nomo"));
 tablo.append("</th>\n<th class='lingvo_kolumno'>");
 tablo.append(QObject::tr("Lingvo"));
 tablo.append("</th>\n<th class='fonto_kolumno'>");
 tablo.append(QObject::tr("Fonto"));
 tablo.append("</th>\n<th class='sinonimoj_kolumno'>");
 tablo.append(QObject::tr("Sinonimoj"));
 tablo.append("</th></tr>\n</thead>\n<tbody>\n");
 QListWidget *listo=new QListWidget();
 listo->setSortingEnabled(true);
 if(informpeto->exec("SELECT etno,nomo,lingvo FROM identigiloj;"))
 {while(informpeto->next())
   listo->addItem(new QListWidgetItem(informpeto->value("etno").toString()+informpeto->value("nomo").toString()+
     informpeto->value("lingvo").toString()));
 }
 else
  if(informpeto->lastError().isValid())
   QMessageBox::warning(patraObjekto,QObject::tr("Eraro [055]!"),informpeto->lastError().text());
 while(listo->count()>0)
 {QListWidgetItem *aktualo=listo->takeItem(0);
  QByteArray etno=aktualo->text().left(2).toUtf8();
  QByteArray nomo=aktualo->text().mid(2,aktualo->text().length()-4).toUtf8();
  QByteArray lingvo=aktualo->text().right(2).toUtf8();
  QByteArray literaturo,pagxo,uuid;
  int tipo=0;
  if(informpeto->exec("SELECT tipo,literaturo,pagxo,uuid FROM identigiloj WHERE etno='"+etno+"' AND nomo='"+
    nomo.replace("'","''")+"' AND lingvo='"+lingvo+"';"))
  {if(informpeto->first())
   {tipo=informpeto->value("tipo").toInt();
    if(!informpeto->value("literaturo").isNull())
     literaturo=informpeto->value("literaturo").toByteArray();
    if(!informpeto->value("pagxo").isNull())
     pagxo=qUncompress(informpeto->value("pagxo").toByteArray());
    uuid=informpeto->value("uuid").toByteArray();
  }}
  else
   if(informpeto->lastError().isValid())
    QMessageBox::warning(patraObjekto,QObject::tr("Eraro [056]!"),informpeto->lastError().text());
  tablo.append("<tr>\n<td class='etno_kolumno'>");
  tablo.append(etno);
  tablo.append("</td>\n<td class='nomo_kolumno'><a href='");
  tablo.append(patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
  tablo.append(uuid);
  tablo.append(".html' title='");
  tablo.append(patraObjekto->identigiloTipoj[tipo].toUtf8());
  tablo.append("'>");
  tablo.append(nomo);
  tablo.append("</a></td>\n<td class='lingvo_kolumno'>[");
  tablo.append(lingvo);
  tablo.append("]</td>\n<td class='fonto_kolumno'><p>");
  if(!literaturo.isEmpty())
  {if(informpeto->exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo.replace("'","''")+"';"))
   {if(informpeto->first())
     tablo.append(qUncompress(informpeto->value("html").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
       patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
   }
   else
    if(informpeto->lastError().isValid())
     QMessageBox::warning(patraObjekto,QObject::tr("Eraro [057]!"),informpeto->lastError().text());
  }
  if(!pagxo.isEmpty())
   tablo.append(pagxo.replace("\342\233\223\342\231\202\342\233\201/",
     patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
  tablo.append("</p></td>\n<td class='sinonimoj_kolumno'>");
  QListWidget *sinonimoj=new QListWidget;
  sinonimoj->setSortingEnabled(true);
  if(informpeto->exec("SELECT nomo,lingvo FROM identigiloj WHERE etno='"+etno+"' AND uuid='"+uuid+"' AND nomo IS NOT '"+
    nomo.replace("'","''")+"';"))
  {while(informpeto->next())
    sinonimoj->addItem(new QListWidgetItem(informpeto->value("nomo").toByteArray()+" ["+
      informpeto->value("lingvo").toByteArray()+"]"));
  }
  else
   if(informpeto->lastError().isValid())
    QMessageBox::warning(patraObjekto,QObject::tr("Eraro [058]!"),informpeto->lastError().text());
  for(int nombro=0;nombro<sinonimoj->count();++nombro)
  {if(nombro>0)
    tablo.append(", ");
   tablo.append(sinonimoj->item(nombro)->text().toUtf8());
  }
  tablo.append("</td>\n</tr>\n");
  delete sinonimoj;
  delete aktualo;
 }
 tablo.append("</tbody>\n<tfood>\n<tr>\n<td class='stato_kolumno' colspan='5'>");
 tablo.append(QObject::tr("Stato: "));
 tablo.append(QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate).toUtf8());
 tablo.append("</td>\n</tr>\n</tfoot>\n</table>\n");
 delete listo;
 return tablo;
}
