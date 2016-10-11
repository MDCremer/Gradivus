#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"
#include "cxefafenestro.h"

void pagxoReferenco::pagxosalto(int indekso)
{if(indekso==1)
 {ui->referencoKadro->setEnabled(false);
  ui->apliku->setEnabled(true);
  literaturo.clear();
  html=QString(avaObjekto->administranto.akiruValoro(AGORDO_STILO));
  html.append("</head>\n<body>\n<p>");
  if(ui->referencoKadro->isChecked())
  {QList<QListWidgetItem *> elektajxoj=ui->referencoj->selectedItems();
   if(elektajxoj.length()>0)
   {QListWidgetItem *faktaReferenco=elektajxoj.first();
    QSqlDatabase datumbazo=QSqlDatabase::database();
    if(datumbazo.open())
    {QSqlQuery informpeto;
     if(informpeto.exec("SELECT html FROM literaturoj where aludo='"+faktaReferenco->text().replace("'","''")+"';"))
     {if(informpeto.first())
      {html.append(qUncompress(informpeto.value("html").toByteArray()));
       literaturo=faktaReferenco->text();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [036]!"),informpeto.lastError().text());
     datumbazo.close();
    }
    else
     if(datumbazo.lastError().isValid())
      QMessageBox::critical(this,tr("Eraro [035]!"),datumbazo.lastError().text());
   }
   else
    if(ui->redakto->toPlainText().simplified().isEmpty())
     ui->apliku->setEnabled(false);
  }
  else
   if(ui->redakto->toPlainText().simplified().isEmpty())
    ui->apliku->setEnabled(false);
  html.append(ui->redakto->toPlainText().simplified());
  pagxo=ui->redakto->toPlainText().simplified();
  html.append("</p>\n</body>\n</html>");
  ui->spektaklo->setHtml(html);
 }
 else
  ui->referencoKadro->setEnabled(true);
}
