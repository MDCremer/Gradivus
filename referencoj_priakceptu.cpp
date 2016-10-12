#include <QByteArray>
#include <QDateTime>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "cxefafenestro.h"

void referencoj::priAkceptu()
{if(!ui->aludo->text().simplified().isEmpty())
 {if(!ui->teksto->toPlainText().simplified().isEmpty())
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    QByteArray faktaArtikolo=ui->aludo->text().simplified().toUtf8();
    QByteArray malnovaHtml,malnovaSubskribo;
    qlonglong malnovaStato;
    bool havebla=false;
    if(informpeto.exec("SELECT html,subskribo,stato FROM literaturoj WHERE aludo='"+faktaArtikolo.replace("'","''")+"';"))
    {if(informpeto.first())
     {havebla=true;
      malnovaHtml=qUncompress(informpeto.value("html").toByteArray());
      malnovaSubskribo=informpeto.value("subskribo").toByteArray();
      malnovaStato=informpeto.value("stato").toLongLong();
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::critical(this,tr("Eraro [021]!"),informpeto.lastError().text());
    QByteArray ordono,inverso,kontribuo;
    QByteArray tempo=QString::number(QDateTime::currentDateTime().toTime_t()).toUtf8();
    if(havebla)
    {if(malnovaHtml!=ui->teksto->toPlainText().simplified())
     {inverso.append("UPDATE literaturoj SET html=x'");
      inverso.append(qCompress(malnovaHtml,9).toHex());
      inverso.append("',subskribo='");
      inverso.append(malnovaSubskribo.replace("'","''"));
      inverso.append("',stato=");
      inverso.append(QString::number(malnovaStato).toUtf8());
      inverso.append(" WHERE aludo='");
      inverso.append(faktaArtikolo.replace("'","''"));
      inverso.append("';");
      ordono.append("UPDATE literaturoj SET html=x'");
      ordono.append(qCompress(ui->teksto->toPlainText().simplified().toUtf8(),9).toHex());
      ordono.append("',subskribo='");
      ordono.append(malnovaSubskribo.replace("'","''"));
      if(!malnovaSubskribo.contains(":"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO)+":"))
      {ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
       ordono.append(":");
      }
      ordono.append("',stato=");
      ordono.append(tempo);
      ordono.append(" WHERE aludo='");
      ordono.append(faktaArtikolo.replace("'","''"));
      ordono.append("';");
      if(ui->kontribui->isChecked())
      {kontribuo.append("INSERT OR REPLACE INTO literaturoj (aludo,html,subskribo,stato) VALUES ('");
       kontribuo.append(faktaArtikolo.replace("'","''"));
       kontribuo.append("',x'");
       kontribuo.append(qCompress(ui->teksto->toPlainText().simplified().toUtf8(),9).toHex());
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
      {kontribuo.append("INSERT OR REPLACE INTO literaturoj (aludo,html,subskribo,stato) VALUES ('");
       kontribuo.append(faktaArtikolo.replace("'","''"));
       kontribuo.append("',x'");
       kontribuo.append(qCompress(malnovaHtml).toHex());
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
    {inverso.append("DELETE FROM literaturoj WHERE aludo='");
     inverso.append(faktaArtikolo.replace("'","''"));
     inverso.append("';");
     ordono.append("INSERT INTO literaturoj (aludo,html,subskribo,stato) VALUES ('");
     ordono.append(faktaArtikolo.replace("'","''"));
     ordono.append("',x'");
     ordono.append(qCompress(ui->teksto->toPlainText().simplified().toUtf8(),9).toHex());
     ordono.append("',':");
     ordono.append(patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     ordono.append(":',");
     ordono.append(tempo);
     ordono.append(");");
     if(ui->kontribui->isChecked())
     {kontribuo.append("INSERT OR REPLACE INTO literaturoj (aludo,html,subskribo,stato) VALUES ('");
      kontribuo.append(faktaArtikolo.replace("'","''"));
      kontribuo.append("',x'");
      kontribuo.append(qCompress(ui->teksto->toPlainText().simplified().toUtf8(),9).toHex());
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
     patraObjekto->spektakloMesagxon(tr("Cita\304\265o '%1' savis.").arg(QString(faktaArtikolo)));
     sxargiAludoj();
     QList<QListWidgetItem *> kongruoj=ui->aludoj->findItems(faktaArtikolo,Qt::MatchExactly);
     if(kongruoj.size()>0)
      ui->aludoj->setCurrentItem(kongruoj.first());
    }
    datumbazo.close();
    if(!kontribuo.isEmpty())
    {QNetworkAccessManager *administranto=new QNetworkAccessManager(this);
     connect(administranto,&QNetworkAccessManager::finished,patraObjekto,&cxefaFenestro::kompletigitaRespondo);
     QUrlQuery parametroj;
     parametroj.addQueryItem("ago","transdono");
     parametroj.addQueryItem("kontribuanto",patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''"));
     parametroj.addQueryItem("pasvorto",patraObjekto->administranto.akiruValoro(AGORDO_PASVORTO));
     parametroj.addQueryItem("speco","literaturo");
     parametroj.addQueryItem("datumoj",kontribuo.toBase64(QByteArray::Base64UrlEncoding));
     administranto->post(QNetworkRequest(QUrl(patraObjekto->administranto.akiruValoro(AGORDO_TRANSDONOADRESO))),
       parametroj.toString().toUtf8());
   }}
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [020]!"),datumbazo.lastError().text());
  }
  else
   patraObjekto->spektakloMesagxon(tr("Malplena cita\304\265o estas neakceptebla!"));
 }
 else
  patraObjekto->spektakloMesagxon(tr("Malplena noto estas neakceptebla!"));
}
