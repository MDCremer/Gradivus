#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"
#include "cxefafenestro.h"
#include "agordoj.h"
#include "provajxo.h"

void datumojRestauxro::priSintakseAnalizu()
{QRegularExpressionMatch interkonsento;
 QString teksto=ui->ordono->toPlainText();
 QByteArray subskribo;
 qlonglong stato;
 provajxo vido(this,patraObjekto);
 int indekso;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(ui->sintakseAnalizu->text()=="literaturoj")
  {QByteArray aludo,kodo;
   interkonsento=QRegularExpression("\\(\\'([^\\']+|\\'{2})+\\'").match(teksto);
   if(interkonsento.hasMatch())
   {aludo=interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("[xX]\\'([0-9A-Fa-f]{2})+\\'").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {kodo=qUncompress(QByteArray::fromHex(interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8()));
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
     if(interkonsento.hasMatch())
     {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
      indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
      interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
       vido.agordiCxefsxlosilo(aludo.replace("''","'"));
       vido.agordiKodo(kodo);
       QByteArray html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
       html.append("<title>");
       html.append(aludo.replace("''","'"));
       html.append("</title>\n</head>\n<body>\n<p>");
       html.append(kodo.replace("\342\233\223\342\231\202\342\233\201/",
         patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
       html.append("</p>\n</body>\n</html>");
       vido.agordiVido(html);
       vido.agordiSubskribo(subskribo.replace("''","'"));
       QDateTime tempo;
       tempo.setTime_t(stato);
       vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
       if(informpeto.exec("SELECT html,subskribo,stato FROM literaturoj WHERE aludo='"+aludo+"';"))
       {if(informpeto.first())
        {QByteArray malnovaKodo=qUncompress(informpeto.value("html").toByteArray());
         QByteArray malnovaSubskribo=informpeto.value("subskribo").toByteArray();
         qlonglong malnovaStato=informpeto.value("stato").toLongLong();
         html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
         html.append("<title>");
         html.append(aludo.replace("''","'"));
         html.append("</title>\n</head>\n<body>\n<p>");
         html.append(malnovaKodo.replace("\342\233\223\342\231\202\342\233\201/",
           patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
         html.append("</p>\n</body>\n</html>");
         vido.agordiMalnovaDatumoj(html);
         vido.agordiMalnovaSubskribo(malnovaSubskribo);
         tempo.setTime_t(malnovaStato);
         vido.agordiMalnovaStato(tempo.toString(Qt::SystemLocaleLongDate));
         if(kodo==malnovaKodo&&subskribo.replace("''","'")==malnovaSubskribo&&stato==malnovaStato)
          vido.agordiRekomendo(tr("La cita\304\265o jam existas."));
         else
         {if(stato==malnovaStato&&kodo!=malnovaKodo)
           vido.agordiRekomendo(tr("Estas sama malnova cita\304\265o malsama enhavo."));
          else
          {if(stato==malnovaStato)
            vido.agordiRekomendo(tr("Estas sama malnova cita\304\265o kun malsamaj subskriptoj."));
           else
           {if(stato<malnovaStato)
             vido.agordiRekomendo(tr("Estas jam disponebla \304\235isdatigi via cita\304\265o."));
            else
            {if(stato>malnovaStato&&kodo==malnovaKodo)
              vido.agordiRekomendo(tr("Eksistas malnova cita\304\265o de la sama enhavo."));
             else
              vido.agordiRekomendo(tr("La nuna bibliografio estas pli malnova."));
        }}}}}
        else
        {vido.agordiMalnovaSubskribo("");
         vido.agordiMalnovaStato("");
         vido.agordiRekomendo(tr("Tia cita\304\265o ne estas disponebla ankora\305\255."));
       }}
       else
        if(informpeto.lastError().isValid())
         QMessageBox::critical(this,tr("Eraro [028]!"),informpeto.lastError().text());
       vido.exec();
  }}}}}
  if(ui->sintakseAnalizu->text()=="identigiloj")
  {
  }
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [027]!"),datumbazo.lastError().text());
}
