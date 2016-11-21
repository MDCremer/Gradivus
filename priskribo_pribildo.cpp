#include <QBuffer>
#include <QByteArray>
#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QImage>
#include <QImageReader>
#include <QIODevice>
#include <QPainter>
#include <QStringList>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"

void priskribo::priBildo()
{QStringList mimeTipoFiltriloj;
 foreach(const QByteArray &mimeTipoNomo,QImageReader::supportedMimeTypes())
  mimeTipoFiltriloj.append(mimeTipoNomo);
 mimeTipoFiltriloj.sort();
 QFileDialog selektado(this,tr("Inkluzivas bildo"),QDir::homePath()+"/Gradivus/bildoj");
 selektado.setAcceptMode(QFileDialog::AcceptOpen);
 selektado.setMimeTypeFilters(mimeTipoFiltriloj);
 selektado.selectMimeTypeFilter("image/jpeg");
 if(selektado.exec()==QDialog::Accepted)
 {QImageReader legilo(selektado.selectedFiles().first());
  legilo.setAutoTransform(true);
  QImage bildo=legilo.read();
  if(bildo.isNull())
   patraObjekto->spektakloMesagxon(tr("Dosiero ne povis esti malfermita!"));
  else
  {if(bildo.width()>360)
    bildo=bildo.scaledToWidth(360,Qt::SmoothTransformation);
   if(bildo.height()>360)
    bildo=bildo.scaledToHeight(360,Qt::SmoothTransformation);
   QImage kopio(bildo.size(),QImage::Format_Grayscale8);
   kopio.fill(Qt::white);
   QPainter pentristo(&kopio);
   pentristo.drawImage(0,0,bildo);
   QByteArray bildoDatumoj;
   QBuffer bufro(&bildoDatumoj);
   bufro.open(QIODevice::WriteOnly);
   kopio.save(&bufro,"JPG",60);
   bufro.close();
   QByteArray enigo("<img width='");
   enigo.append(QByteArray::number(kopio.width()));
   enigo.append("' height='");
   enigo.append(QByteArray::number(kopio.height()));
   enigo.append("' src='\342\234\202");
   enigo.append(QByteArray::number(bildoj.count()));
   enigo.append("\360\237\223\267'>");
   ui->teksto->insertPlainText(enigo);
   bildoj<<"data:image/jpg;base64,"+bildoDatumoj.toBase64();
}}}
