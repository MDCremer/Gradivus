#include "konfiguro.h"
#include "ui_konfiguro.h"
#include "agordoj.h"
#include "cxefafenestro.h"

void konfiguro::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 registrilo->malfaru();
 patraObjekto->administranto.sxargu();
 lingvaKvanto=patraObjekto->administranto.akiruLingvaKvanto();
 ui->inicialoj->setText(patraObjekto->administranto.akiruValoro(AGORDO_NOMO));
 if(patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).isEmpty())
  ui->kulturo->setCurrentIndex(0);
 else
  ui->kulturo->setCurrentIndex(ui->kulturo->findText(patraObjekto->administranto.akiruValoro(AGORDO_LINGVO)));
 ui->lingvoj->clear();
 for(int indekso=0;indekso<lingvaKvanto;++indekso)
  ui->lingvoj->addItem(statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)]);
 patraObjekto->spektakloMesagxon(tr("\305\234an\304\235oj malfaritaj!"));
 this->setCursor(Qt::ArrowCursor);
}
