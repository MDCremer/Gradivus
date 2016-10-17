#include <QList>
#include <QListWidgetItem>
#include <QString>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::priAlternativojElekti()
{QList<QListWidgetItem *> elektajxoj=ui->alternativoj->selectedItems();
 if(elektajxoj.length()>0)
 {QString aktualo=ui->etno->currentText().left(2)+": "+elektajxoj.first()->text();
  if(ui->limigiTipoj->currentIndex()>0||ui->lingvoLimigo->currentIndex()>0)
  {ui->limigiTipoj->setCurrentIndex(0);
   ui->lingvoLimigo->setCurrentIndex(0);
  }
  QList<QListWidgetItem *> kongruoj=ui->identigilojListo->findItems(aktualo,Qt::MatchExactly);
  if(kongruoj.size()>0)
   ui->identigilojListo->setCurrentItem(kongruoj.first());
}}
