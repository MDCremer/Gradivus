#include <QApplication>
#include <QLibraryInfo>
#include <QLocale>
#include <QString>
#include <QTranslator>
#include "cxefafenestro.h"

int main(int argc,char *argv[])
{QApplication gradivo(argc,argv);
 QString lingvoMallongigo=QLocale::system().name().left(2);
 QTranslator sistemaTradukilo;
 if(sistemaTradukilo.load("qt_"+lingvoMallongigo,QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
  gradivo.installTranslator(&sistemaTradukilo);
 QTranslator programaTradukilo;
 if(programaTradukilo.load(":/tradukajoj/gradivus_"+lingvoMallongigo))
  gradivo.installTranslator(&programaTradukilo);
 cxefaFenestro fenestro;
 fenestro.show();
 return gradivo.exec();
}
