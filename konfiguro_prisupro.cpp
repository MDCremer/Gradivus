#include <QListWidgetItem>
#include "konfiguro.h"
#include "ui_konfiguro.h"

void konfiguro::priSupro()
{int linio=ui->lingvoj->currentRow();
 QListWidgetItem *aktivaEro=ui->lingvoj->currentItem();
 for(int indekso=linio;indekso>0;--indekso)
  ui->lingvoj->insertItem(indekso,ui->lingvoj->takeItem(indekso-1));
 ui->lingvoj->insertItem(0,aktivaEro);
 if(linio==ui->lingvoj->count()-1)
 {ui->malsupren->setEnabled(true);
  ui->malsupro->setEnabled(true);
 }
 ui->supro->setEnabled(false);
 ui->supren->setEnabled(false);
 ui->lingvoj->scrollToItem(aktivaEro);
 ui->lingvoj->setFocus();
}
