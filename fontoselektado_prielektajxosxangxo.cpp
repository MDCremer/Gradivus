#include <QByteArray>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "fontoselektado.h"
#include "ui_fontoselektado.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void fontoSelektado::priElektajxoSxangxo()
{QList<QListWidgetItem *> elektajxoj=ui->listo->selectedItems();
 if(elektajxoj.length()>0)
 {QListWidgetItem *aktualo=elektajxoj.first();
  if(aktualo->text()!=aludo)
  {aludo=aktualo->text().toUtf8();
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    QString literaturo,pagxo;
    if(informpeto.exec("SELECT literaturo,pagxo FROM fontoj WHERE uuid='"+ajxo+"' AND aludo='"+aludo+"';"))
    {if(informpeto.first())
     {if(!informpeto.value("literaturo").isNull())
       literaturo=informpeto.value("literaturo").toString();
      if(!informpeto.value("pagxo").isNull())
       pagxo=QString(qUncompress(informpeto.value("pagxo").toByteArray()));
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [090]!"),informpeto.lastError().text());
    QByteArray html=avaObjekto->administranto.akiruValoro(AGORDO_STILO);
    html.append("</head>\n<body>\n<p>");
    if(!literaturo.isEmpty())
    {if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo.replace("'","''")+"';"))
     {if(informpeto.first())
       html.append(qUncompress(informpeto.value("html").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
         avaObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
     }
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [091]!"),informpeto.lastError().text());
    }
    html.append(pagxo.toUtf8().replace("\342\233\223\342\231\202\342\233\201/",
      avaObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
    html.append("</p>\n</body>\n</html>");
    ui->montru->setHtml(html);
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [089]!"),datumbazo.lastError().text());
   ui->apliku->setEnabled(true);
}}}
