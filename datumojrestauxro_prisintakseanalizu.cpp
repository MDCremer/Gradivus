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
#include "provajxo.h"

void datumojRestauxro::priSintakseAnalizu()
{QRegularExpressionMatch interkonsento;
 QString teksto=ui->ordono->toPlainText();
 QByteArray subskribo;
 qlonglong stato;
 provajxo vido(this);
 int indekso;
 QSqlDatabase datumbazo=QSqlDatabase::database();
 if(datumbazo.open())
 {QSqlQuery informpeto;
  if(ui->sintakseAnalizu->text()=="literaturoj")
  {QByteArray aludo,html;
   interkonsento=QRegularExpression("\\(\\'([^\\']+|\\'{2})+\\'").match(teksto);
   if(interkonsento.hasMatch())
   {aludo=interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("x\\'([0-9A-Fa-f]{2})+\\'").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {html=qUncompress(QByteArray::fromHex(interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8()));
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
     if(interkonsento.hasMatch())
     {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
      indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
      interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
       vido.agordiCxefsxlosilo(aludo.replace("''","'"));
       vido.agordiKodo(html);
       vido.agordiSubskribo(subskribo.replace("''","'"));
       QDateTime tempo;
       tempo.setTime_t(stato);
       vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
       if(informpeto.exec("SELECT html,subskribo,stato FROM literaturoj WHERE aludo='"+aludo+"';"))
       {if(informpeto.first())
        {QByteArray malnovaHtml=qUncompress(informpeto.value("html").toByteArray());
         QByteArray malnovaSubskribo=informpeto.value("subskribo").toByteArray();
         qlonglong malnovaStato=informpeto.value("stato").toLongLong();
        }
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
