#include <QDialog>
#include <QLayout>
#include <QToolButton>
#include <QWidget>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "cxefafenestro.h"

tezauxro::tezauxro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::tezauxro)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 ui->aludoj->setAlignment(ui->fonto,Qt::AlignTop);
 connect(ui->reiru,&QToolButton::clicked,this,&tezauxro::priReiru);
 connect(ui->selektado,&QToolButton::clicked,this,&tezauxro::priSelektado);
 connect(ui->fonto,&QToolButton::clicked,this,&tezauxro::priFonto);
 connect(ui->objekto,&QToolButton::clicked,this,&tezauxro::priObjekto);
}
