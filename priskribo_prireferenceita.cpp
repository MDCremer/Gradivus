#include <QDialog>
#include <QString>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "kodoselektado.h"

void priskribo::priReferenceita()
{ui->teksto->setFocus();
 QString ligilo;
 if(!enigojAktivigita[PRISKRIBO_REFERENCEITA]||ui->teksto->textCursor().hasSelection())
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
  enigojAktivigita[PRISKRIBO_REFERENCEITA]=false;
  ui->a->setText("<a>");
 }
 else
 {if(enigojAktivigita[PRISKRIBO_REFERENCEITA])
  {ui->teksto->insertPlainText("</a>");
   enigojAktivigita[PRISKRIBO_REFERENCEITA]=false;
   ui->a->setText("<a>");
  }
  else
  {QString enigo("<a href='");
   enigo.append(ligilo);
   if(!ligilo.isEmpty())
    enigo.append(".html");
   enigo.append("'>");
   ui->teksto->insertPlainText(enigo);
   enigojAktivigita[PRISKRIBO_REFERENCEITA]=true;
   ui->a->setText("</a>");
}}}
