#include <QString>
#include <QToolButton>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::enigi(int indekso,QString starto,QString fino,QToolButton *butono)
{if(ui->teksto->hasFocus())
 {if(ui->teksto->textCursor().hasSelection())
  {QString enigo(starto);
   enigo.append(ui->teksto->textCursor().selectedText());
   enigo.append(fino);
   ui->teksto->insertPlainText(enigo);
   enigojAktivigita[indekso]=false;
   butono->setText(starto);
  }
  else
  {if(enigojAktivigita[indekso])
   {ui->teksto->insertPlainText(fino);
    enigojAktivigita[indekso]=false;
    butono->setText(starto);
   }
   else
   {ui->teksto->insertPlainText(starto);
    enigojAktivigita[indekso]=true;
    butono->setText(fino);
}}}}
