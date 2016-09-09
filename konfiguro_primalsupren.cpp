#include "konfiguro.h"
#include "ui_konfiguro.h"

void konfiguro::priMalsupren()
{int linio=ui->lingvoj->currentRow();
 QListWidgetItem *aktivaEro=ui->lingvoj->currentItem();
 ui->lingvoj->insertItem(linio,ui->lingvoj->takeItem(linio+1));
 ui->lingvoj->insertItem(linio+1,aktivaEro);
 if(linio==0)
 {ui->supren->setEnabled(true);
  ui->supro->setEnabled(true);
 }
 if(linio==ui->lingvoj->count()-2)
 {ui->malsupro->setEnabled(false);
  ui->malsupren->setEnabled(false);
 }
 ui->lingvoj->scrollToItem(aktivaEro);
 ui->lingvoj->setFocus();
}
