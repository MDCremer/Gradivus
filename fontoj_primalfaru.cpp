#include <QList>
#include <QListWidgetItem>
#include "fontoj.h"
#include "ui_fontoj.h"

void fontoj::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 QString aktualo=aktualaFonto;
 registrilo->malfaru();
 sxargi();
 QList<QListWidgetItem *> kongruoj=ui->listo->findItems(aktualo,Qt::MatchExactly);
 if(kongruoj.size()>0)
  ui->listo->setCurrentItem(kongruoj.first());
 patraObjekto->spektakloMesagxon(tr("\305\234an\304\235oj malfaritaj!"));
 this->setCursor(Qt::ArrowCursor);
}
