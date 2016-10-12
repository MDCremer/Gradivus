#include <QNetworkReply>
#include "cxefafenestro.h"

void cxefaFenestro::kompletigitaRespondo(QNetworkReply *respondo)
{if(respondo->error()==QNetworkReply::NoError)
  spektakloMesagxon(respondo->readAll());
 else
  spektakloMesagxon(tr("Reto eraro: ")+respondo->errorString());
 respondo->deleteLater();
}
