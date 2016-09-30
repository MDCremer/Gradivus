#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "konfiguro.h"

void cxefaFenestro::priKonfiguro()
{konfiguro konfiguroDialogo(this);
 konfiguroDialogo.exec();
}
