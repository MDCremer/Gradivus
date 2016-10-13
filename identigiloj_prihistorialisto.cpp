#include <QList>
#include <QListWidgetItem>
#include <QString>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::priHistoriaListo(QString teksto)
{QListWidgetItem *identigilo=ui->identigilojListo->currentItem();
 bool kongrua=true;
 if(identigilo==0)
  kongrua=false;
 else
  if(identigilo->text()!=teksto)
   kongrua=false;
 if(!kongrua&&!teksto.isEmpty())
 {QList<QListWidgetItem *> elektajxoj=ui->identigilojListo->findItems(teksto,Qt::MatchExactly);
  if(elektajxoj.length()>0)
   ui->identigilojListo->setCurrentItem(elektajxoj.first());
}}
