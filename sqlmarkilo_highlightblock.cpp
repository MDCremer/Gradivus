#include <QRegularExpressionMatch>
#include <QString>
#include <QToolButton>
#include "sqlmarkilo.h"

void sqlMarkilo::highlightBlock(const QString &teksto)
{QRegularExpressionMatch interkonsento;
 bool rekonis=false;
 interkonsento=literaturoj.match(teksto);
 if(interkonsento.hasMatch())
 {int indekso=interkonsento.capturedStart();
  int longo=interkonsento.capturedLength();
  setFormat(indekso,longo,rekonisStrukturo);
  asociitaButono->setText("literaturoj");
  rekonis=true;
 }
 interkonsento=identigiloj.match(teksto);
 if(interkonsento.hasMatch())
 {int indekso=interkonsento.capturedStart();
  int longo=interkonsento.capturedLength();
  setFormat(indekso,longo,rekonisStrukturo);
  asociitaButono->setText("identigiloj");
  rekonis=true;
 }
 interkonsento=fontoj.match(teksto);
 if(interkonsento.hasMatch())
 {int indekso=interkonsento.capturedStart();
  int longo=interkonsento.capturedLength();
  setFormat(indekso,longo,rekonisStrukturo);
  asociitaButono->setText("fontoj");
  rekonis=true;
 }
 asociitaButono->setEnabled(rekonis);
 if(!rekonis)
  asociitaButono->setText(tr("nekonata"));
}
