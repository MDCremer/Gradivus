#include <QList>
#include <QListWidgetItem>
#include "kodoselektado.h"
#include "ui_kodoselektado.h"

void kodoSelektado::priElektajxoSxangxo()
{QList<QListWidgetItem *> elektajxoj=ui->listo->selectedItems();
 ui->apliku->setEnabled(elektajxoj.length()>0);
}
