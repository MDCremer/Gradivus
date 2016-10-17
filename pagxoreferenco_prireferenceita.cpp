#include <QDialog>
#include <QString>
#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"
#include "kodoselektado.h"

void pagxoReferenco::priReferenceita()
{if(ui->redakto->hasFocus())
 {QString ligilo;
  if(!enigojAktivigita[PAGXOREFERENCO_REFERENCEITA]||ui->redakto->textCursor().hasSelection())
  {kodoSelektado selektado(this,avaObjekto);
   if(selektado.exec()==QDialog::Accepted)
   {ligilo="\342\233\223\342\231\202\342\233\201/";
    ligilo.append(selektado.akiruKodo());
  }}
  if(ui->redakto->textCursor().hasSelection())
  {QString enigo("<a href='");
   enigo.append(ligilo);
   enigo.append(".html'>");
   enigo.append(ui->redakto->textCursor().selectedText());
   enigo.append("</a>");
   ui->redakto->insertPlainText(enigo);
   enigojAktivigita[PAGXOREFERENCO_REFERENCEITA]=false;
   ui->referenceita->setText("<a>");
  }
  else
  {if(enigojAktivigita[PAGXOREFERENCO_REFERENCEITA])
   {ui->redakto->insertPlainText("</a>");
    enigojAktivigita[PAGXOREFERENCO_REFERENCEITA]=false;
    ui->referenceita->setText("<a>");
   }
   else
   {QString enigo("<a href='");
    enigo.append(ligilo);
    enigo.append(".html'>");
    ui->redakto->insertPlainText(enigo);
    enigojAktivigita[PAGXOREFERENCO_REFERENCEITA]=true;
    ui->referenceita->setText("</a>");
}}}}
