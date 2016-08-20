#include <QDesktopServices>
#include <QUrl>
#include <QtWebEngineWidgets>
#include "hipertekstopagxo.h"

bool hipertekstoPagxo::acceptNavigationRequest(const QUrl &url,NavigationType type,bool isMainFrame)
{if(type==QWebEnginePage::NavigationTypeLinkClicked)
 {QDesktopServices::openUrl(url);
  return false;
 }
 return true;
}
