#include "konfiguro.h"
#include "ui_konfiguro.h"

void konfiguro::priSupren()
{int linio=ui->lingvoj->currentRow();
 QListWidgetItem *aktivaEro=ui->lingvoj->currentItem();
 ui->lingvoj->insertItem(linio,ui->lingvoj->takeItem(linio-1));
 ui->lingvoj->insertItem(linio-1,aktivaEro);
 if(linio==1)
 {ui->supro->setEnabled(false);
  ui->supren->setEnabled(false);
 }
 if(linio==ui->lingvoj->count()-1)
 {ui->malsupren->setEnabled(true);
  ui->malsupro->setEnabled(true);
 }
 ui->lingvoj->scrollToItem(aktivaEro);
 ui->lingvoj->setFocus();
}
