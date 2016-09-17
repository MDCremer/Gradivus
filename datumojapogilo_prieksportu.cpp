#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QTextStream>
#include "datumojapogilo.h"
#include "ui_datumojapogilo.h"
#include "cxefafenestro.h"

void datumojApogilo::priEksportu()
{QString eligoDosiernomo=QFileDialog::getSaveFileName(this,tr("Dosiero selektado por sekurkopioj"),QDir::homePath()+
  "/Gradivus/skriptoj/SQL/provizaro.sql",tr("SQL-dosiero")+" (*.sql)");
 if(!eligoDosiernomo.isNull())
 {QFile eligoDosiero(eligoDosiernomo);
  int linioj=0;
  eligoDosiero.open(QIODevice::WriteOnly);
  if(eligoDosiero.isOpen())
  {QProgressDialog progreso(tr("Eksporti"),tr("Abortu"),0,-1,this);
   progreso.setModal(true);
   bool pli=true;
   QTextStream eldono(&eligoDosiero);
   eldono.setCodec("UTF-8");
   eldono<<"Versio 0.01\n-- Gradivo rezerva dosiero\n";
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    if(pli&&ui->agordoj->isChecked())
    {patraObjekto->spektakloMesagxon(tr("Eksporti agordojn \342\200\246"));
     eldono<<"-- Agordoj\nBEGIN;\n";
     if(informpeto.exec("SELECT nomo,valoro FROM agordoj;"))
     {while(pli&&informpeto.next())
      {eldono<<"INSERT OR REPLACE INTO agordoj (nomo,valoro) VALUES ('";
       eldono<<informpeto.value("nomo").toByteArray();
       eldono<<"','";
       eldono<<informpeto.value("valoro").toByteArray().replace("'","''");
       eldono<<"');\n";
       progreso.setValue(++linioj);
       pli=!progreso.wasCanceled();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [008]!"),informpeto.lastError().text());
     eldono<<"COMMIT;\n";
    }
    if(pli&&ui->lingvoj->isChecked())
    {patraObjekto->spektakloMesagxon(tr("Eksporti lingvojn \342\200\246"));
     eldono<<"-- Lingvoj\nBEGIN;\n";
     if(informpeto.exec("SELECT mallongigo,rango FROM lingvoj;"))
     {while(pli&&informpeto.next())
      {eldono<<"INSERT OR REPLACE INTO lingvoj (mallongigo,rango) VALUES ('";
       eldono<<informpeto.value("mallongigo").toByteArray();
       eldono<<"',";
       eldono<<informpeto.value("rango").toByteArray();
       eldono<<");\n";
       progreso.setValue(++linioj);
       pli=!progreso.wasCanceled();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [009]!"),informpeto.lastError().text());
     eldono<<"COMMIT;";
    }
    if(pli&&ui->identigiloj->isChecked())
    {patraObjekto->spektakloMesagxon(tr("Eksporti identigilojn \342\200\246"));
     eldono<<"-- Identigiloj\nBEGIN;\n";
     if(informpeto.exec("SELECT lando,nomo,lingvo,citajxo,referenco,uuid,subskribon,stato FROM identigiloj;"))
     {while(pli&&informpeto.next())
      {eldono<<"INSERT OR REPLACE INTO identigilo (lando,nomo,lingvo,";
       if(!informpeto.value("citajxo").isNull())
        eldono<<"citajxo,";
       if(!informpeto.value("referenco").isNull())
        eldono<<"referenco,";
       eldono<<"uuid,subskribon,stato) VALUES ('";
       eldono<<informpeto.value("lando").toByteArray();
       eldono<<"','";
       eldono<<informpeto.value("nomo").toByteArray().replace("'","''");
       eldono<<"','";
       eldono<<informpeto.value("lingvo").toByteArray();
       eldono<<"','";
       if(!informpeto.value("citajxo").isNull())
       {eldono<<informpeto.value("citajxo").toByteArray().replace("'","''");
        eldono<<"','";
       }
       if(!informpeto.value("referenco").isNull())
       {eldono<<informpeto.value("referenco").toByteArray().replace("'","''");
        eldono<<"','";
       }
       eldono<<informpeto.value("uuid").toByteArray();
       eldono<<"','";
       eldono<<informpeto.value("subskribon").toByteArray();
       eldono<<"',";
       eldono<<informpeto.value("stato").toByteArray();
       eldono<<");\n";
       progreso.setValue(++linioj);
       pli=!progreso.wasCanceled();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [017]!"),informpeto.lastError().text());
     eldono<<"COMMIT;";
    }
    datumbazo.close();
    patraObjekto->spektakloMesagxon(tr("Eksportitaj %1 registroj!").arg(linioj));
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [007]!"),datumbazo.lastError().text());
   eligoDosiero.close();
  }
  accept();
}}
