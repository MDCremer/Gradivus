#include "konfiguro.h"
#include "ui_konfiguro.h"

void konfiguro::priMalsupro()
{int linio=ui->lingvoj->currentRow();
 QListWidgetItem *aktivaEro=ui->lingvoj->currentItem();
 for(int indekso=linio;indekso<183;++indekso)
  ui->lingvoj->insertItem(indekso,ui->lingvoj->takeItem(indekso+1));
 ui->lingvoj->insertItem(183,aktivaEro);
 if(linio==0)
 {ui->supren->setEnabled(true);
  ui->supro->setEnabled(true);
 }
 ui->malsupro->setEnabled(false);
 ui->malsupren->setEnabled(false);
 ui->lingvoj->scrollToItem(aktivaEro);
 ui->lingvoj->setFocus();
}
