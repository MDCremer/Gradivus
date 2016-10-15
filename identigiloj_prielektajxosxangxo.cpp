#include <QByteArray>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void identigiloj::priElektajxoSxangxo()
{QList<QListWidgetItem *> elektajxoj=ui->identigilojListo->selectedItems();
 if(elektajxoj.length()>0)
 {QListWidgetItem *aktualo=elektajxoj.first();
  if(aktualo->text()!=aktualaIdentigilo)
  {aktualaIdentigilo=aktualo->text();
   int indekso=ui->historiaListo->findText(aktualaIdentigilo);
   if(indekso==-1)
   {ui->historiaListo->insertItem(0,aktualaIdentigilo);
    indekso=0;
   }
   ui->historiaListo->setCurrentIndex(indekso);
   ui->forigu->setEnabled(true);
   QString etno=aktualo->text().left(2);
   QString nomo;
   QString lingvo;
   QString kodo;
   if(ui->lingvoLimigo->currentIndex()>0)
   {nomo=aktualo->text().right(aktualo->text().length()-4);
    lingvo=ui->lingvoLimigo->currentText().left(2);
   }
   else
   {nomo=aktualo->text().mid(4,aktualo->text().length()-9);
    lingvo=aktualo->text().mid(aktualo->text().length()-3,2);
   }
   ui->etno->setCurrentIndex(ui->etno->findText(etno,Qt::MatchStartsWith));
   ui->nomo->setText(nomo);
   ui->lingvo->setCurrentIndex(ui->lingvo->findText(lingvo,Qt::MatchStartsWith));
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    if(informpeto.exec("SELECT tipo,literaturo,pagxo,uuid,subskribo,stato FROM identigiloj WHERE etno='"+etno+
      "' AND nomo='"+nomo.replace("'","''")+"' AND lingvo='"+lingvo+"';"))
    {if(informpeto.first())
     {ui->tipo->setCurrentIndex(informpeto.value("tipo").toInt());
      if(informpeto.value("literaturo").isNull())
       literaturo.clear();
      else
       literaturo=informpeto.value("literaturo").toString();
      if(informpeto.value("pagxo").isNull())
       pagxo.clear();
      else
       pagxo=QString(qUncompress(informpeto.value("pagxo").toByteArray()));
      kodo=informpeto.value("uuid").toString();
      ui->subskribo->setText(informpeto.value("subskribo").toString());
      QDateTime tempo;
      tempo.setTime_t(informpeto.value("stato").toUInt());
      ui->stato->setText(tempo.toString(Qt::SystemLocaleLongDate));
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [045]!"),informpeto.lastError().text());
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
       QMessageBox::warning(this,tr("Eraro [046]!"),informpeto.lastError().text());
    }
    html.append(pagxo.toUtf8().replace("\342\233\223\342\231\202\342\233\201/",
      patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
    html.append("</p>\n</body>\n</html>");
    ui->referenco->setHtml(html);
    datumbazo.close();
    ui->objektoKodo->setText(kodo);
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [044]!"),datumbazo.lastError().text());
 }}
 else
 {ui->forigu->setEnabled(false);
  ui->subskribo->clear();
  ui->stato->clear();
  aktualaIdentigilo.clear();
}}
