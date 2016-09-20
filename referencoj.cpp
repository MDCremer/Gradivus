#include "referencoj.h"
#include "ui_referencoj.h"

referencoj::referencoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::referencoj)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->abortu,&QToolButton::clicked,this,&referencoj::priAbortu);
}
