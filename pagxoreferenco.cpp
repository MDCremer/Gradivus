#include <QListWidgetItem>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"
#include "cxefafenestro.h"
#include "hipertekstopagxo.h"
#include "htmlmarkilo.h"

pagxoReferenco::pagxoReferenco(QWidget *gepatro,cxefaFenestro *avo):QDialog(gepatro),ui(new Ui::pagxoReferenco)
{ui->setupUi(this);
 ui->spektaklo->setPage(new hipertekstoPagxo());
 markilo=new htmlMarkilo(ui->redakto->document());
 avaObjekto=avo;
 connect(ui->rezignu,&QPushButton::clicked,this,&pagxoReferenco::priRezignu);
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT aludo FROM literaturoj;"))
  {while(informpeto.next())
    ui->referencoj->addItem(new QListWidgetItem(informpeto.value("aludo").toByteArray()));
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [034]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [033]!"),datumbazo.lastError().text());
}
