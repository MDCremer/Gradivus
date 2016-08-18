#include <QApplication>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QLibraryInfo>
#include <QLocale>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QTextStream>
#include <QTranslator>
#include "cxefafenestro.h"

int main(int argc,char *argv[])
{QApplication gradivo(argc,argv);
/* datumbazo */
 if(!QSqlDatabase::drivers().contains("QSQLITE"))
  return -999;
 else
 {QSqlDatabase datumbazo=QSqlDatabase::addDatabase("QSQLITE");
  QFileInfo dosiero(QDir::homePath()+"/Gradivus/Gradivus.sqlite3");
  bool pravalorizi=!dosiero.exists();
  datumbazo.setDatabaseName(QDir::homePath()+"/Gradivus/Gradivus.sqlite3");
  if(!datumbazo.open())
  {if(datumbazo.lastError().isValid())
    QMessageBox::critical(0,"Fatala eraro [001]!",datumbazo.lastError().text());
   return -888;
  }
  else
  {QString lingvoMallongigo=QLocale::system().name();
   QSqlQuery informpeto;
   if(pravalorizi)
   {QFile listo(QDir::homePath()+"/Gradivus/skriptoj/enkondukalisto.txt");
    if(listo.open(QIODevice::ReadOnly|QIODevice::Text))
    {while(!listo.atEnd())
     {QByteArray linio=listo.readLine();
      if(linio.endsWith("\n"))
       linio.truncate(linio.length()-QByteArray("\n").length());
      QString skripto(QDir::homePath()+"/Gradivus/skriptoj/SQL/");
      skripto.append(linio);
      QFile komando(skripto);
      if(komando.open(QIODevice::ReadOnly|QIODevice::Text))
      {QByteArray instrukcio;
       while(!komando.atEnd())
       {QByteArray teksto=komando.readLine();
        if(teksto.endsWith("\n"))
         teksto.truncate(teksto.length()-QByteArray("\n").length());
        if(!teksto.isEmpty()&&!teksto.startsWith("--"))
        {instrukcio.append(teksto);
         if(teksto.endsWith(";"))
         {if(informpeto.exec(instrukcio))
           instrukcio.clear();
          else
           if(informpeto.lastError().isValid())
            QMessageBox::warning(0,"Eraro [002]!",informpeto.lastError().text());
         }
         else
          instrukcio.append(" ");
       }}
       komando.close();
      }
      else
       QMessageBox::warning(0,"Eraro [003]!","La dosiero "+linio+" ne povis esti malfermita!");
     }
     listo.close();
    }
    else
     QMessageBox::warning(0,"Eraro [004]!","La listo de dosieroj por esti procesita ne povis esti malfermita!");
    QFileInfo provizaro("$HOME/Gradivus/skriptoj/SQL/provizaro.sql");
    if(provizaro.exists())
    {QFile stoko(QDir::homePath()+"/Gradivus/skriptoj/SQL/provizaro.sql");
     if(stoko.open(QIODevice::ReadOnly|QIODevice::Text))
     {QTextStream enigo(&stoko);
      enigo.setCodec("UTF-8");
      while(!enigo.atEnd())
      {QString linio=enigo.readLine();
       if(linio.endsWith("\n"))
        linio.truncate(linio.length()-QString("\n").length());
       if(!linio.isEmpty()&&!linio.startsWith("--"))
        if(linio.endsWith(";"))
         if(!informpeto.exec(linio))
          if(informpeto.lastError().isValid())
           QMessageBox::warning(0,"Eraro [005]!",informpeto.lastError().text());
      }
      stoko.close();
   }}}
   if(informpeto.exec("SELECT nomo,valoro FROM agordoj;"))
   {while(informpeto.next())
    {QByteArray nomo=informpeto.value("nomo").toByteArray();
     if(nomo=="lingvo")
     {QByteArray lingvo=informpeto.value("valoro").toByteArray();
      if(!lingvo.isEmpty())
      {QLocale kulturo(lingvo);
       QLocale::setDefault(kulturo);
       lingvoMallongigo=kulturo.name();
   }}}}
   else
    if(informpeto.lastError().isValid())
     QMessageBox::warning(0,"Eraro [006]!",informpeto.lastError().text());
   datumbazo.close();
/* tradukistoj */
   QTranslator sistemaTradukilo;
   if(sistemaTradukilo.load("qt_"+lingvoMallongigo.left(2),QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    gradivo.installTranslator(&sistemaTradukilo);
   QTranslator programaTradukilo;
   if(programaTradukilo.load(":/tradukajoj/gradivus_"+lingvoMallongigo.left(2)))
    gradivo.installTranslator(&programaTradukilo);
/* fenestro */
   cxefaFenestro fenestro;
   fenestro.show();
/* kontrolo */
   return gradivo.exec();
}}}
