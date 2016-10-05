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
#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"

void datumojRestauxro::priSxargi()
{QString dosieroNomo=QFileDialog::getOpenFileName(this,tr("Dosiera elekto por legado"),QDir::homePath()+
   "/Gradivus/skriptoj/SQL/",tr("SQL-Dosiero")+" (*.sql)");
 if(!dosieroNomo.isNull())
 {QProgressDialog pasxo(tr("Importado"),tr("Rezignu"),0,-1,this);
  pasxo.setModal(true);
  bool dauxrigu=true;
  int nombro=0;
  QFile dosiero(dosieroNomo);
  if(dosiero.open(QIODevice::ReadOnly|QIODevice::Text))
  {QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery registrilo;
    QTextStream enigo(&dosiero);
    enigo.setCodec("UTF-8");
    while(dauxrigu&&!enigo.atEnd())
    {QString linio=enigo.readLine();
     if(linio.endsWith("\n"))
      linio.truncate(linio.length()-QString("\n").length());
     if(!linio.isEmpty()&&!linio.startsWith("--"))
     {if(linio.endsWith(";"))
      {if(ui->enmetiAuxIgnori->isChecked())
        if(linio.startsWith("INSERT OR REPLACE INTO "))
         linio.replace(10,7,"IGNORE ");
       if(registrilo.exec(linio))
       {pasxo.setValue(++nombro);
        dauxrigu=!pasxo.wasCanceled();
       }
       else
       {if(registrilo.lastError().isValid())
         QMessageBox::warning(this,tr("Eraro [032]!"),registrilo.lastError().text());
        dauxrigu=false;
    }}}}
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [031]!"),datumbazo.lastError().text());
  }
  else
   patraObjekto->spektakloMesagxon(tr("Dosiero ne povis esti malfermita!"));
}}
