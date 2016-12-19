#include <QDialog>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "fontoselektado.h"

void tezauxro::priFonto()
{fontoSelektado selektado(this,patraObjekto,ajxo);
 if(selektado.exec()==QDialog::Accepted)
  ui->fonto->setText(selektado.akiruAludo());
 else
  ui->fonto->setText("---");
}
