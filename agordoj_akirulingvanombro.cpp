#include <QByteArray>
#include "agordoj.h"
#include "statikajdatumoj.h"

int agordoj::akiruLingvaNombro(QByteArray komenco)
{for(int indekso=0;indekso<LINGVAKVANTO;++indekso)
  if(statikajDatumoj::lingvoNomoj[indekso].startsWith(komenco))
   return indekso;
 return -1;
}
