#include <QByteArray>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTreeWidgetItem>
#include "tezauxro.h"
#include "ui_tezauxro.h"
#include "rikordoregistrilo.h"

void tezauxro::priForigu()
{QTreeWidgetItem *aktualo=ui->rilatojListo->currentItem();
 if(aktualo!=0&&aktualo->type()>3000)
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  if(datumbazo.open())
  {QSqlQuery informpeto;
   QByteArray inverso("INSERT INTO semantikajrilatoj (subjekto,rilato,objekto,aludo,subskribo,stato) VALUES ('");
   inverso.append(ajxo);
   inverso.append("',");
   inverso.append(QByteArray::number(aktualo->type()-3500));
   inverso.append(",'");
   inverso.append(aktualo->toolTip(0));
   inverso.append("',");
   if(informpeto.exec("SELECT aludo,subskribo,stato FROM semantikajrilatoj WHERE subjekto='"+ajxo+"' AND rilato="+
     QByteArray::number(aktualo->type()-3500)+" AND objekto='"+aktualo->toolTip(0)+"';"))
   {if(informpeto.first())
    {if(informpeto.value("aludo").isNull())
      inverso.append("NULL,'");
     else
     {inverso.append("'");
      inverso.append(informpeto.value("aludo").toByteArray());
      inverso.append("','");
     }
     inverso.append(informpeto.value("subskribo").toByteArray().replace("'","''"));
     inverso.append("',");
     inverso.append(informpeto.value("stato").toByteArray());
     inverso.append(");");
   }}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(this,tr("Eraro [115]!"),informpeto.lastError().text());
   QByteArray ordono("DELETE FROM semantikajrilatoj WHERE subjekto='");
   ordono.append(ajxo);
   ordono.append("' AND rilato=");
   ordono.append(QByteArray::number(aktualo->type()-3500));
   ordono.append(" AND objekto='");
   ordono.append(aktualo->toolTip(0));
   ordono.append("';");
   registrilo->komencu();
   registrilo->aldonu(inverso);
   registrilo->plenumu(&informpeto,ordono);
   registrilo->fermu();
   patraObjekto->spektakloMesagxon(tr("Semantika rilato estis forigita!"));
   datumbazo.close();
   sxargi();
  }
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [114]!"),datumbazo.lastError().text());
}}
