#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include "konfiguro.h"
#include "ui_konfiguro.h"
#include "agordoj.h"
#include "cxefafenestro.h"

void konfiguro::priKonfirmu()
{bool sxangxita=false;
 int sxangxoNombro=0;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {if(ui->inicialoj->text()!=patraObjekto->administranto.akiruValoro(AGORDO_NOMO))
  {registrilo->komencu();
   registrilo->aldonu("UPDATE agordoj SET valoro='"+patraObjekto->administranto.akiruValoro(AGORDO_NOMO).replace("'","''")+
    "' WHERE nomo='nomo';");
   registrilo->plenumu("UPDATE agordoj SET valoro='"+ui->inicialoj->text().toUtf8().replace("'","''")+"' WHERE nomo='nomo';");
   sxangxita=true;
   patraObjekto->administranto.agorduValoro(AGORDO_NOMO,ui->inicialoj->text().toUtf8());
   ++sxangxoNombro;
  }
  if((ui->kulturo->currentIndex()==0&&!patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).isEmpty())||
   (ui->kulturo->currentIndex()>0&&ui->kulturo->currentText()!=patraObjekto->administranto.akiruValoro(AGORDO_LINGVO)))
  {if(!sxangxita)
   {registrilo->komencu();
    sxangxita=true;
   }
   registrilo->aldonu("UPDATE agordoj SET valoro='"+patraObjekto->administranto.akiruValoro(AGORDO_LINGVO).replace("'","''")+
    "' WHERE nomo='lingvo';");
   if(ui->kulturo->currentIndex()==0)
   {registrilo->plenumu("UPDATE agordoj SET valoro='' WHERE nomo='lingvo';");
    patraObjekto->administranto.agorduValoro(AGORDO_LINGVO,"");
   }
   else
   {registrilo->plenumu("UPDATE agordoj SET valoro='"+ui->kulturo->currentText().toUtf8().replace("'","''")+
     "' WHERE nomo='lingvo';");
    patraObjekto->administranto.agorduValoro(AGORDO_LINGVO,ui->kulturo->currentText().toUtf8());
   }
   ++sxangxoNombro;
  }
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical((QWidget *)patraObjekto,tr("Eraro [016]!"),datumbazo.lastError().text());
 if(sxangxita)
 {registrilo->fermu();
  patraObjekto->spektakloMesagxon(tr("%1 ŝanĝoj estas konservitaj!").arg(sxangxoNombro));
 }
 else
  patraObjekto->spektakloMesagxon(tr("Ekzistas neniu ŝanĝo!"));
}
