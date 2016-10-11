#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::priVakigu()
{ui->aludo->clear();
 ui->teksto->clear();
 ui->aludoj->clearSelection();
 if(enigojAktivigita[REFERENCO_CITAJXO])
  ui->citajxo->setText("<cite>");
 if(enigojAktivigita[REFERENCO_FORTA])
  ui->forta->setText("<strong>");
 if(enigojAktivigita[REFERENCO_GRASA])
  ui->grasa->setText("<b>");
 if(enigojAktivigita[REFERENCO_KURSIVA])
  ui->kursiva->setText("<i>");
 if(enigojAktivigita[REFERENCO_SUBSTRETIKA])
  ui->substretika->setText("<u>");
 if(enigojAktivigita[REFERENCO_SUPERSKRIBITA])
  ui->superskribita->setText("<sup>");
 if(enigojAktivigita[REFERENCO_SUBA])
  ui->suba->setText("<sub>");
 if(enigojAktivigita[REFERENCO_REFERENCEITA])
  ui->referenceita->setText("<a>");
 if(enigojAktivigita[REFERENCO_MINORA])
  ui->minora->setText("<small>");
 for(int indekso=0;indekso<9;++indekso)
  enigojAktivigita[indekso]=false;
}
