#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"
#include "cxefafenestro.h"

datumojRestauxro::datumojRestauxro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::datumojrestauxro)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
}
