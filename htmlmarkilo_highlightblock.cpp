#include <QRegExp>
#include <QString>
#include "htmlmarkilo.h"

void htmlMarkilo::highlightBlock(const QString &teksto)
{foreach(const markaRegulo &regulo,reguloj)
 {QRegExp esprimo(regulo.sxablono);
  int indekso=esprimo.indexIn(teksto);
  while(indekso>-1)
  {int longo=esprimo.matchedLength();
   setFormat(indekso,longo,regulo.arangxo);
   indekso=esprimo.indexIn(teksto,indekso+longo);
 }}
 setCurrentBlockState(0);
 int startoIndekso=0;
 if(previousBlockState()!=1)
  startoIndekso=komentoStartoEsprimo.indexIn(teksto);
 while(startoIndekso>-1)
 {int finoIndekso=komentoFinoEsprimo.indexIn(teksto,startoIndekso);
  int komentoLongo;
  if(finoIndekso==-1)
  {setCurrentBlockState(1);
   komentoLongo=teksto.length()-startoIndekso;
  }
  else
   komentoLongo=finoIndekso-startoIndekso+komentoFinoEsprimo.matchedLength();
  setFormat(startoIndekso,komentoLongo,komentoArangxo);
  startoIndekso=komentoStartoEsprimo.indexIn(teksto,startoIndekso+komentoLongo);
}}
