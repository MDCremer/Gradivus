#ifndef AGORDOJ_H
#define AGORDOJ_H

#include <QByteArray>
#include "statikajdatumoj.h"

#define AGORDO_NOMO 0
#define AGORDO_LINGVO 1

class agordoj
{public:
  int akiruLingvaNombro(int rango) {return lingvaRangoj[rango];}
  int akiruLingvaKvanto() {return lingvaKvanto;}
  QByteArray akiruValoro(int nombro) {return valoroj[nombro];}
  void sxargu();
 private:
  QByteArray valoroj[2];
  int lingvaRangoj[LINGVAKVANTO];
  int lingvaKvanto;
};

#endif // AGORDOJ_H
