#include <QByteArray>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void fontoj::priElektajxoSxangxo()
{QList<QListWidgetItem *> elektajxoj=ui->listo->selectedItems();
 if(elektajxoj.length()>0)
 {QListWidgetItem *aktualo=elektajxoj.first();
  if(aktualo->text()!=aktualaFonto)
  {aktualaFonto=aktualo->text();
   ui->forigu->setEnabled(true);
   ui->aludo->setText(aktualo->text());
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    if(informpeto.exec("SELECT literaturo,pagxo,subskribo,stato FROM fontoj WHERE uuid='"+ajxo+"' AND aludo='"+aktualaFonto+
      "';"))
    {if(informpeto.first())
     {if(informpeto.value("literaturo").isNull())
       literaturo.clear();
      else
       literaturo=informpeto.value("literaturo").toString();
      if(informpeto.value("pagxo").isNull())
       pagxo.clear();
      else
       pagxo=QString(qUncompress(informpeto.value("pagxo").toByteArray()));
      ui->subskribo->setText(informpeto.value("subskribo").toString());
      QDateTime tempo;
      tempo.setTime_t(informpeto.value("stato").toUInt());
      ui->stato->setText(tempo.toString(Qt::SystemLocaleLongDate));
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [070]!"),informpeto.lastError().text());
    QByteArray html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
    html.append("</head>\n<body>\n<p>");
    if(!literaturo.isEmpty())
    {if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo.replace("'","''")+"';"))
     {if(informpeto.first())
       html.append(qUncompress(informpeto.value("html").toByteArray()).replace("\342\233\223\342\231\202\342\233\201/",
         patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
     }
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [071]!"),informpeto.lastError().text());
    }
    html.append(pagxo.toUtf8().replace("\342\233\223\342\231\202\342\233\201/",
      patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
    html.append("</p>\n</body>\n</html>");
    ui->montru->setHtml(html);
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [069]!"),datumbazo.lastError().text());
 }}
 else
 {ui->forigu->setEnabled(false);
  ui->subskribo->clear();
  ui->stato->clear();
  aktualaFonto.clear();
}}
