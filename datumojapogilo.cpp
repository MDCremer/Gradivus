#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include "datumojapogilo.h"
#include "ui_datumojapogilo.h"

datumojApogilo::datumojApogilo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::datumojApogilo)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 connect(ui->rezignu,&QPushButton::clicked,this,&datumojApogilo::priRezignu);
 connect(ui->eksportu,&QPushButton::clicked,this,&datumojApogilo::priEksportu);
 connect(ui->elektuCxiuj,&QPushButton::clicked,this,&datumojApogilo::priElektuCxiuj);
}
