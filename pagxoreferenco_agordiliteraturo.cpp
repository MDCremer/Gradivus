#include <QList>
#include <QListWidgetItem>
#include <QString>
#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"

void pagxoReferenco::agordiLiteraturo(QString aludo)
{QList<QListWidgetItem *> kongruoj=ui->referencoj->findItems(aludo,Qt::MatchExactly);
 if(kongruoj.size()>0)
  ui->referencoj->setCurrentItem(kongruoj.first());
}
