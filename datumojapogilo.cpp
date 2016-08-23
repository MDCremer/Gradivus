#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include "datumojapogilo.h"
#include "ui_datumojapogilo.h"

datumojApogilo::datumojApogilo(QWidget *gepatro):QDialog(gepatro),ui(new Ui::datumojApogilo)
{ui->setupUi(this);
 connect(ui->abortu,&QPushButton::clicked,this,&datumojApogilo::priAbortu);
 connect(ui->eksportu,&QPushButton::clicked,this,&datumojApogilo::priExportu);
}
