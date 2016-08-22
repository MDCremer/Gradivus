#include <QDialog>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "datumojapogilo.h"

void cxefaFenestro::priDatumojApogilo()
{datumojApoligo datumojApogilo(this);
 datumojApogilo.exec();
}
