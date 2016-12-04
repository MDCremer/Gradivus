#include <QCheckBox>
#include <QDialog>
#include <QPushButton>
#include <QToolButton>
#include <QWidget>
#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"
#include "hipertekstopagxo.h"

fontoj::fontoj(QWidget *gepatro):QDialog(gepatro),ui(new Ui::fontoj)
{ui->setupUi(this);
 patraObjekto=(cxefaFenestro *)gepatro;
 registrilo=new rikordoRegistrilo(ui->malfaru);
 ui->montru->setPage(new hipertekstoPagxo(this,patraObjekto));
 ui->montru->setHtml(patraObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n</body>\n</html>");
 connect(ui->selektado,&QToolButton::clicked,this,&fontoj::priSelektado);
 connect(ui->reiru,&QToolButton::clicked,this,&fontoj::priReiru);
 connect(ui->enigo,&QToolButton::clicked,this,&fontoj::priEnigo);
 connect(ui->kontribui,&QCheckBox::toggled,this,&fontoj::priKontribui);
 connect(ui->vakigu,&QPushButton::clicked,this,&fontoj::priVakigu);
 connect(ui->akceptu,&QPushButton::clicked,this,&fontoj::priAkceptu);
 connect(ui->listo,&QListWidget::itemSelectionChanged,this,&fontoj::priElektajxoSxangxo);
 connect(ui->malfaru,&QPushButton::clicked,this,&fontoj::priMalfaru);
}
