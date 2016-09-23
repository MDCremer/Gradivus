#include <QtWebEngineWidgets>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "hipertekstopagxo.h"
#include "rikordoregistrilo.h"

referencoj::referencoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::referencoj)
{ui->setupUi(this);
 ui->spektaklo->setPage(new hipertekstoPagxo());
 markilo=new htmlMarkilo(ui->teksto->document());
 registrilo=new rikordoRegistrilo(ui->malfaru);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->abortu,&QToolButton::clicked,this,&referencoj::priAbortu);
 sxargiAludoj();
}
