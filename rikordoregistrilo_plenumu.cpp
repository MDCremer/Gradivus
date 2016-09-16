#include <QByteArray>
#include <QMessageBox>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QStack>
#include "rikordoregistrilo.h"

bool rikordoRegistrilo::plenumu(QSqlQuery *registrilo,QByteArray ordono)
{bool sukceso=registrilo->exec(ordono);
 if(!sukceso)
 {while(stako.pop()!="COMMIT;");
  malfaroButono->setDisabled(stako.isEmpty());
  aktiva=false;
  if(registrilo->lastError().isValid())
   QMessageBox::warning(malfaroButono,QObject::tr("Eraro [012]!"),registrilo->lastError().text());
 }
 return sukceso;
}
