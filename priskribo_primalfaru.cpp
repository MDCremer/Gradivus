#include "priskribo.h"
#include "ui_priskribo.h"
#include "rikordoregistrilo.h"

void priskribo::priMalfaru()
{this->setCursor(Qt::WaitCursor);
 registrilo->malfaru();
 patraObjekto->spektakloMesagxon(tr("\305\234an\304\235oj malfaritaj!"));
 this->setCursor(Qt::ArrowCursor);
 ui->lingvo->setCurrentIndex(-1);
 ui->lingvo->setCurrentIndex(0);
}
