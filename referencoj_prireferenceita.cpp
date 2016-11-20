#include <QDialog>
#include <QString>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "kodoselektado.h"

void referencoj::priReferenceita()
{if(ui->teksto->hasFocus())
 {QString ligilo;
  if(!enigojAktivigita[REFERENCO_REFERENCEITA]||ui->teksto->textCursor().hasSelection())
  {kodoSelektado selektado(this,patraObjekto);
   if(selektado.exec()==QDialog::Accepted)
   {ligilo="\342\233\223\342\231\202\342\233\201/";
    ligilo.append(selektado.akiruKodo());
  }}
  if(ui->teksto->textCursor().hasSelection())
  {QString enigo("<a href='");
   enigo.append(ligilo);
   if(!ligilo.isEmpty())
    enigo.append(".html");
   enigo.append("'>");
   enigo.append(ui->teksto->textCursor().selectedText());
   enigo.append("</a>");
   ui->teksto->insertPlainText(enigo);
   enigojAktivigita[REFERENCO_REFERENCEITA]=false;
   ui->referenceita->setText("<a>");
  }
  else
  {if(enigojAktivigita[REFERENCO_REFERENCEITA])
   {ui->teksto->insertPlainText("</a>");
    enigojAktivigita[REFERENCO_REFERENCEITA]=false;
    ui->referenceita->setText("<a>");
   }
   else
   {QString enigo("<a href='");
    enigo.append(ligilo);
    if(!ligilo.isEmpty())
     enigo.append(".html");
    enigo.append("'>");
    ui->teksto->insertPlainText(enigo);
    enigojAktivigita[REFERENCO_REFERENCEITA]=true;
    ui->referenceita->setText("</a>");
}}}}
