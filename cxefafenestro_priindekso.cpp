#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "agordoj.h"
#include "eldono.h"

void cxefaFenestro::priIndekso()
{QByteArray html=administranto.akiruValoro(AGORDO_STILO);
 html.append("<title>");
 html.append(tr("Indekso"));
 html.append("</title>\n</head>\n<body>\n<h1>");
 html.append(tr("Indekso"));
 html.append("</h1>\n");
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  html.append(eldono::indekso(&informpeto,this));
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [054]!"),datumbazo.lastError().text());
 html.append("</body>\n</html>");
 ui->informaMontro->setHtml(html);
}
