#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"

void fontoj::priKontribui(bool kontrolita)
{if(kontrolita)
  ui->kontribui->setChecked(patraObjekto->konsento(this));
}
