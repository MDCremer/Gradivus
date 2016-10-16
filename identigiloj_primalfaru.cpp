#include <QList>
#include <QListWidgetItem>
#include <QString>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 QString aktualo=aktualaIdentigilo;
 registrilo->malfaru();
 sxargi();
 QList<QListWidgetItem *> kongruoj=ui->identigilojListo->findItems(aktualo,Qt::MatchExactly);
 if(kongruoj.size()>0)
  ui->identigilojListo->setCurrentItem(kongruoj.first());
 patraObjekto->spektakloMesagxon(tr("\305\234an\304\235oj malfaritaj!"));
 this->setCursor(Qt::ArrowCursor);
}
