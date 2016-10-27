#include <QDesktopServices>
#include <QFileDialog>
#include <QtWebEngineWidgets>
#include <QUrl>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"

void cxefaFenestro::priPdfEldono()
{QString eldono=QFileDialog::getSaveFileName(this,tr("Dosiero selektado por eldono"),QDir::homePath()+
  "/Gradivus/dokumentoj/",tr("PDF-dosiero")+" (*.pdf)");
 if(!eldono.isNull())
 {if(!eldono.endsWith(".pdf"))
   eldono.append(".pdf");
  ui->informaMontro->page()->printToPdf(eldono);
  QDesktopServices::openUrl(QUrl("file://"+eldono));
}}
