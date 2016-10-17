#include <QString>
#include <QToolButton>
#include "pagxoreferenco.h"
#include "ui_pagxoreferenco.h"

void pagxoReferenco::enigi(int indekso,QString starto,QString fino,QToolButton *butono)
{if(ui->redakto->hasFocus())
 {if(ui->redakto->textCursor().hasSelection())
  {QString enigo(starto);
   enigo.append(ui->redakto->textCursor().selectedText());
   enigo.append(fino);
   ui->redakto->insertPlainText(enigo);
   enigojAktivigita[indekso]=false;
   butono->setText(starto);
  }
  else
  {if(enigojAktivigita[indekso])
   {ui->redakto->insertPlainText(fino);
    enigojAktivigita[indekso]=false;
    butono->setText(starto);
   }
   else
   {ui->redakto->insertPlainText(starto);
    enigojAktivigita[indekso]=true;
    butono->setText(fino);
}}}}
