#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"

void identigiloj::priKontribui(bool kontrolita)
{if(kontrolita)
  ui->kontribui->setChecked(patraObjekto->konsento(this));
}
