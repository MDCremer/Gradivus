#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "cxefafenestro.h"

void tezauxro::priKontribui(bool kontrolita)
{if(kontrolita)
  ui->kontribui->setChecked(patraObjekto->konsento(this));
}
