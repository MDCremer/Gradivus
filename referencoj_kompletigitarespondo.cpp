#include <QNetworkReply>
#include "referencoj.h"
#include "cxefafenestro.h"

void referencoj::kompletigitaRespondo(QNetworkReply *respondo)
{if(respondo->error()==QNetworkReply::NoError)
  patraObjekto->spektakloMesagxon(respondo->readAll());
 else
  patraObjekto->spektakloMesagxon(tr("Reto eraro: ")+respondo->errorString());
 respondo->deleteLater();
}
