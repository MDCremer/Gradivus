#include <QByteArray>
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>
#include "fontoselektado.h"
#include "ui_fontoselektado.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"

fontoSelektado::fontoSelektado(QWidget *gepatro,cxefaFenestro *avo,QByteArray kodo):QDialog(gepatro),
  ui(new Ui::fontoSelektado)
{ui->setupUi(this);
 avaObjekto=avo;
 ajxo=kodo;
 ui->montru->setPage(new hipertekstoPagxo(this,avaObjekto));
 connect(ui->rezignu,&QPushButton::clicked,this,&fontoSelektado::priRezignu);
 connect(ui->listo,&QListWidget::itemSelectionChanged,this,&fontoSelektado::priElektajxoSxangxo);
 connect(ui->apliku,&QPushButton::clicked,this,&fontoSelektado::priApliku);
 connect(ui->listo,&QListWidget::doubleClicked,this,&fontoSelektado::priApliku);
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(informpeto.exec("SELECT aludo FROM fontoj WHERE uuid='"+kodo+"';"))
  {while(informpeto.next())
    ui->listo->addItem(new QListWidgetItem(informpeto.value("aludo").toString()));
  }
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [088]!"),informpeto.lastError().text());
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [087]!"),datumbazo.lastError().text());
 QByteArray informo;
 if(ui->listo->count()==0)
 {informo.append("<p><b>");
  informo.append(tr("Tiu konceptu ne referencoj estas stokitaj."));
  informo.append("</b></p>\n");
 }
 ui->montru->setHtml(avaObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n"+informo+"</body>\n</html>");
}
