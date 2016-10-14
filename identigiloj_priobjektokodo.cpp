#include <QDialog>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "kodoselektado.h"

void identigiloj::priObjektoKodo()
{kodoSelektado selektado(this,patraObjekto);
 if(selektado.exec()==QDialog::Accepted)
  ui->objektoKodo->setText(selektado.akiruKodo());
}
