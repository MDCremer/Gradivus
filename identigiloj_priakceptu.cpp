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
#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"

void identigiloj::priAkceptu()
{if(!ui->nomo->text().simplified().isEmpty())
 {if(!ui->objektoKodo->text().isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    bool havebla=false;
    QByteArray malnovaLiteraturo,malnovaPagxo,malnovaObjektoKodo,malnovaSubskribo;
    qlonglong malnovaStato;
    int malnovaTipo;
    QString aktualo(ui->etno->currentText().left(2));
    aktualo.append(": ");
    aktualo.append(ui->nomo->text().simplified());
    aktualo.append(" [");
    aktualo.append(ui->lingvo->currentText().left(2));
    aktualo.append("]");
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
       ui->objektoKodo->text()!=QString(malnovaObjektoKodo))
     {bool unua=true;
      inverso.append("UPDATE identigiloj SET ");
      ordono.append("UPDATE identigiloj SET ");
      if(ui->tipo->currentIndex()!=malnovaTipo)
      {inverso.append("tipo=");
       inverso.append(QString::number(malnovaTipo));
       ordono.append("tipo=");
       ordono.append(QString::number(ui->tipo->currentIndex()));
       unua=false;
      }
      if(literaturo!=QString(malnovaLiteraturo))
      {if(unua)
        unua=false;
       else
       {inverso.append(",");
        ordono.append(",");
       }
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
      if(ui->objektoKodo->text()!=QString(malnovaObjektoKodo))
      {if(unua)
        unua=false;
       else
       {inverso.append(",");
        ordono.append(",");
       }
       inverso.append("uuid='");
       ordono.append("uuid='");
       inverso.append(malnovaObjektoKodo);
       ordono.append(ui->objektoKodo->text());
       inverso.append("'");
       ordono.append("'");
      }
      inverso.append(",subskribo='");
      inverso.append(malnovaSubskribo.replace("'","''"));
      inverso.append("'',stato=");
      inverso.append(QString::number(malnovaStato).toUtf8());
      ordono.append(",subskribo='");
      ordono.append(malnovaSubskribo.replace("'","''"));
      if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
      {ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
       ordono.append(":");
      }
      ordono.append("',stato=");
      ordono.append(tempo);
      inverso.append(" WHERE etno='");
      ordono.append(" WHERE etno='");
      inverso.append(ui->etno->currentText().left(2).toUtf8());
      ordono.append(ui->etno->currentText().left(2).toUtf8());
      inverso.append("' AND nomo='");
      ordono.append("' AND nomo='");
      inverso.append(ui->nomo->text().simplified().replace("'","''").toUtf8());
      ordono.append(ui->nomo->text().simplified().replace("'","''").toUtf8());
      inverso.append("' AND lingvo='");
      ordono.append("' AND lingvo='");
      inverso.append(ui->lingvo->currentText().left(2).toUtf8());
      ordono.append(ui->lingvo->currentText().left(2).toUtf8());
      inverso.append("';");
      ordono.append("';");
      if(ui->kontribui->isChecked())
      {kontribuo.append("INSERT OR REPLACE INTO identigiloj (etno,nomo,lingvo,tipo,literaturo,pagxo,uuid,subskribo,stato) V\
ALUES ('");
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
       if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
       {kontribuo.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
        kontribuo.append(":");
       }
       kontribuo.append("',");
       kontribuo.append(tempo);
       kontribuo.append(");");
     }}
     else
     {if(ui->kontribui->isChecked()&&malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+
        ":"))
      {kontribuo.append("INSERT OR REPLACE INTO identigiloj (etno,nomo,lingvo,tipo,literaturo,pagxo,uuid,subskribo,stato) V\
ALUES ('");
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
    {inverso.append("DELETE FROM identigiloj WHERE etno='");
     inverso.append(ui->etno->currentText().left(2).toUtf8());
     inverso.append("' AND nomo='");
     inverso.append(ui->nomo->text().simplified().replace("'","''").toUtf8());
     inverso.append("' AND lingvo='");
     inverso.append(ui->lingvo->currentText().left(2).toUtf8());
     inverso.append("';");
     ordono.append("INSERT INTO identigiloj (etno,nomo,lingvo,tipo,literaturo,pagxo,uuid,subskribo,stato) VALUES ('");
     ordono.append(ui->etno->currentText().left(2).toUtf8());
     ordono.append("','");
     ordono.append(ui->nomo->text().simplified().replace("'","''").toUtf8());
     ordono.append("','");
     ordono.append(ui->lingvo->currentText().left(2).toUtf8());
     ordono.append("',");
     ordono.append(QString::number(ui->tipo->currentIndex()).toUtf8());
     ordono.append(",");
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
     ordono.append("'");
     ordono.append(ui->objektoKodo->text().toUtf8());
     ordono.append("',':");
     ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     ordono.append(":',");
     ordono.append(tempo);
     ordono.append(");");
     if(ui->kontribui->isChecked())
     {kontribuo.append("INSERT OR REPLACE INTO identigiloj (etno,nomo,lingvo,tipo,literaturo,pagxo,uuid,subskribo,stato) VA\
LUES ('");
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
      patraObjekto->spektakloMesagxon(tr("Identigilo '%1' savis.").arg(aktualo));
     else
      patraObjekto->spektakloMesagxon(tr("Identigilo '%1' \304\235isdatigis.").arg(aktualo));
     aktualaIdentigilo.clear();
     if(ui->limigiTipoj->currentIndex()>0||ui->lingvoLimigo->currentIndex()>0)
     {ui->limigiTipoj->setCurrentIndex(0);
      ui->lingvoLimigo->setCurrentIndex(0);
     }
     else
      sxargi();
     QList<QListWidgetItem *> kongruoj=ui->identigilojListo->findItems(aktualo,Qt::MatchExactly);
     if(kongruoj.size()>0)
      ui->identigilojListo->setCurrentItem(kongruoj.first());
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
