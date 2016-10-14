#include "kodoselektado.h"
#include "ui_kodoselektado.h"

void kodoSelektado::priDevasEnhavi(bool kontrolita)
{ui->enhavo->setEnabled(kontrolita);
 if(kontrolita)
  ui->enhavo->setFocus();
 else
  sxargi();
}
