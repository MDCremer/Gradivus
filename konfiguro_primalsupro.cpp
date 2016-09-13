#include "konfiguro.h"
#include "ui_konfiguro.h"
#include "cxefafenestro.h"

void konfiguro::priMalsupro()
{int linio=ui->lingvoj->currentRow();
 QListWidgetItem *aktivaEro=ui->lingvoj->currentItem();
 for(int indekso=linio;indekso<lingvaKvanto-1;++indekso)
  ui->lingvoj->insertItem(indekso,ui->lingvoj->takeItem(indekso+1));
 ui->lingvoj->insertItem(lingvaKvanto-1,aktivaEro);
 if(linio==0)
 {ui->supren->setEnabled(true);
  ui->supro->setEnabled(true);
 }
 ui->malsupro->setEnabled(false);
 ui->malsupren->setEnabled(false);
 ui->lingvoj->scrollToItem(aktivaEro);
 ui->lingvoj->setFocus();
}
