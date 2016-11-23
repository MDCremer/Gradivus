#include <QByteArray>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QObject>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include "eldono.h"
#include "cxefafenestro.h"

QByteArray eldono::priskribo(QByteArray kodo,QSqlQuery *informpeto,cxefaFenestro *patraObjekto)
{QByteArray teksto("<article class='priskribo'>\n<header class='identigiloj'>\n");
 QListWidget *nomoj=new QListWidget();
 nomoj->setSortingEnabled(true);
 if(informpeto->exec("SELECT etno,nomo,lingvo,tipo FROM identigiloj WHERE uuid='"+kodo+"';"))
 {while(informpeto->next())
   nomoj->addItem(new QListWidgetItem(informpeto->value("etno").toString()+informpeto->value("tipo").toString()+
      informpeto->value("nomo").toString()+informpeto->value("lingvo").toString()));
 }
 else
  if(informpeto->lastError().isValid())
   QMessageBox::warning(patraObjekto,QObject::tr("Eraro [061]!"),informpeto->lastError().text());
 QByteArray aktualaEtno("xx");
 bool unua=true;
 for(int nombro=0;nombro<nomoj->count();++nombro)
 {if(!nomoj->item(nombro)->text().startsWith(aktualaEtno))
  {if(nombro>0)
    teksto.append("</h2>\n");
   teksto.append("<h2>");
   aktualaEtno=nomoj->item(nombro)->text().left(2).toUtf8();
   teksto.append(aktualaEtno);
   teksto.append(": ");
   unua=true;
  }
  if(unua)
   unua=false;
  else
   teksto.append(", ");
  teksto.append(nomoj->item(nombro)->text().mid(3,nomoj->item(nombro)->text().length()-5).toUtf8());
  teksto.append(" [");
  teksto.append(nomoj->item(nombro)->text().right(2).toUtf8());
  teksto.append("]");
 }
 teksto.append("</h2>\n</header>\n");
 delete nomoj;
 QStringList referencoj;
 if(informpeto->exec("SELECT teksto FROM priskriboj,lingvoj WHERE uuid='"+kodo+"' AND mallongigo=lingvo ORDER BY rango;"))
 {if(informpeto->first())
  {QByteArray priskribo=qUncompress(informpeto->value("teksto").toByteArray()).
     replace("\342\233\223\342\231\202\342\233\201/",patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
   QRegularExpressionMatchIterator interkonsento=
     QRegularExpression("\343\200\226\360\237\223\226[A-Za-z0-9]{3}\343\200\227").globalMatch(priskribo);
   while(interkonsento.hasNext())
   {QRegularExpressionMatch kongruo=interkonsento.next();
    if(kongruo.hasMatch())
    {int nombro=referencoj.indexOf(QRegularExpression(kongruo.captured().mid(3,3)));
     if(nombro>-1)
      priskribo.replace(kongruo.captured().toUtf8(),"<sup>["+QByteArray::number(nombro)+"]</sup>");
     else
     {referencoj<<kongruo.captured().mid(3,3);
      priskribo.replace(kongruo.captured().toUtf8(),"<sup>["+QByteArray::number(referencoj.length())+"]</sup>");
   }}}
   teksto.append("<section class='teksto'>\n");
   teksto.append(priskribo);
   teksto.append("</section>\n");
 }}
 else
  if(informpeto->lastError().isValid())
   QMessageBox::warning(patraObjekto,QObject::tr("Eraro [098]!"),informpeto->lastError().text());
 QListWidget *fontoj=new QListWidget();
 fontoj->setSortingEnabled(true);
 if(informpeto->exec("SELECT aludo FROM fontoj WHERE uuid='"+kodo+"';"))
 {while(informpeto->next())
   fontoj->addItem(new QListWidgetItem(informpeto->value("aludo").toString()));
 }
 else
  if(informpeto->lastError().isValid())
   QMessageBox::warning(patraObjekto,QObject::tr("Eraro [075]!"),informpeto->lastError().text());
 if(fontoj->count()>0)
 {teksto.append("<footer class='fontoj'>\n<h3>");
  teksto.append(QObject::tr("Fontoj"));
  teksto.append("</h3>\n<table>\n");
  for(int nombro=0;nombro<referencoj.length();++nombro)
  {teksto.append("<tr>\n<td class='indekso_kolumno'><sup>[");
   teksto.append(QString::number(nombro+1).toUtf8());
   teksto.append("]</sup></td>\n<td class='fonto_kolumno'>");
   QByteArray literaturo,pagxo;
   if(informpeto->exec("SELECT literaturo,pagxo FROM fontoj WHERE uuid='"+kodo+"' AND aludo='"+referencoj[nombro]+"';"))
   {if(informpeto->first())
    {if(!informpeto->value("literaturo").isNull())
      literaturo=informpeto->value("literaturo").toByteArray();
     if(!informpeto->value("pagxo").isNull())
      pagxo=qUncompress(informpeto->value("pagxo").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
        patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
   }}
   else
    if(informpeto->lastError().isValid())
     QMessageBox::warning(patraObjekto,QObject::tr("Eraro [076]!"),informpeto->lastError().text());
   if(!literaturo.isEmpty())
   {if(informpeto->exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo.replace("'","''")+"';"))
    {if(informpeto->first())
      teksto.append(qUncompress(informpeto->value("html").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
        patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
    }
    else
     if(informpeto->lastError().isValid())
      QMessageBox::warning(patraObjekto,QObject::tr("Eraro [077]!"),informpeto->lastError().text());
   }
   teksto.append(pagxo);
   teksto.append("</td>\n");
   QList<QListWidgetItem *> kongruoj=fontoj->findItems(referencoj[nombro],Qt::MatchExactly);
   if(kongruoj.size()>0)
    delete fontoj->takeItem(fontoj->row(kongruoj.first()));
  }
  int nombro=referencoj.length()+1;
  while(fontoj->count()>0)
  {QListWidgetItem *aktualo=fontoj->takeItem(0);
   teksto.append("<tr>\n<td><sup>[");
   teksto.append(QString::number(nombro++).toUtf8());
   teksto.append("]</sup></td>\n<td>");
   QByteArray literaturo,pagxo;
   if(informpeto->exec("SELECT literaturo,pagxo FROM fontoj WHERE uuid='"+kodo+"' AND aludo='"+aktualo->text()+"';"))
   {if(informpeto->first())
    {if(!informpeto->value("literaturo").isNull())
      literaturo=informpeto->value("literaturo").toByteArray();
     if(!informpeto->value("pagxo").isNull())
      pagxo=qUncompress(informpeto->value("pagxo").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
        patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
   }}
   else
    if(informpeto->lastError().isValid())
     QMessageBox::warning(patraObjekto,QObject::tr("Eraro [078]!"),informpeto->lastError().text());
   if(!literaturo.isEmpty())
   {if(informpeto->exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo.replace("'","''")+"';"))
    {if(informpeto->first())
      teksto.append(qUncompress(informpeto->value("html").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
        patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
    }
    else
     if(informpeto->lastError().isValid())
      QMessageBox::warning(patraObjekto,QObject::tr("Eraro [079]!"),informpeto->lastError().text());
   }
   teksto.append(pagxo);
   teksto.append("</td>\n");
   delete aktualo;
  }
  teksto.append("</table>\n</footer>\n");
 }
 delete fontoj;
 teksto.append("</article>\n");
 return teksto;
}
