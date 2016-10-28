#include <QByteArray>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
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
 teksto.append("</article>\n");
 return teksto;
}
