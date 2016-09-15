#include <QByteArray>
#include "agordoj.h"

int agordoj::akiruLingvaRango(QByteArray komenco)
{int nombro=akiruLingvaNombro(komenco);
 for(int indekso=0;indekso<lingvaKvanto;++indekso)
  if(lingvaRangoj[indekso]==nombro)
   return indekso;
 return 10;
}
