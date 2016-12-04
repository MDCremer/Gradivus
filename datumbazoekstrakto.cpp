#include <QDialog>
#include <QDir>
#include <QPushButton>
#include <QWidget>
#include "datumbazoekstrakto.h"
#include "ui_datumbazoekstrakto.h"
#include "cxefafenestro.h"

datumbazoEkstrakto::datumbazoEkstrakto(QWidget *gepatro):QDialog(gepatro),ui(new Ui::datumbazoEkstrakto)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 ui->dosierujo->setText(QDir::homePath()+"/Gradivus/dokumentoj/eldono");
 ui->indekso->setText(QDir::homePath()+"/Gradivus/dokumentoj/eldono/indekso.txt");
 ui->artikoloj->setText(QDir::homePath()+"/Gradivus/dokumentoj/eldono/artikolo.txt");
 connect(ui->rezignu,&QPushButton::clicked,this,&datumbazoEkstrakto::priRezignu);
 connect(ui->ekstrakto,&QPushButton::clicked,this,&datumbazoEkstrakto::priEkstrakto);
}
