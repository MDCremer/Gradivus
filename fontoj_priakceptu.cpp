#include <QByteArray>
#include <QDateTime>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QUrlQuery>
#include "fontoj.h"
#include "ui_fontoj.h"
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

void fontoj::priAkceptu()
{if(ui->aludo->text().length()==3)
 {if(!literaturo.isEmpty()||!pagxo.isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    bool havebla=false;
    QByteArray malnovaLiteraturo,malnovaPagxo,malnovaSubskribo;
    qlonglong malnovaStato;
    QString aktualo(ui->aludo->text());
    if(informpeto.exec("SELECT literaturo,pagxo,subskribo,stato FROM fontoj WHERE uuid='"+ajxo+"' AND aludo='"+
      ui->aludo->text()+"';"))
    {if(informpeto.first())
     {havebla=true;
      if(!informpeto.value("literaturo").isNull())
       malnovaLiteraturo=informpeto.value("literaturo").toByteArray();
      if(!informpeto.value("pagxo").isNull())
       malnovaPagxo=qUncompress(informpeto.value("pagxo").toByteArray());
      malnovaSubskribo=informpeto.value("subskribo").toByteArray();
      malnovaStato=informpeto.value("stato").toLongLong();
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::critical(this,tr("Eraro [068]!"),informpeto.lastError().text());
    QByteArray ordono,inverso,kontribuo;
    QByteArray tempo=QString::number(QDateTime::currentDateTime().toTime_t()).toUtf8();
    if(havebla)
    {if(literaturo!=QString(malnovaLiteraturo)||pagxo!=QString(malnovaPagxo))
     {bool unua=true;
      inverso.append("UPDATE fontoj SET ");
      ordono.append("UPDATE fontoj SET ");
      if(literaturo!=QString(malnovaLiteraturo))
      {unua=false;
       inverso.append("literaturo=");
       ordono.append("literaturo=");
       if(malnovaLiteraturo.isEmpty())
        inverso.append("NULL");
       else
       {inverso.append("'");
        inverso.append(malnovaLiteraturo.replace("'","''"));
        inverso.append("'");
       }
       if(literaturo.isEmpty())
        ordono.append("NULL");
       else
       {ordono.append("'");
        ordono.append(literaturo.replace("'","''").toUtf8());
        ordono.append("'");
      }}
      if(pagxo!=QString(malnovaPagxo))
      {if(unua)
        unua=false;
       else
       {inverso.append(",");
        ordono.append(",");
       }
       inverso.append("pagxo=");
       ordono.append("pagxo=");
       if(malnovaPagxo.isEmpty())
        inverso.append("NULL");
       else
       {inverso.append("x'");
        inverso.append(qCompress(malnovaPagxo).toHex());
        inverso.append("'");
       }
       if(pagxo.isEmpty())
        ordono.append("NULL");
       else
       {ordono.append("x'");
        ordono.append(qCompress(pagxo.toUtf8()).toHex());
        ordono.append("'");
      }}
      inverso.append(",subskribo='");
      inverso.append(malnovaSubskribo.replace("'","''"));
      inverso.append("'',stato=");
      inverso.append(QString::number(malnovaStato).toUtf8());
      inverso.append(" WHERE uuid='");
      inverso.append(ajxo);
      inverso.append("' AND aludo='");
      inverso.append(ui->aludo->text().toUtf8());
      inverso.append("';");
      ordono.append(",subskribo='");
      ordono.append(malnovaSubskribo.replace("'","''"));
      if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
      {ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
       ordono.append(":");
      }
      ordono.append("',stato=");
      ordono.append(tempo);
      inverso.append(" WHERE uuid='");
      inverso.append(ajxo);
      inverso.append("' AND aludo='");
      inverso.append(ui->aludo->text().toUtf8());
      inverso.append("';");
      ordono.append(" WHERE uuid='");
      ordono.append(ajxo);
      ordono.append("' AND aludo='");
      ordono.append(ui->aludo->text().toUtf8());
      ordono.append("';");
      if(ui->kontribui->isChecked())
      {kontribuo.append("INSERT OR REPLACE INTO fontoj (uuid,aludo,literaturo,pagxo,subskribo,stato) VALUES ('");
       kontribuo.append(ajxo);
       kontribuo.append("','");
       kontribuo.append(ui->aludo->text().toUtf8());
       kontribuo.append("',");
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
      {kontribuo.append("INSERT OR REPLACE INTO fontoj (uuid,aludo,literaturo,pagxo,subskribo,stato) VALUES ('");
       kontribuo.append(ajxo);
       kontribuo.append("','");
       kontribuo.append(ui->aludo->text().toUtf8());
       kontribuo.append("',");
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
       kontribuo.append(malnovaSubskribo.replace("'","''"));
       kontribuo.append("',");
       kontribuo.append(QByteArray::number(malnovaStato));
       kontribuo.append(");");
      }
      else
       patraObjekto->spektakloMesagxon(tr("Neniuj \305\235an\304\235oj estis malkovritaj, kiu devus esti stokita!"));
    }}
    else
    {inverso.append("DELETE FROM fontoj WHERE uuid='");
     inverso.append(ajxo);
     inverso.append("' AND aludo='");
     inverso.append(ui->aludo->text().toUtf8());
     inverso.append("';");
     ordono.append("INSERT INTO fontoj (uuid,aludo,literaturo,pagxo,subskribo,stato) VALUES ('");
     ordono.append(ajxo);
     ordono.append("','");
     ordono.append(ui->aludo->text().toUtf8());
     ordono.append("',");
     if(literaturo.isEmpty())
      ordono.append("NULL,");
     else
     {ordono.append("'");
      ordono.append(literaturo.replace("'","''").toUtf8());
      ordono.append("',");
     }
     if(pagxo.isEmpty())
      ordono.append("NULL,");
     else
     {ordono.append("x'");
      ordono.append(qCompress(pagxo.toUtf8()).toHex());
      ordono.append("',");
     }
     ordono.append("':");
     ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     ordono.append(":',");
     ordono.append(tempo);
     ordono.append(");");
     if(ui->kontribui->isChecked())
     {kontribuo.append("INSERT OR REPLACE INTO fontoj (uuid,aludo,literaturo,pagxo,subskribo,stato) VALUES ('");
      kontribuo.append(ajxo);
      kontribuo.append("','");
      kontribuo.append(ui->aludo->text().toUtf8());
      kontribuo.append("',");
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
      kontribuo.append("':");
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
      patraObjekto->spektakloMesagxon(tr("Fonto '%1' savis.").arg(aktualo));
     else
      patraObjekto->spektakloMesagxon(tr("Fonto '%1' \304\235isdatigis.").arg(aktualo));
     aktualaFonto.clear();
     sxargi();
     QList<QListWidgetItem *> kongruoj=ui->listo->findItems(aktualo,Qt::MatchExactly);
     if(kongruoj.size()>0)
      ui->listo->setCurrentItem(kongruoj.first());
    }
    datumbazo.close();
    if(!kontribuo.isEmpty())
    {QNetworkAccessManager *administranto=new QNetworkAccessManager(this);
     connect(administranto,&QNetworkAccessManager::finished,patraObjekto,&cxefaFenestro::kompletigitaRespondo);
     QUrlQuery parametroj;
     parametroj.addQueryItem("ago","transdono");
     parametroj.addQueryItem("kontribuanto",patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     parametroj.addQueryItem("pasvorto",patraObjekto->administranto.akiruValoro(AGORDO_PASVORTO));
     parametroj.addQueryItem("speco","fonto");
     parametroj.addQueryItem("datumoj",kontribuo.toBase64(QByteArray::Base64UrlEncoding));
     administranto->post(QNetworkRequest(QUrl(patraObjekto->administranto.akiruValoro(AGORDO_TRANSDONOADRESO))),
       parametroj.toString().toUtf8());
   }}
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [067]!"),datumbazo.lastError().text());
  }
  else
   patraObjekto->spektakloMesagxon(tr("Malplena referenco estas neakceptebla!"));
 }
 else
  patraObjekto->spektakloMesagxon(tr("La aludo estu tri signojn longa!"));
}
