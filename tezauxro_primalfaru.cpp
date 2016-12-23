#include "tezauxro.h"
#include "ui_tezauxro.h"

void tezauxro::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 registrilo->malfaru();
 sxargi();
 this->setCursor(Qt::ArrowCursor);
}
