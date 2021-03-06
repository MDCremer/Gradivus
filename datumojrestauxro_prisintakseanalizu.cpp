#include <QByteArray>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QRegExp>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
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
  {QByteArray etno,nomo,lingvo,tipo,literaturo,pagxo,uuid;
   interkonsento=QRegularExpression("\\(\\'[A-Z]{2}\\',").match(teksto);
   if(interkonsento.hasMatch())
   {etno=interkonsento.captured().mid(2,2).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("\\'([^\\']+|\\'{2})+\\',").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {nomo=interkonsento.captured().mid(1,interkonsento.capturedLength()-3).toUtf8();
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("\\'[a-z]{2}\\',").match(teksto,indekso);
     if(interkonsento.hasMatch())
     {lingvo=interkonsento.captured().mid(1,interkonsento.capturedLength()-3).toUtf8();
      indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
      interkonsento=QRegularExpression("[0-9]+,").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {tipo=interkonsento.captured().left(interkonsento.capturedLength()-1).toUtf8();
       indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
       interkonsento=QRegularExpression("(NULL|\\'([^\\']+|\\'{2})+\\'),").match(teksto,indekso);
       if(interkonsento.hasMatch())
       {if(interkonsento.captured()!="NULL,")
         literaturo=interkonsento.captured().mid(1,interkonsento.capturedLength()-3).toUtf8();
        indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
        interkonsento=QRegularExpression("(NULL|[xX]\\'([0-9A-Fa-f]{2})+\\'),").match(teksto,indekso);
        if(interkonsento.hasMatch())
        {if(interkonsento.captured()!="NULL,")
          pagxo=qUncompress(QByteArray::fromHex(interkonsento.captured().mid(2,interkonsento.capturedLength()-3).toUtf8()));
         indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
         interkonsento=QRegularExpression("\\'[a-zA-Z0-9_-]{22}\\',").match(teksto,indekso);
         if(interkonsento.hasMatch())
         {uuid=interkonsento.captured().mid(1,22).toUtf8();
          indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
          interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
          if(interkonsento.hasMatch())
          {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
           indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
           interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
           if(interkonsento.hasMatch())
           {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
            vido.agordiCxefsxlosilo(etno+": "+nomo.replace("''","'")+" ["+lingvo+"]");
            vido.agordiKodo(pagxo);
            QByteArray html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
            html.append("<title>");
            html.append(etno+": "+nomo.replace("''","'")+" ["+lingvo+"]");
            html.append("</title>\n</head>\n<body>\n<table>\n<tr>\n<td>");
            html.append(tr("Tipo:").toUtf8());
            html.append("</td>\n<td>");
            if(tipo.toInt()<5)
             html.append(patraObjekto->identigiloTipoj[tipo.toInt()]);
            else
             html.append(tipo);
            html.append("</td>\n</tr>\n<tr>\n<td>");
            html.append(tr("Objekto kodo:"));
            html.append("</td>\n<td>");
            html.append(uuid);
            html.append("</td>\n</tr>\n<tr>\n<td>");
            html.append(tr("Fonto:"));
            html.append("</td>\n<td>");
            if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo+"';"))
            {if(informpeto.first())
              html.append("<i>"+qUncompress(informpeto.value("html").toByteArray())+"</i>");
             else
              html.append(tr("<i>(nekonata literaturo)</i>").toUtf8());
            }
            else
             if(informpeto.lastError().isValid())
              QMessageBox::critical(this,tr("Eraro [051]!"),informpeto.lastError().text());
            html.append(pagxo.replace("\342\233\223\342\231\202\342\233\201/",
              patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
            html.append("</td>\n</tr>\n</table>\n</body>\n</html>");
            vido.agordiVido(html);
            vido.agordiSubskribo(subskribo.replace("''","'"));
            QDateTime tempo;
            tempo.setTime_t(stato);
            vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
            QByteArray malnovaTipo,malnovaLiteraturo,malnovaPagxo,malnovaUuid,malnovaSubskribo;
            qlonglong malnovaStato;
            bool havebla=false;
            if(informpeto.exec("SELECT tipo,literaturo,pagxo,uuid,subskribo,stato FROM identigiloj WHERE etno='"+etno+
              "' AND nomo='"+nomo+"' AND lingvo='"+lingvo+"';"))
            {if(informpeto.first())
             {malnovaTipo=informpeto.value("tipo").toByteArray();
              if(!informpeto.value("literaturo").isNull())
               malnovaLiteraturo=informpeto.value("literaturo").toByteArray();
              if(!informpeto.value("pagxo").isNull())
               malnovaPagxo=qUncompress(informpeto.value("pagxo").toByteArray());
              malnovaUuid=informpeto.value("uuid").toByteArray();
              malnovaSubskribo=informpeto.value("subskribo").toByteArray();
              malnovaStato=informpeto.value("stato").toLongLong();
              havebla=true;
              vido.agordiMalnovaSubskribo(malnovaSubskribo);
              tempo.setTime_t(malnovaStato);
              vido.agordiMalnovaStato(tempo.toString(Qt::SystemLocaleLongDate));
              html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
              html.append("<title>");
              html.append(etno+": "+nomo.replace("''","'")+" ["+lingvo+"]");
              html.append("</title>\n</head>\n<body>\n<table>\n<tr>\n<td>");
              html.append(tr("Tipo:").toUtf8());
              html.append("</td>\n<td>");
              if(malnovaTipo.toInt()<5)
               html.append(patraObjekto->identigiloTipoj[malnovaTipo.toInt()]);
              else
               html.append(malnovaTipo);
              html.append("</td>\n</tr>\n<tr>\n<td>");
              html.append(tr("Objekto kodo:"));
              html.append("</td>\n<td>");
              html.append(malnovaUuid);
              html.append("</td>\n</tr>\n<tr>\n<td>");
              html.append(tr("Fonto:"));
              html.append("</td>\n<td>");
              if(literaturo==malnovaLiteraturo&&pagxo==malnovaPagxo&&uuid==malnovaUuid&&subskribo.replace("''","'")==
                malnovaSubskribo&&stato==malnovaStato)
               vido.agordiRekomendo(tr("La identigilo jam existas."));
              else
              {if(stato==malnovaStato&&(literaturo!=malnovaLiteraturo||pagxo!=malnovaPagxo||uuid!=malnovaUuid||
                 tipo!=malnovaTipo))
                vido.agordiRekomendo(tr("Estas sama malnova identigilo malsama enhavo."));
               else
               {if(stato==malnovaStato)
                 vido.agordiRekomendo(tr("Estas sama malnova identigilo kun malsamaj subskriptoj."));
                else
                {if(stato<malnovaStato)
                  vido.agordiRekomendo(tr("Estas jam disponebla \304\235isdatigi via identigilo."));
                 else
                 {if(stato>malnovaStato&&literaturo==malnovaLiteraturo&&pagxo==malnovaPagxo&&uuid==malnovaUuid)
                   vido.agordiRekomendo(tr("Eksistas malnova identigilo de la sama enhavo."));
                  else
                   vido.agordiRekomendo(tr("La nuna identigilo estas pli malnova."));
             }}}}}
             else
             {vido.agordiMalnovaSubskribo("");
              vido.agordiMalnovaStato("");
              vido.agordiRekomendo(tr("Tia identigilo ne estas disponebla ankora\305\255."));
            }}
            else
             if(informpeto.lastError().isValid())
              QMessageBox::critical(this,tr("Eraro [052]!"),informpeto.lastError().text());
            if(havebla)
            {if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+malnovaLiteraturo.replace("'","''")+"';"))
             {if(informpeto.first())
               html.append(qUncompress(informpeto.value("html").toByteArray()));
             }
             else
              if(informpeto.lastError().isValid())
               QMessageBox::critical(this,tr("Eraro [053]!"),informpeto.lastError().text());
             html.append(malnovaPagxo.replace("\342\233\223\342\231\202\342\233\201/",
               patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
             html.append("</td>\n</tr>\n</table>\n</body>\n</html>");
             vido.agordiMalnovaDatumoj(html);
            }
            vido.exec();
  }}}}}}}}}}
  if(ui->sintakseAnalizu->text()=="fontoj")
  {QByteArray aludo,literaturo,pagxo,uuid;
   interkonsento=QRegularExpression("\\(\\'[a-zA-Z0-9_-]{22}\\',").match(teksto);
   if(interkonsento.hasMatch())
   {uuid=interkonsento.captured().mid(2,22).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("\\'[a-zA-Z0-9]{3}\\',").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {aludo=interkonsento.captured().mid(1,3).toUtf8();
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("(NULL|\\'([^\\']+|\\'{2})+\\'),").match(teksto,indekso);
     if(interkonsento.hasMatch())
     {if(interkonsento.captured()!="NULL,")
       literaturo=interkonsento.captured().mid(1,interkonsento.capturedLength()-3).toUtf8();
      indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
      interkonsento=QRegularExpression("(NULL|[xX]\\'([0-9A-Fa-f]{2})+\\'),").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {if(interkonsento.captured()!="NULL,")
        pagxo=qUncompress(QByteArray::fromHex(interkonsento.captured().mid(2,interkonsento.capturedLength()-3).toUtf8()));
       indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
       interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
       if(interkonsento.hasMatch())
       {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
        indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
        interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
        if(interkonsento.hasMatch())
        {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
         vido.agordiCxefsxlosilo(uuid+":"+aludo);
         vido.agordiKodo(pagxo);
         QByteArray html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
         html.append("<title>");
         html.append(uuid+":"+aludo);
         html.append("</title>\n</head>\n<body>\n<table>\n<tr>\n<td>");
         html.append(tr("Identigiloj:"));
         html.append("</td>\n<td>");
         QListWidget *nomoj=new QListWidget();
         nomoj->setSortingEnabled(true);
         if(informpeto.exec("SELECT etno,nomo,lingvo,tipo FROM identigiloj WHERE uuid='"+uuid+"';"))
         {while(informpeto.next())
           nomoj->addItem(new QListWidgetItem(informpeto.value("etno").toString()+informpeto.value("tipo").toString()+
             informpeto.value("nomo").toString()+informpeto.value("lingvo").toString()));
         }
         else
          if(informpeto.lastError().isValid())
           QMessageBox::critical(this,tr("Eraro [083]!"),informpeto.lastError().text());
         QByteArray identigiloj,aktualaEtno("xx");
         if(nomoj->count()==0)
          identigiloj.append(tr("<i>(nekonata koncepto)</i>"));
         else
         {bool unua=true;
          for(int nombro=0;nombro<nomoj->count();++nombro)
          {if(!nomoj->item(nombro)->text().startsWith(aktualaEtno))
           {if(nombro>0)
             identigiloj.append(" ");
            aktualaEtno=nomoj->item(nombro)->text().left(2).toUtf8();
            identigiloj.append(aktualaEtno);
            identigiloj.append(": ");
            unua=true;
           }
           if(unua)
            unua=false;
           else
            identigiloj.append(", ");
           identigiloj.append(nomoj->item(nombro)->text().mid(3,nomoj->item(nombro)->text().length()-5).toUtf8());
           identigiloj.append(" [");
           identigiloj.append(nomoj->item(nombro)->text().right(2).toUtf8());
           identigiloj.append("]");
         }}
         html.append(identigiloj);
         html.append("</td>\n</tr>\n<td>");
         html.append(tr("Fonto:"));
         html.append("</td>\n<td>");
         if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+literaturo+"';"))
         {if(informpeto.first())
           html.append("<i>"+qUncompress(informpeto.value("html").toByteArray())+"</i>");
          else
           html.append(tr("<i>(nekonata literaturo)</i>").toUtf8()+literaturo);
         }
         else
          if(informpeto.lastError().isValid())
           QMessageBox::critical(this,tr("Eraro [080]!"),informpeto.lastError().text());
         html.append(pagxo.replace("\342\233\223\342\231\202\342\233\201/",
           patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
         html.append("</td>\n</tr>\n</table></body>\n</html>");
         vido.agordiVido(html);
         vido.agordiSubskribo(subskribo.replace("''","'"));
         QDateTime tempo;
         tempo.setTime_t(stato);
         vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
         QByteArray malnovaLiteraturo,malnovaPagxo,malnovaSubskribo;
         qlonglong malnovaStato;
         bool havebla=false;
         if(informpeto.exec("SELECT literaturo,pagxo,subskribo,stato FROM fontoj WHERE uuid='"+uuid+"' AND aludo='"+aludo+
           "';"))
         {if(informpeto.first())
          {if(!informpeto.value("literaturo").isNull())
            malnovaLiteraturo=informpeto.value("literaturo").toByteArray();
           if(!informpeto.value("pagxo").isNull())
            malnovaPagxo=qUncompress(informpeto.value("pagxo").toByteArray());
           malnovaSubskribo=informpeto.value("subskribo").toByteArray();
           malnovaStato=informpeto.value("stato").toLongLong();
           havebla=true;
           vido.agordiMalnovaSubskribo(malnovaSubskribo);
           tempo.setTime_t(malnovaStato);
           vido.agordiMalnovaStato(tempo.toString(Qt::SystemLocaleLongDate));
           html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
           html.append("<title>");
           html.append(uuid+":"+aludo);
           html.append("</title>\n</head>\n<body>\n<table>\n<tr>\n<td>");
           html.append(tr("Identigiloj:"));
           html.append("</td>\n<td>");
           html.append(identigiloj);
           html.append("</td>\n</tr>\n<td>");
           html.append(tr("Fonto:"));
           html.append("</td>\n<td>");
           if(literaturo==malnovaLiteraturo&&pagxo==malnovaPagxo&&subskribo.replace("''","'")==malnovaSubskribo&&
             stato==malnovaStato)
            vido.agordiRekomendo(tr("La fonto jam existas."));
           else
           {if(stato==malnovaStato&&(literaturo!=malnovaLiteraturo||pagxo!=malnovaPagxo))
             vido.agordiRekomendo(tr("Estas sama malnova fonto malsama enhavo."));
            else
            {if(stato==malnovaStato)
              vido.agordiRekomendo(tr("Estas sama malnova fonto kun malsamaj subskriptoj."));
             else
             {if(stato<malnovaStato)
               vido.agordiRekomendo(tr("Estas jam disponebla \304\235isdatigi via fonto."));
              else
              {if(stato>malnovaStato&&literaturo==malnovaLiteraturo&&pagxo==malnovaPagxo)
                vido.agordiRekomendo(tr("Eksistas malnova fonto de la sama enhavo."));
               else
                vido.agordiRekomendo(tr("La nuna fonto estas pli malnova."));
          }}}}}
          else
          {vido.agordiMalnovaSubskribo("");
           vido.agordiMalnovaStato("");
           vido.agordiRekomendo(tr("Tia fonto ne estas disponebla ankora\305\255."));
         }}
         else
          if(informpeto.lastError().isValid())
           QMessageBox::critical(this,tr("Eraro [081]!"),informpeto.lastError().text());
         if(havebla)
         {if(informpeto.exec("SELECT html FROM literaturoj WHERE aludo='"+malnovaLiteraturo.replace("'","''")+"';"))
          {if(informpeto.first())
            html.append(qUncompress(informpeto.value("html").toByteArray()));
          }
          else
           if(informpeto.lastError().isValid())
            QMessageBox::critical(this,tr("Eraro [082]!"),informpeto.lastError().text());
          html.append(malnovaPagxo.replace("\342\233\223\342\231\202\342\233\201/",
            patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
          html.append("</td>\n</tr>\n</table></body>\n</html>");
          vido.agordiMalnovaDatumoj(html);
         }
         vido.exec();
  }}}}}}}
  if(ui->sintakseAnalizu->text()=="priskriboj")
  {QByteArray uuid,lingvo,priskribo;
   interkonsento=QRegularExpression("\\(\\'[a-zA-Z0-9_-]{22}\\',").match(teksto);
   if(interkonsento.hasMatch())
   {uuid=interkonsento.captured().mid(2,22).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("\\'[a-z]{2}\\',").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {lingvo=interkonsento.captured().mid(1,interkonsento.capturedLength()-3).toUtf8();
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     QRegExp priskriboInterkonsento("[xX]\\'([0-9A-Fa-f]{2})+\\'");
     int priskriboIndekso=priskriboInterkonsento.indexIn(teksto);
     if(priskriboIndekso>-1)
     {int longo=priskriboInterkonsento.matchedLength();
      priskribo=qUncompress(QByteArray::fromHex(teksto.mid(priskriboIndekso+2,longo-3).toUtf8()));
      indekso=priskriboIndekso+longo;
      interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
       indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
       interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
       if(interkonsento.hasMatch())
       {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
        vido.agordiCxefsxlosilo(uuid+" ("+lingvo+")");
        vido.agordiKodo(priskribo);
        vido.agordiSubskribo(subskribo.replace("''","'"));
        QDateTime tempo;
        tempo.setTime_t(stato);
        vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
        QByteArray html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
        html.append("<title>");
        html.append(uuid+" ("+lingvo+")");
        html.append("</title>\n</head>\n<body>\n<article>\n");
        QRegularExpressionMatchIterator kongruo=
          QRegularExpression("\343\200\226\360\237\223\226[A-Za-z0-9]{3}\343\200\227").globalMatch(priskribo);
        while(kongruo.hasNext())
        {interkonsento=kongruo.next();
         if(interkonsento.hasMatch())
          priskribo.replace(interkonsento.captured().toUtf8(),"<sup>[<i>"+interkonsento.captured().mid(3,3).toUtf8()+
            "</i>]</sup>");
        }
        html.append(priskribo.replace("\342\233\223\342\231\202\342\233\201/",
          patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
        html.append("</article>\n</body>\n</html>");
        vido.agordiVido(html);
        QByteArray malnovaTeksto,malnovaSubskribo;
        qlonglong malnovaStato;
        if(informpeto.exec("SELECT teksto,subskribo,stato FROM priskriboj WHERE uuid='"+uuid+"' AND lingvo='"+lingvo+"';"))
        {if(informpeto.first())
         {malnovaTeksto=qUncompress(informpeto.value("teksto").toByteArray());
          malnovaSubskribo=informpeto.value("subskribo").toByteArray();
          malnovaStato=informpeto.value("stato").toLongLong();
          vido.agordiMalnovaSubskribo(malnovaSubskribo);
          tempo.setTime_t(malnovaStato);
          vido.agordiMalnovaStato(tempo.toString(Qt::SystemLocaleLongDate));
          html=patraObjekto->administranto.akiruValoro(AGORDO_STILO);
          html.append("<title>");
          html.append(uuid+" ("+lingvo+")");
          html.append("</title>\n</head>\n<body>\n<article>\n");
          QRegularExpressionMatchIterator kongruo=
            QRegularExpression("\343\200\226\360\237\223\226[A-Za-z0-9]{3}\343\200\227").globalMatch(malnovaTeksto);
          while(kongruo.hasNext())
          {interkonsento=kongruo.next();
           if(interkonsento.hasMatch())
            malnovaTeksto.replace(interkonsento.captured().toUtf8(),"<sup>[<i>"+interkonsento.captured().mid(3,3).toUtf8()+
              "</i>]</sup>");
          }
          html.append(malnovaTeksto.replace("\342\233\223\342\231\202\342\233\201/",
            patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
          html.append("</article>\n</body>\n</html>");
          vido.agordiMalnovaDatumoj(html);
          if(priskribo==malnovaTeksto&&subskribo.replace("''","'")==malnovaSubskribo&&stato==malnovaStato)
           vido.agordiRekomendo(tr("La priskribo jam existas."));
          else
          {if(stato==malnovaStato&&priskribo!=malnovaTeksto)
            vido.agordiRekomendo(tr("Estas sama malnova priskribo malsama enhavo."));
           else
           {if(stato==malnovaStato)
             vido.agordiRekomendo(tr("Estas sama malnova priskribo kun malsamaj subskriptoj."));
            else
            {if(stato<malnovaStato)
              vido.agordiRekomendo(tr("Estas jam disponebla \304\235isdatigi via priskribo."));
             else
             {if(stato>malnovaStato&&priskribo==malnovaTeksto)
               vido.agordiRekomendo(tr("Eksistas malnova priskribo de la sama enhavo."));
              else
               vido.agordiRekomendo(tr("La nuna priskribo estas pli malnova."));
         }}}}}
         else
         {vido.agordiMalnovaSubskribo("");
          vido.agordiMalnovaStato("");
          vido.agordiRekomendo(tr("Tia priskribo ne estas disponebla ankora\305\255."));
        }}
        else
         if(informpeto.lastError().isValid())
          QMessageBox::critical(this,tr("Eraro [099]!"),informpeto.lastError().text());
        vido.exec();
  }}}}}}
  if(ui->sintakseAnalizu->text()=="semantikajrilatoj")
  {QByteArray subjekto,objekto,aludo;
   int rilato;
   interkonsento=QRegularExpression("\\(\\'[a-zA-Z0-9_-]{22}\\',").match(teksto);
   if(interkonsento.hasMatch())
   {subjekto=interkonsento.captured().mid(2,22).toUtf8();
    indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("[0-4],").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {rilato=interkonsento.captured().left(1).toInt();
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("\\(\\'[a-zA-Z0-9_-]{22}\\',").match(teksto);
     if(interkonsento.hasMatch())
     {objekto=interkonsento.captured().mid(2,22).toUtf8();
      indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
      interkonsento=QRegularExpression("(NULL|\\'[a-zA-Z0-9]{3}\\'),").match(teksto,indekso);
      if(interkonsento.hasMatch())
      {if(interkonsento.captured()=="NULL,")
        aludo="---";
       else
        aludo=interkonsento.captured().mid(1,3).toUtf8();
       indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
       interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
       if(interkonsento.hasMatch())
       {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
        indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
        interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
        if(interkonsento.hasMatch())
        {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
         vido.agordiSubskribo(subskribo.replace("''","'"));
         QDateTime tempo;
         tempo.setTime_t(stato);
         vido.agordiStato(tempo.toString(Qt::SystemLocaleLongDate));
         QStringList specioj;
         specioj<<QObject::tr("hiponima:")<<QObject::tr("meronima:")<<QObject::tr("disponebla:")
           <<QObject::tr("instrumenta:")<<QObject::tr("supreniranta:");
         vido.exec();
  }}}}}}}
  datumbazo.close();
 }
 else
  if(datumbazo.lastError().isValid())
   QMessageBox::critical(this,tr("Eraro [027]!"),datumbazo.lastError().text());
}
