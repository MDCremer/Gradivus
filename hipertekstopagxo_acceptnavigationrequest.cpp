#include <QByteArray>
#include <QDesktopServices>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QUrl>
#include <QtWebEngineWidgets>
#include "hipertekstopagxo.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "ui_cxefafenestro.h"
#include "eldono.h"

bool hipertekstoPagxo::acceptNavigationRequest(const QUrl &url,NavigationType type,bool isMainFrame)
{if(type==QWebEnginePage::NavigationTypeLinkClicked)
 {if(url.toString().startsWith(radikon->administranto.akiruValoro(AGORDO_VORTARO)))
  {QByteArray html=radikon->administranto.akiruValoro(AGORDO_STILO);
   html.append("<title>");
   html.append(tr("Priskribo"));
   html.append("</title>\n</head>\n<body>\n");
   html.append("</body>\n</html>");
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    html.append(eldono::priskribo(url.toString().mid(radikon->administranto.akiruValoro(AGORDO_VORTARO).length(),
      22).toUtf8(),&informpeto,radikon,1));
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(radikon,tr("Eraro [059]!"),datumbazo.lastError().text());
   radikon->montruPriskribo(html);
  }
  else
   QDesktopServices::openUrl(url);
  return false;
 }
 return true;
}
