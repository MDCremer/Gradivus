#ifndef AGORDOJ_H
#define AGORDOJ_H

#include <QByteArray>
#include "statikajdatumoj.h"

#define AGORDO_NOMO 0
#define AGORDO_LINGVO 1
#define AGORDO_PASVORTO 2
#define AGORDO_TRANSDONOADRESO 3
#define AGORDO_VORTARO 4
#define AGORDO_STILO 5

class agordoj
{public:
  void agorduLingvaRango(QByteArray komenco,int rango) {lingvaRangoj[rango]=akiruLingvaNombro(komenco);}
  void agorduValoro(int nombro,QByteArray valoro) {valoroj[nombro]=valoro;}
  int akiruLingvaNombro(int rango) {return lingvaRangoj[rango];}
  int akiruLingvaNombro(QByteArray komenco);
  int akiruLingvaRango(QByteArray komenco);
  int akiruLingvaKvanto() {return lingvaKvanto;}
  QByteArray akiruValoro(int nombro) {return valoroj[nombro];}
  void sxargu();
 private:
  QByteArray valoroj[6];
  int lingvaRangoj[LINGVAKVANTO];
  int lingvaKvanto;
};

#endif // AGORDOJ_H
