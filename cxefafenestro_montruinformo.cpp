#include <QDir>
#include <QFileInfo>
#include <QLocale>
#include <QString>
#include <QUrl>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"

void cxefaFenestro::montruInformo(QString dosiero)
{QString pado(QDir::homePath()+"/Gradivus/dokumentoj/");
 QLocale kulturo;
 QString lingvo=kulturo.name().split('_').first()+"/";
 QFileInfo varianto(pado+lingvo+dosiero);
 if(varianto.exists())
  pado.append(lingvo);
 ui->informaMontro->setUrl(QUrl("file://"+pado+dosiero));
}
