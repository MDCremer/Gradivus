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
#include <QStringListIterator>
#include "eldono.h"
#include "cxefafenestro.h"

QByteArray eldono::priskribo(QByteArray kodo,QSqlQuery *informpeto,cxefaFenestro *patraObjekto,int grado)
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
 bool navigadoKolumno=false;
 if(informpeto->exec("SELECT COUNT(*) FROM semantikajrilatoj WHERE subjekto='"+kodo+"' OR objekto='"+kodo+"';"))
 {if(informpeto->first())
   if(informpeto->value("COUNT(*)").toInt()>0)
    navigadoKolumno=true;
 }
 else
  if(informpeto->lastError().isValid())
   QMessageBox::warning(patraObjekto,QObject::tr("Eraro [116]!"),informpeto->lastError().text());
 if(navigadoKolumno)
 {teksto.append("<aside class='tezauxro'>\n<dl>\n");
  QStringList specioj;
  specioj<<QObject::tr("hiponima:")<<QObject::tr("hiperonima:")<<QObject::tr("meronima:")<<QObject::tr("holonima:")
    <<QObject::tr("disponebla:")<<QObject::tr("disponenta:")<<QObject::tr("instrumenta:")<<QObject::tr("fina:")
    <<QObject::tr("supreniranta:")<<QObject::tr("malsupreniranta:");
  for(int nombro=0;nombro<5;++nombro)
  {QStringList objektoj;
   if(informpeto->exec("SELECT objekto,aludo FROM semantikajrilatoj WHERE subjekto='"+kodo+"' AND rilato="+
     QByteArray::number(nombro)+";"))
   {while(informpeto->next())
     objektoj<<informpeto->value("objekto").toString()+(informpeto->value("aludo").isNull()?"---":
       informpeto->value("aludo").toString());
   }
   else
    if(informpeto->lastError().isValid())
     QMessageBox::warning(patraObjekto,QObject::tr("Eraro [117]!"),informpeto->lastError().text());
   if(objektoj.length()>0)
   {teksto.append("<dt><dfn>");
    teksto.append(specioj.at(nombro*2).toUtf8());
    teksto.append("</dfn></dt>\n<dd>");
   }
   bool unua=true;
   QStringListIterator montrilo(objektoj);
   while(montrilo.hasNext())
   {QByteArray aktualo=montrilo.next().toUtf8();
    QByteArray objekto=aktualo.left(22);
    QByteArray aludo=aktualo.right(3);
    if(informpeto->exec("SELECT etno,nomo,mallongigo FROM identigiloj,lingvoj WHERE uuid='"+objekto+
      "' AND mallongigo=lingvo ORDER BY tipo,rango,nomo;"))
    {if(informpeto->first())
     {if(unua)
       unua=false;
      else
       teksto.append(", ");
      teksto.append("<a href='");
      teksto.append(patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
      teksto.append(objekto);
      teksto.append(".html'>");
      teksto.append(informpeto->value("etno").toByteArray()+": "+informpeto->value("nomo").toByteArray()+" ["+
        informpeto->value("mallongigo").toByteArray()+"]");
      teksto.append("</a>");
      if(aludo!="---")
      {int pozicio=referencoj.indexOf(QRegularExpression(aludo));
       if(pozicio==-1)
       {referencoj<<QString(aludo);
        pozicio=referencoj.length();
       }
       teksto.append("<sup><a href='#");
       teksto.append(aludo);
       teksto.append("'>[");
       teksto.append(QByteArray::number(pozicio));
       teksto.append("]</a></sup>");
    }}}
    else
     if(informpeto->lastError().isValid())
      QMessageBox::warning(patraObjekto,QObject::tr("Eraro [118]!"),informpeto->lastError().text());
   }
   teksto.append("</dd>\n");
   QStringList subjektoj;
   if(informpeto->exec("SELECT subjekto,aludo FROM semantikajrilatoj WHERE objekto='"+kodo+"' AND rilato="+
     QByteArray::number(nombro)+";"))
   {while(informpeto->next())
     subjektoj<<informpeto->value("subjekto").toString()+(informpeto->value("aludo").isNull()?"---":
       informpeto->value("aludo").toString());
   }
   else
    if(informpeto->lastError().isValid())
     QMessageBox::warning(patraObjekto,QObject::tr("Eraro [119]!"),informpeto->lastError().text());
   if(subjektoj.length()>0)
   {teksto.append("<dt><dfn>");
    teksto.append(specioj.at(nombro*2+1).toUtf8());
    teksto.append("</dfn></dt>\n<dd>");
   }
   unua=true;
   QStringListIterator duaMontrilo(subjektoj);
   while(duaMontrilo.hasNext())
   {QByteArray aktualo=duaMontrilo.next().toUtf8();
    QByteArray subjekto=aktualo.left(22);
    QByteArray aludo=aktualo.right(3);
    if(informpeto->exec("SELECT etno,nomo,mallongigo FROM identigiloj,lingvoj WHERE uuid='"+subjekto+
      "' AND mallongigo=lingvo ORDER BY tipo,rango,nomo;"))
    {if(informpeto->first())
     {if(unua)
       unua=false;
      else
       teksto.append(", ");
      teksto.append("<a href='");
      teksto.append(patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
      teksto.append(subjekto);
      teksto.append(".html'>");
      teksto.append(informpeto->value("etno").toByteArray()+": "+informpeto->value("nomo").toByteArray()+" ["+
        informpeto->value("mallongigo").toByteArray()+"]");
      teksto.append("</a>");
      if(aludo!="---")
      {int pozicio=referencoj.indexOf(QRegularExpression(aludo));
       if(pozicio==-1)
       {referencoj<<QString(aludo);
        pozicio=referencoj.length();
       }
       teksto.append("<sup><a href='#");
       teksto.append(aludo);
       teksto.append("'>[");
       teksto.append(QByteArray::number(pozicio));
       teksto.append("]</a></sup>");
    }}}
    else
     if(informpeto->lastError().isValid())
      QMessageBox::warning(patraObjekto,QObject::tr("Eraro [120]!"),informpeto->lastError().text());
   }
   teksto.append("</dd>\n");
  }
  teksto.append("</dl>\n</aside>\n");
 }
 if(informpeto->exec("SELECT teksto,subskribo FROM priskriboj,lingvoj WHERE uuid='"+kodo+
   "' AND mallongigo=lingvo ORDER BY rango;"))
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
      priskribo.replace(kongruo.captured().toUtf8(),"<sup>[<a href='#"+kongruo.captured().mid(3,3).toUtf8()+"'>"+
        QByteArray::number(nombro)+"</a>]</sup>");
     else
     {referencoj<<kongruo.captured().mid(3,3);
      priskribo.replace(kongruo.captured().toUtf8(),"<sup>[<a href='#"+kongruo.captured().mid(3,3).toUtf8()+"'>"+
        QByteArray::number(referencoj.length())+"</a>]</sup>");
   }}}
   teksto.append("<section class='teksto'>\n");
   teksto.append(priskribo);
   teksto.append("<p class='subskribo'>[");
   QByteArray subskribo=informpeto->value("subskribo").toByteArray();
   teksto.append(subskribo.mid(1,subskribo.length()-2));
   teksto.append("]</p>\n");
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
  {teksto.append("<tr>\n<td class='indekso_kolumno'><sup>[<a id='"+referencoj[nombro]+"'>");
   teksto.append(QString::number(nombro+1).toUtf8());
   teksto.append("</a>]</sup></td>\n<td class='fonto_kolumno'>");
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
