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
#include "priskribo.h"
#include "ui_priskribo.h"
#include "rikordoregistrilo.h"

void priskribo::priAkceptu()
{bool havebla=false;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  QByteArray malnovaTeksto,malnovaSubskribo;
  qlonglong malnovaStato;
  if(informpeto.exec("SELECT teksto,subskribo,stato FROM priskriboj WHERE uuid='"+ajxo+"' AND lingvo='"+
    ui->lingvo->currentText().left(2)+"';"))
  {if(informpeto.first())
   {malnovaTeksto=qUncompress(informpeto.value("teksto").toByteArray());
    malnovaSubskribo=informpeto.value("subskribo").toByteArray();
    malnovaStato=informpeto.value("stato").toLongLong();
    havebla=true;
  }}
  else
   if(informpeto.lastError().isValid())
    QMessageBox::warning(this,tr("Eraro [093]!"),informpeto.lastError().text());
  QByteArray ordono,inverso,kontribuo;
  QByteArray tempo=QByteArray::number(QDateTime::currentDateTime().toTime_t());
  QByteArray teksto=ui->teksto->toPlainText().toUtf8();
  QByteArray lingvo=ui->lingvo->currentText().left(2).toUtf8();
  for(int nombro=0;nombro<bildoj.count();++nombro)
   teksto.replace("\342\234\202"+QByteArray::number(nombro)+"\360\237\223\267",bildoj[nombro]);
  if(havebla)
  {if(teksto!=malnovaTeksto)
   {inverso.append("UPDATE priskriboj SET teksto=x'");
    inverso.append(qCompress(malnovaTeksto,9).toHex());
    inverso.append("',subskribo='");
    inverso.append(malnovaSubskribo.replace("'","''"));
    inverso.append("',stato=");
    inverso.append(QByteArray::number(malnovaStato));
    inverso.append(" WHERE uuid='");
    inverso.append(ajxo);
    inverso.append("' AND lingvo='");
    inverso.append(lingvo);
    inverso.append("';");
    ordono.append("UPDATE priskriboj SET teksto=x'");
    ordono.append(qCompress(teksto,9).toHex());
    ordono.append("',subskribo='");
    ordono.append(malnovaSubskribo.replace("'","''"));
    if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
    {ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     ordono.append(":");
    }
    ordono.append("',stato=");
    ordono.append(tempo);
    ordono.append(" WHERE uuid='");
    ordono.append(ajxo);
    ordono.append("' AND lingvo='");
    ordono.append(lingvo);
    ordono.append("';");
    if(ui->kontribui->isChecked())
    {kontribuo.append("INSERT OR REPLACE INTO priskriboj (uuid,lingvo,teksto,subskribo,stato) VALUES ('");
     kontribuo.append(ajxo);
     kontribuo.append("','");
     kontribuo.append(lingvo);
     kontribuo.append("',x'");
     kontribuo.append(qCompress(teksto,9).toHex());
     kontribuo.append("','");
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
    {kontribuo.append("INSERT OR REPLACE INTO priskriboj (uuid,lingvo,teksto,subskribo,stato) VALUES ('");
     kontribuo.append(ajxo);
     kontribuo.append("','");
     kontribuo.append(lingvo);
     kontribuo.append("',x'");
     kontribuo.append(qCompress(teksto,9).toHex());
     kontribuo.append("','");
     kontribuo.append(malnovaSubskribo.replace("'","''"));
     kontribuo.append("',");
     kontribuo.append(tempo);
     kontribuo.append(");");
    }
    else
     patraObjekto->spektakloMesagxon(tr("Neniuj \305\235an\304\235oj estis malkovritaj, kiu devus esti stokita!"));
  }}
  else
  {inverso.append("DELETE FROM priskriboj WHERE uuid='");
   inverso.append(ajxo);
   inverso.append("' AND lingvo='");
   inverso.append(lingvo);
   inverso.append("';");
   ordono.append("INSERT INTO priskriboj (uuid,lingvo,teksto,subskribo,stato) VALUES ('");
   ordono.append(ajxo);
   ordono.append("','");
   ordono.append(lingvo);
   ordono.append("',x'");
   ordono.append(qCompress(teksto,9).toHex());
   ordono.append("',':");
   ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
   ordono.append(":',");
   ordono.append(tempo);
   ordono.append(");");
   if(ui->kontribui->isChecked())
   {kontribuo.append("INSERT OR REPLACE INTO priskriboj (uuid,lingvo,teksto,subskribo,stato) VALUES ('");
    kontribuo.append(ajxo);
    kontribuo.append("','");
    kontribuo.append(lingvo);
    kontribuo.append("',x'");
    kontribuo.append(qCompress(teksto,9).toHex());
    kontribuo.append("',':");
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
    patraObjekto->spektakloMesagxon(tr("Priskribo savis."));
   else
    patraObjekto->spektakloMesagxon(tr("Priskribo \304\235isdatigis."));
   ui->lingvo->setCurrentIndex(-1);
   ui->lingvo->setCurrentIndex(ui->lingvo->findText(lingvo,Qt::MatchStartsWith));
  }
  datumbazo.close();
  if(!kontribuo.isEmpty())
  {QNetworkAccessManager *administranto=new QNetworkAccessManager(this);
   connect(administranto,&QNetworkAccessManager::finished,patraObjekto,&cxefaFenestro::kompletigitaRespondo);
   QUrlQuery parametroj;
   parametroj.addQueryItem("ago","transdono");
   parametroj.addQueryItem("kontribuanto",patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
   parametroj.addQueryItem("pasvorto",patraObjekto->administranto.akiruValoro(AGORDO_PASVORTO));
   parametroj.addQueryItem("speco","priskribo");
   parametroj.addQueryItem("datumoj",kontribuo.toBase64(QByteArray::Base64UrlEncoding));
   administranto->post(QNetworkRequest(QUrl(patraObjekto->administranto.akiruValoro(AGORDO_TRANSDONOADRESO))),
     parametroj.toString().toUtf8());
 }}
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [092]!"),datumbazo.lastError().text());
}
