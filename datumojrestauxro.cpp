#include <QDialog>
#include <QToolButton>
#include <QWidget>
#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"
#include "cxefafenestro.h"

datumojRestauxro::datumojRestauxro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::datumojrestauxro)
{ui->setupUi(this);
 markilo=new sqlMarkilo(ui->sintakseAnalizu,ui->ordono->document());
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->reiru,&QToolButton::clicked,this,&datumojRestauxro::priReiru);
 connect(ui->sintakseAnalizu,&QToolButton::clicked,this,&datumojRestauxro::priSintakseAnalizu);
 connect(ui->plenumu,&QToolButton::clicked,this,&datumojRestauxro::priPlenumu);
}
