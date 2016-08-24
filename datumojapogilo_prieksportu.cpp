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

void datumojApogilo::priExportu()
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
    {eldono<<"-- Agordoj\nBEGIN;\n";
     if(informpeto.exec("SELECT nomo,valoro FROM agordoj;"))
     {while(pli&&informpeto.next())
      {eldono<<"INSERT OR REPLACE INTO agordoj (nomo,valoro) VALUES ('";
       eldono<<informpeto.value("nomo").toByteArray();
       eldono<<"','";
       eldono<<informpeto.value("valoro").toByteArray().replace("'","''");
       eldono<<"');\n";
       progreso.setValue(++linioj);
       pli=progreso.wasCanceled();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [008]!"),informpeto.lastError().text());
     eldono<<"COMMIT;\n";
    }
    if(pli&&ui->lingvoj->isChecked())
    {eldono<<"-- Lingvoj\nBEGIN;\n";
     if(informpeto.exec("SELECT mallongigo,rango FROM lingvoj;"))
     {while(pli&&informpeto.next())
      {eldono<<"INSERT OR REPLACE INTO lingvoj (mallongigo,rango) VALUES ('";
       eldono<<informpeto.value("mallongigo").toByteArray();
       eldono<<"',";
       eldono<<informpeto.value("rango").toByteArray();
       eldono<<");\n";
       progreso.setValue(++linioj);
       pli=progreso.wasCanceled();
     }}
     else
      if(informpeto.lastError().isValid())
       QMessageBox::warning(this,tr("Eraro [009]"),informpeto.lastError().text());
     eldono<<"COMMIT;";
    }
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [007]!"),datumbazo.lastError().text());
   eligoDosiero.close();
  }
  accept();
}}
