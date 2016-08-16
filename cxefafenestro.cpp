#include <QMainWindow>
#include <QWidget>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"

cxefaFenestro::cxefaFenestro(QWidget *parent):QMainWindow(parent),ui(new Ui::cxefaFenestro)
{ui->setupUi(this);
}
