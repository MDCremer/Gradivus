#include <QListWidgetItem>
#include "konfiguro.h"
#include "ui_konfiguro.h"

void konfiguro::lingvoEtikedoSxangxo(QListWidgetItem *aktivaEro)
{if(aktivaEro==0)
 {ui->supro->setEnabled(false);
  ui->supren->setEnabled(false);
  ui->malsupren->setEnabled(false);
  ui->malsupro->setEnabled(false);
 }
 else
 {int indekso=ui->lingvoj->currentRow();
  ui->supro->setEnabled(indekso>0);
  ui->supren->setEnabled(indekso>0);
  ui->malsupren->setEnabled(indekso<ui->lingvoj->count()-1);
  ui->malsupro->setEnabled(indekso<ui->lingvoj->count()-1);
}}
