#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QUrlQuery>
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"

void identigiloj::priAkceptu()
{if(!ui->nomo->text().simplified().isEmpty())
 {if(ui->objektoKodo->text().isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    bool havebla=false;
    QByteArray malnovaLiteraturo,malnovaPagxo,malnovaObjektoKodo,malnovaSubskribo;
    qlonglong malnovaStato;
    int malnovaTipo;
    if(informpeto.exec("SELECT tipo,literaturo,pagxo,uuid,subskribo,stato FROM identigiloj WHERE etno='"+
      ui->etno->currentText().left(2)+"' AND nomo='"+ui->nomo->text().simplified().replace("'","''")+"' AND lingvo='"+
      ui->lingvo->currentText().left(2)+"';"))
    {if(informpeto.first())
     {havebla=true;
      malnovaTipo=informpeto.value("tipo").toInt();
      if(!informpeto.value("literaturo").isNull())
       malnovaLiteraturo=informpeto.value("literaturo").toByteArray();
      if(!informpeto.value("pagxo").isNull())
       malnovaPagxo=qUncompress(informpeto.value("pagxo").toByteArray());
      malnovaObjektoKodo=informpeto.value("uuid").toByteArray();
      malnovaSubskribo=informpeto.value("subskribo").toByteArray();
      malnovaStato=informpeto.value("stato").toLongLong();
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::critical(this,tr("Eraro [040]!"),informpeto.lastError().text());
    QByteArray ordono,inverso,kontribuo;
    QByteArray tempo=QString::number(QDateTime::currentDateTime().toTime_t()).toUtf8();
    if(havebla)
    {if(ui->tipo->currentIndex()!=malnovaTipo||literaturo!=QString(malnovaLiteraturo)||pagxo!=QString(malnovaPagxo)||
       ui->objektoKodo!=malnovaObjektoKodo)
     {
     }
     else
     {if(ui->kontribui->isChecked()&&malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
      {kontribuo.append("INSERT OR REPLACE INTO identigiloj (etno,nomo,lingvo,tipo,literaturo,pagxo,uuid,subskribo,stato) VALUES ('");
       kontribuo.append(ui->etno->currentText().left(2).toUtf8());
       kontribuo.append("','");
       kontribuo.append(ui->nomo->text().simplified().replace("'","''").toUtf8());
       kontribuo.append("','");
       kontribuo.append(ui->lingvo->currentText().left(2).toUtf8());
       kontribuo.append("',");
       kontribuo.append(QString::number(ui->tipo->currentIndex()).toUtf8());
       kontribuo.append(",");
       if(literaturo.isEmpty())
        kontribuo.append("NULL,");
       else
       {kontribuo.append("'");
        kontribuo.append(literaturo.replace("'","''").toUtf8());
        kontribuo.append("',");
       }
       if(pagxo.isEmpty())
        kontribuo.append("NULL,");
       else
       {kontribuo.append("x'");
        kontribuo.append(qCompress(pagxo.toUtf8()).toHex());
        kontribuo.append("',");
       }
       kontribuo.append("'");
       kontribuo.append(ui->objektoKodo->text().toUtf8());
       kontribuo.append("','");
       kontribuo.append(malnovaSubskribo.replace("'","''"));
       kontribuo.append("',");
       kontribuo.append(QString::number(malnovaStato).toUtf8());
       kontribuo.append(");");
      }
      else
       patraObjekto->spektakloMesagxon(tr("Neniuj \305\235an\304\235oj estis malkovritaj, kiu devus esti stokita!"));
    }}
    else
    {
    }
    datumbazo.close();
    if(!kontribuo.isEmpty())
    {QNetworkAccessManager *administranto=new QNetworkAccessManager(this);
     connect(administranto,&QNetworkAccessManager::finished,patraObjekto,&cxefaFenestro::kompletigitaRespondo);
     QUrlQuery parametroj;
     parametroj.addQueryItem("ago","transdono");
     parametroj.addQueryItem("kontribuanto",patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     parametroj.addQueryItem("pasvorto",patraObjekto->administranto.akiruValoro(AGORDO_PASVORTO));
     parametroj.addQueryItem("speco","identigilo");
     parametroj.addQueryItem("datumoj",kontribuo.toBase64(QByteArray::Base64UrlEncoding));
     administranto->post(QNetworkRequest(QUrl(patraObjekto->administranto.akiruValoro(AGORDO_TRANSDONOADRESO))),
       parametroj.toString().toUtf8());
   }}
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [039]!"),datumbazo.lastError().text());
  }
  else
   patraObjekto->spektakloMesagxon(tr("Nomo sen objekto kodon estas neakceptebla!"));
 }
 else
  patraObjekto->spektakloMesagxon(tr("Malplena etikedo estas neakceptebla!"));
}
