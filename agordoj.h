#ifndef AGORDOJ_H
#define AGORDOJ_H

#include "statikajdatumoj.h"

class agordoj
{public:
  int akiruLingvaNombro(int rango) {return lingvaRangoj[rango];}
  int akiruLingvaKvanto() {return lingvaKvanto;}
  void sxargu();
 private:
  int lingvaRangoj[LINGVAKVANTO];
  int lingvaKvanto;
};

#endif // AGORDOJ_H
