#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"

void priskribo::priKontribui(bool kontrolita)
{if(kontrolita)
  ui->kontribui->setChecked(patraObjekto->konsento(this));
}
