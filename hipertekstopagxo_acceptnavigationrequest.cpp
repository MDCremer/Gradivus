#include <QDesktopServices>
#include <QMessageBox>
#include <QString>
#include <QUrl>
#include <QtWebEngineWidgets>
#include "hipertekstopagxo.h"
#include "cxefafenestro.h"
#include "agordoj.h"

bool hipertekstoPagxo::acceptNavigationRequest(const QUrl &url,NavigationType type,bool isMainFrame)
{if(type==QWebEnginePage::NavigationTypeLinkClicked)
 {if(url.toString().startsWith(radikon->administranto.akiruValoro(AGORDO_VORTARO)))
  {QString kodo=url.toString().mid(radikon->administranto.akiruValoro(AGORDO_VORTARO).length(),22);
   QMessageBox::information(radikon,"sencimigi",kodo);
  }
  else
   QDesktopServices::openUrl(url);
  return false;
 }
 return true;
}
