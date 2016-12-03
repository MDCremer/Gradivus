#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "cxefafenestro.h"

tezauxro::tezauxro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::tezauxro)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
}
