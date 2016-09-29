#include "referencoj.h"
#include "ui_referencoj.h"
#include "cxefafenestro.h"

void referencoj::priKontribui(bool kontrolita)
{if(kontrolita)
  ui->kontribui->setChecked(patraObjekto->konsento(this));
}
