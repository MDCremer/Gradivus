#include <QDialog>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "fontoselektado.h"

void priskribo::priFonto()
{fontoSelektado selektado(this,patraObjekto,ajxo);
 if(selektado.exec()==QDialog::Accepted)
 {QByteArray enigo("\343\200\226\360\237\223\226");
  enigo.append(selektado.akiruAludo());
  enigo.append("\343\200\227");
  ui->teksto->insertPlainText(enigo);
}}
