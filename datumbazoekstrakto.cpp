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
 ui->indekso->setText(QDir::homePath()+"/Gradivus/dokumentoj/eldono/modeloj/indekso.txt");
 ui->artikoloj->setText(QDir::homePath()+"/Gradivus/dokumentoj/eldono/modeloj/artikolo.txt");
 connect(ui->rezignu,&QPushButton::clicked,this,&datumbazoEkstrakto::priRezignu);
 connect(ui->ekstrakto,&QPushButton::clicked,this,&datumbazoEkstrakto::priEkstrakto);
 connect(ui->priDosierujo,&QPushButton::clicked,this,&datumbazoEkstrakto::priDosierujo);
 connect(ui->priIndekso,&QPushButton::clicked,this,&datumbazoEkstrakto::priIndekso);
 connect(ui->priArtikoloj,&QPushButton::clicked,this,&datumbazoEkstrakto::priArtikoloj);
}
