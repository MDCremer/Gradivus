#include <QDialog>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"

priskribo::priskribo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::priskribo)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
}
