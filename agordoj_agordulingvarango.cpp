#include <QByteArray>
#include "agordoj.h"
#include "statikajdatumoj.h"

void agordoj::agorduLingvaRango(QByteArray komenco,int rango)
{for(int indekso=0;indekso<LINGVAKVANTO;++indekso)
 {if(statikajDatumoj::lingvoNomoj[indekso].startsWith(komenco))
  {lingvaRangoj[indekso]=rango;
   indekso=LINGVAKVANTO;
}}}
