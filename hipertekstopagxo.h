#ifndef HIPERTEKSTOPAGXO_H
#define HIPERTEKSTOPAGXO_H

#include <QtWebEngineWidgets>
#include "cxefafenestro.h"

class hipertekstoPagxo:public QWebEnginePage
{Q_OBJECT
 public:
  hipertekstoPagxo(QObject *gepatro,cxefaFenestro *fenestro):QWebEnginePage(gepatro){radikon=fenestro;}
  bool acceptNavigationRequest(const QUrl &url,NavigationType type,bool isMainFrame);
  cxefaFenestro *radikon;
};

#endif // HIPERTEKSTOPAGXO_H
