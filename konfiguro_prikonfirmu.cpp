#include <QListWidgetItem>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include "konfiguro.h"
#include "ui_konfiguro.h"
#include "agordoj.h"
#include "cxefafenestro.h"
#include "statikajdatumoj.h"

void konfiguro::priKonfirmu()
{int sxangxoNombro=0;
 if(ui->inicialoj->text()!=patraObjekto->administranto.akiruValoro(AGORDO_NOMO))
  ++sxangxoNombro;
 if((ui->kulturo->currentIndex()==0&&!patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).isEmpty())||
   (ui->kulturo->currentIndex()>0&&ui->kulturo->currentText()!=patraObjekto->administranto.akiruValoro(AGORDO_LINGVO)))
  ++sxangxoNombro;
 for(int indekso=0;indekso<lingvaKvanto;++indekso)
  if(ui->lingvoj->item(indekso)->text()!=
    statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)])
   ++sxangxoNombro;
 if(sxangxoNombro>0)
 {QSqlDatabase datumbazo=QSqlDatabase::database();
  bool dauxrigu=true;
  if(datumbazo.open())
  {QProgressDialog progreso(tr("Stokado"),tr("Abortu"),0,sxangxoNombro,this);
   progreso.setModal(true);
   int procesis=0;
   if(ui->inicialoj->text()!=patraObjekto->administranto.akiruValoro(AGORDO_NOMO))
   {registrilo->komencu();
    registrilo->aldonu("UPDATE agordoj SET valoro='"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''")+
      "' WHERE nomo='nomo';");
    dauxrigu=registrilo->plenumu("UPDATE agordoj SET valoro='"+ui->inicialoj->text().toUtf8().replace("'","''")+
      "' WHERE nomo='nomo';");
    patraObjekto->administranto.agorduValoro(AGORDO_NOMO,ui->inicialoj->text().toUtf8());
    progreso.setValue(++procesis);
    if(dauxrigu)
     dauxrigu=!progreso.wasCanceled();
   }
   if((dauxrigu&&ui->kulturo->currentIndex()==0&&!patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).isEmpty())||
     (dauxrigu&&ui->kulturo->currentIndex()>0&&
    ui->kulturo->currentText()!=patraObjekto->administranto.akiruValoro(AGORDO_LINGVO)))
   {if(procesis==0)
     registrilo->komencu();
    registrilo->aldonu("UPDATE agordoj SET valoro='"+
       patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).replace("'","''")+"' WHERE nomo='lingvo';");
    if(ui->kulturo->currentIndex()==0)
    {dauxrigu=registrilo->plenumu("UPDATE agordoj SET valoro='' WHERE nomo='lingvo';");
     patraObjekto->administranto.agorduValoro(AGORDO_LINGVO,"");
    }
    else
    {dauxrigu=registrilo->plenumu("UPDATE agordoj SET valoro='"+ui->kulturo->currentText().toUtf8().replace("'","''")+
       "' WHERE nomo='lingvo';");
     patraObjekto->administranto.agorduValoro(AGORDO_LINGVO,ui->kulturo->currentText().toUtf8());
    }
    progreso.setValue(++procesis);
    if(dauxrigu)
     dauxrigu=!progreso.wasCanceled();
   }
   for(int indekso=0;indekso<lingvaKvanto;++indekso)
   {QListWidgetItem *ero=ui->lingvoj->item(indekso);
    if(dauxrigu&&ero->text()!=statikajDatumoj::lingvoNomoj[patraObjekto->administranto.akiruLingvaNombro(indekso)])
    {if(procesis==0)
      registrilo->komencu();
     registrilo->aldonu("UPDATE lingvoj SET rango="+
       QString("%1").arg(patraObjekto->administranto.akiruLingvaRango(ero->text().left(2).toUtf8())).toUtf8()+
       " WHERE mallongigo='"+ero->text().left(2).toUtf8()+"';");
     dauxrigu=registrilo->plenumu("UPDATE lingvoj SET rango="+QString("%1").arg(indekso).toUtf8()+" WHERE mallongigo='"+
       ero->text().left(2).toUtf8()+"';");
     patraObjekto->administranto.agorduLingvaRango(ero->text().left(2).toUtf8(),indekso);
     progreso.setValue(++procesis);
     if(dauxrigu)
      dauxrigu=!progreso.wasCanceled();
   }}
   datumbazo.close();
   if(dauxrigu)
   {registrilo->fermu();
    patraObjekto->spektakloMesagxon(tr("%n \305\235ar\304\235oj estas savitaj!","",sxangxoNombro));
  }}
  else
   if(datumbazo.lastError().isValid())
    QMessageBox::critical(this,tr("Eraro [016]!"),datumbazo.lastError().text());
 }
 else
  patraObjekto->spektakloMesagxon(tr("Ekzistas neniu \305\235ar\304\235o!"));
}
