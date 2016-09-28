#include <QList>
#include <QListWidgetItem>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 registrilo->malfaru();
 QByteArray faktaArtikolo=faktaAludo;
 sxargiAludoj();
 QList<QListWidgetItem *> kongruoj=ui->aludoj->findItems(faktaArtikolo,Qt::MatchExactly);
 if(kongruoj.size()>0)
  ui->aludoj->setCurrentItem(kongruoj.first());
 patraObjekto->spektakloMesagxon(tr("\305\234an\304\235oj malfaritaj!"));
 this->setCursor(Qt::ArrowCursor);
}
