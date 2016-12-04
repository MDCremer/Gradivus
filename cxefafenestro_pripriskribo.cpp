#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "kodoselektado.h"
#include "eldono.h"

void cxefaFenestro::priPriskribo()
{kodoSelektado selektado(this,this);
 if(selektado.exec()==QDialog::Accepted)
 {QByteArray html=administranto.akiruValoro(AGORDO_STILO);
  html.append("<title>");
  html.append(tr("Priskribo"));
  html.append("</title>\n</head>\n<body>\n");
  html.append("</body>\n</html>");
  QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   html.append(eldono::priskribo(selektado.akiruKodo().toUtf8(),&informpeto,this,1));
   datumbazo.close();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [060]!"),datumbazo.lastError().text());
  montruPriskribo(html);
}}
