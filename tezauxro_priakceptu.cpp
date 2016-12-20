#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUrl>
#include <QUrlQuery>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

void tezauxro::priAkceptu()
{bool havebla=false;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  QByteArray malnovaObjekto,malnovaAludo,malnovaSubskribo;
  int malnovaRilato;
  qlonglong malnovaStato;
  if(informpeto.exec("SELECT rilato,objekto,aludo,subskribo,stato FROM semantikajrilatoj WHERE subjekto='"+ajxo+"';"))
  {if(informpeto.first())
   {malnovaRilato=informpeto.value("rilato").toInt();
    malnovaObjekto=informpeto.value("objekto").toByteArray();
    if(informpeto.value("aludo").isNull())
     malnovaAludo="---";
    else
     malnovaAludo=informpeto.value("aludo").toByteArray();
    malnovaSubskribo=informpeto.value("subskribo").toByteArray();
    malnovaStato=informpeto.value("stato").toLongLong();
    havebla=true;
  }}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [110]!"),informpeto.lastError().text());
  QByteArray ordono,inverso,kontribuo;
  QByteArray tempo=QByteArray::number(QDateTime::currentDateTime().toTime_t());
  if(havebla)
  {if(ui->rilato->currentIndex()!=malnovaRilato||objekto!=malnovaObjekto||ui->fonto->text()!=malnovaAludo)
   {
   }
   else
   {if(ui->kontribui->isChecked()&&malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
    {kontribuo.append("INSERT OR REPLACE INTO semantikajrilatoj (subjekto,rilato,objekto,aludo,subskribo,stato) VALUES ('");
     kontribuo.append(ajxo);
     kontribuo.append("',");
     kontribuo.append(QByteArray::number(malnovaRilato));
     kontribuo.append(",'");
     kontribuo.append(malnovaObjekto);
     kontribuo.append("',");
     if(malnovaAludo=="---")
      kontribuo.append("NULL,'");
     else
     {kontribuo.append("'");
      kontribuo.append(malnovaAludo);
      kontribuo.append("','");
     }
     kontribuo.append(malnovaSubskribo.replace("'","''"));
     kontribuo.append("',");
     kontribuo.append(QByteArray::number(malnovaStato));
     kontribuo.append(");");
    }
    else
     patraObjekto->spektakloMesagxon(tr("Neniuj \305\235an\304\235oj estis malkovritaj, kiu devus esti stokita!"));
  }}
  else
  {
  }
  if(!inverso.isEmpty())
  {registrilo->komencu();
   registrilo->aldonu(inverso);
   registrilo->plenumu(&informpeto,ordono);
   registrilo->fermu();
   if(ordono.startsWith("INSERT"))
    patraObjekto->spektakloMesagxon(tr("Semantika rilato savis."));
   else
    patraObjekto->spektakloMesagxon(tr("Samenatika rilato \304\235isdatigis."));
   sxargi();
  }
  datumbazo.close();
  if(!kontribuo.isEmpty())
  {QNetworkAccessManager *administranto=new QNetworkAccessManager(this);
   connect(administranto,&QNetworkAccessManager::finished,patraObjekto,&cxefaFenestro::kompletigitaRespondo);
   QUrlQuery parametroj;
   parametroj.addQueryItem("ago","transdono");
   parametroj.addQueryItem("kontribuanto",patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
   parametroj.addQueryItem("pasvorto",patraObjekto->administranto.akiruValoro(AGORDO_PASVORTO));
   parametroj.addQueryItem("speco","semantika rilato");
   parametroj.addQueryItem("datumoj",kontribuo.toBase64(QByteArray::Base64UrlEncoding));
   administranto->post(QNetworkRequest(QUrl(patraObjekto->administranto.akiruValoro(AGORDO_TRANSDONOADRESO))),
     parametroj.toString().toUtf8());
 }}
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [109]!"),datumbazo.lastError().text());
}
