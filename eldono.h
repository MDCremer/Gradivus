#ifndef ELDONO_H
#define ELDONO_H

#include <QByteArray>
#include <QSqlQuery>
#include "cxefafenestro.h"

class eldono
{public:
  static QByteArray indekso(QSqlQuery *informpeto,cxefaFenestro *patraObjekto);
  static QByteArray priskribo(QByteArray kodo,QSqlQuery *informpeto,cxefaFenestro *patraObjekto,bool pura);
};

#endif // ELDONO_H
