#ifndef HIPERTEKSTOPAGXO_H
#define HIPERTEKSTOPAGXO_H

#include <QtWebEngineWidgets>

class hipertekstoPagxo:public QWebEnginePage
{Q_OBJECT
 public:
  hipertekstoPagxo(QObject *gepatro=0):QWebEnginePage(gepatro){}
  bool acceptNavigationRequest(const QUrl &url,NavigationType type,bool isMainFrame);
};

#endif // HIPERTEKSTOPAGXO_H
