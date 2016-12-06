#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QProgressDialog>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include "datumbazoekstrakto.h"
#include "ui_datumbazoekstrakto.h"
#include "cxefafenestro.h"
#include "eldono.h"

void datumbazoEkstrakto::priEkstrakto()
{QDir dosierujo(ui->dosierujo->text());
 if(dosierujo.exists())
 {QFile indekso(ui->indekso->text());
  if(indekso.open(QIODevice::ReadOnly|QIODevice::Text))
  {QByteArray indeksoModelo=indekso.readAll();
   indekso.close();
   if(indeksoModelo.indexOf("<!-- GRADIVUS -->")>-1)
   {QFile artikolo(ui->artikoloj->text());
    if(artikolo.open(QIODevice::ReadOnly|QIODevice::Text))
    {QByteArray artikoloModelo=artikolo.readAll();
     artikolo.close();
     if(artikoloModelo.indexOf("<!-- GRADIVUS -->")>-1)
     {QFile indeksoEligo(ui->dosierujo->text()+"/index.html");
      if(indeksoEligo.open(QIODevice::WriteOnly|QIODevice::Text))
      {QSqlDatabase datumbazo=QSqlDatabase::database();
       if(datumbazo.open())
       {QSqlQuery informpeto;
        indeksoModelo.replace("<!-- GRADIVUS -->",eldono::indekso(&informpeto,patraObjekto));
        indeksoEligo.write(indeksoModelo);
        indeksoEligo.close();
        bool pli=true;
        QStringList kodoj;
        if(informpeto.exec("SELECT DISTINCT uuid FROM identigiloj;"))
        {while(informpeto.next())
          kodoj.append(informpeto.value("uuid").toString());
        }
        else
        {if(informpeto.lastError().isValid())
          QMessageBox::warning(0,"Eraro [101]!",informpeto.lastError().text());
         pli=false;
        }
        int grado=0;
        if(!ui->permesita->isChecked())
         grado=1;
        QProgressDialog progreso(tr("Ekstrakti"),tr("Abortu"),0,kodoj.size(),this);
        progreso.setModal(true);
        for(int nombro=0;nombro<kodoj.size();++nombro)
        {QByteArray eligo(artikoloModelo);
         eligo.replace("<!-- GRADIVUS -->",eldono::priskribo(kodoj.at(nombro).toUtf8(),&informpeto,patraObjekto,grado));
         QFile artikoloEligo(ui->dosierujo->text()+"/"+kodoj.at(nombro)+".html");
         if(artikoloEligo.open(QIODevice::WriteOnly|QIODevice::Text))
         {artikoloEligo.write(eligo);
          artikoloEligo.close();
          progreso.setValue(nombro);
         }
         else
         {patraObjekto->spektakloMesagxon(tr("La eligo dosiero por la artikolo (%1) ne malfermis!").arg(kodoj.at(nombro)));
          pli=false;
        }}
        progreso.setValue(kodoj.size());
        datumbazo.close();
        if(pli)
         accept();
       }
      }
      else
       patraObjekto->spektakloMesagxon(tr("La eligo dosiero por la registro ne malfermis!"));
     }
     else
      patraObjekto->spektakloMesagxon(tr("La modelo por la artikoloj estas malebligita!"));
    }
    else
     patraObjekto->spektakloMesagxon(tr("La specifita modelo por la artikoloj ne ekzistas!"));
   }
   else
    patraObjekto->spektakloMesagxon(tr("La modelo por la registro estas malebligita!"));
  }
  else
   patraObjekto->spektakloMesagxon(tr("La specifita modelo por la registro ne ekzistas!"));
 }
 else
  patraObjekto->spektakloMesagxon(tr("La donita dosierujo ne ekzistas!"));
}
