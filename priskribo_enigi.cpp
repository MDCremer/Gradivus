#include <QString>
#include <QToolButton>
#include "priskribo.h"
#include "ui_priskribo.h"

void priskribo::enigi(int indekso,QString starto,QString fino,QToolButton *butono)
{ui->teksto->setFocus();
 if(ui->teksto->textCursor().hasSelection())
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
}}}
