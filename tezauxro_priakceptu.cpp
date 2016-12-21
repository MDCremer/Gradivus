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
  QByteArray malnovaAludo,malnovaSubskribo;
  qlonglong malnovaStato;
  if(informpeto.exec("SELECT aludo,subskribo,stato FROM semantikajrilatoj WHERE subjekto='"+ajxo+"' AND rilato="+
    QByteArray::number(ui->rilato->currentIndex())+" AND objekto='"+objekto+"';"))
  {if(informpeto.first())
   {if(informpeto.value("aludo").isNull())
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
  {if(ui->fonto->text()!=malnovaAludo)
   {inverso.append("UPDATE semantikajrilatoj SET aludo=");
    ordono.append("UPDATE semantikajrilatoj SET aludo=");
    if(malnovaAludo=="---")
     inverso.append("NULL");
    else
    {inverso.append("'");
     inverso.append(malnovaAludo);
     inverso.append("'");
    }
    ordono.append("aludo=");
    if(ui->fonto->text()=="---")
     ordono.append("NULL");
    else
    {ordono.append("'");
     ordono.append(ui->fonto->text().toUtf8());
     ordono.append("'");
    }
    inverso.append("',subskribo='");
    inverso.append(malnovaSubskribo.replace("'","''"));
    inverso.append("',stato=");
    inverso.append(QByteArray::number(malnovaStato));
    inverso.append(" WHERE subjekto='");
    inverso.append(ajxo);
    inverso.append("' AND rilato=");
    inverso.append(QByteArray::number(ui->rilato->currentIndex()));
    inverso.append(" AND objekto='");
    inverso.append(objekto);
    inverso.append("';");
    ordono.append("',subskribo='");
    ordono.append(malnovaSubskribo.replace("'","''"));
    if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
    {ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     ordono.append(":");
    }
    ordono.append("',stato=");
    ordono.append(tempo);
    ordono.append(" WHERE subjekto='");
    ordono.append(ajxo);
    ordono.append("' AND rilato=");
    ordono.append(QByteArray::number(ui->rilato->currentIndex()));
    ordono.append(" AND objekto='");
    ordono.append(objekto);
    ordono.append("';");
    if(ui->kontribui->isChecked())
    {kontribuo.append("INSERT OR REPLACE INTO semantikajrilatoj (subjekto,rilato,objekto,aludo,subskribo,stato) VALUES ('");
     kontribuo.append(ajxo);
     kontribuo.append("',");
     kontribuo.append(QByteArray::number(ui->rilato->currentIndex()));
     kontribuo.append(",'");
     kontribuo.append(objekto);
     kontribuo.append("',");
     if(ui->fonto->text()=="---")
      kontribuo.append("NULL,'");
     else
     {kontribuo.append("'");
      kontribuo.append(ui->fonto->text().toUtf8());
      kontribuo.append("','");
     }
     kontribuo.append(malnovaSubskribo.replace("'","''"));
     if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
     {kontribuo.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
      kontribuo.append(":");
     }
     kontribuo.append("',");
     kontribuo.append(tempo);
     kontribuo.append(");");
   }}
   else
   {if(ui->kontribui->isChecked()&&malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
    {kontribuo.append("INSERT OR REPLACE INTO semantikajrilatoj (subjekto,rilato,objekto,aludo,subskribo,stato) VALUES ('");
     kontribuo.append(ajxo);
     kontribuo.append("',");
     kontribuo.append(QByteArray::number(ui->rilato->currentIndex()));
     kontribuo.append(",'");
     kontribuo.append(objekto);
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
  {inverso.append("DELETE FROM semantikajrilatoj WHERE subjekto='");
   inverso.append(ajxo);
   inverso.append("' AND rilato=");
   inverso.append(QByteArray::number(ui->rilato->currentIndex()));
   inverso.append(" AND objekto='");
   inverso.append(objekto);
   inverso.append("';");
   ordono.append("INSERT INTO semantikajrilatoj (subjekto,rilato,objekto,");
   if(ui->fonto->text()!="---")
    ordono.append("aludo,");
   ordono.append("subskribo,stato) VALUES ('");
   ordono.append(ajxo);
   ordono.append("',");
   ordono.append(QByteArray::number(ui->rilato->currentIndex()));
   ordono.append(",'");
   ordono.append(objekto);
   ordono.append("','");
   if(ui->fonto->text()!="---")
   {ordono.append(ui->fonto->text().toUtf8());
    ordono.append("','");
   }
   ordono.append(":");
   ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
   ordono.append(":',");
   ordono.append(tempo);
   ordono.append(");");
   if(ui->kontribui->isChecked())
   {kontribuo.append("INSERT OR REPLACE INTO semantikajrilatoj (subjekto,rilato,objekto,aludo,subskribo,stato) VALUES ('");
    kontribuo.append(ajxo);
    kontribuo.append("',");
    kontribuo.append(QByteArray::number(ui->rilato->currentIndex()));
    kontribuo.append(",'");
    kontribuo.append(objekto);
    kontribuo.append("',");
    if(ui->fonto->text()=="---")
     kontribuo.append("NULL,':");
    else
    {kontribuo.append("'");
     kontribuo.append(ui->fonto->text().toUtf8());
     kontribuo.append("',':");
    }
    kontribuo.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
    kontribuo.append(":',");
    kontribuo.append(tempo);
    kontribuo.append(");");
  }}
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
