#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"

void pagxoReferenco::priVakigu()
{ui->redakto->clear();
 ui->referencoj->clearSelection();
 if(enigojAktivigita[PAGXOREFERENCO_CITAJXO])
  ui->citajxo->setText("<cite>");
 if(enigojAktivigita[PAGXOREFERENCO_FORTA])
  ui->forta->setText("<strong>");
 if(enigojAktivigita[PAGXOREFERENCO_GRASA])
  ui->grasa->setText("<b>");
 if(enigojAktivigita[PAGXOREFERENCO_KURSIVA])
  ui->kursiva->setText("<i>");
 if(enigojAktivigita[PAGXOREFERENCO_SUBSTRETIKA])
  ui->substretika->setText("<u>");
 if(enigojAktivigita[PAGXOREFERENCO_SUPERSKRIBITA])
  ui->superskribita->setText("<sup>");
 if(enigojAktivigita[PAGXOREFERENCO_SUBA])
  ui->suba->setText("<sub>");
 if(enigojAktivigita[PAGXOREFERENCO_REFERENCEITA])
  ui->referenceita->setText("<a>");
 if(enigojAktivigita[PAGXOREFERENCO_MINORA])
  ui->minora->setText("<small>");
 for(int indekso=0;indekso<9;++indekso)
  enigojAktivigita[indekso]=false;
}
