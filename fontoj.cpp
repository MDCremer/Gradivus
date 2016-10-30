#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

fontoj::fontoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::fontoj)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 registrilo=new rikordoRegistrilo(ui->malfaru);
 connect(ui->selektado,&QToolButton::clicked,this,&fontoj::priSelektado);
}
