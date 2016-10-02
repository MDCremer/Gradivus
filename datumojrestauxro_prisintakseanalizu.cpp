#include <QByteArray>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>
#include "datumojrestauxro.h"
#include "ui_datumojrestauxro.h"

void datumojRestauxro::priSintakseAnalizu()
{QRegularExpressionMatch interkonsento;
 QString teksto=ui->ordono->toPlainText();
 QByteArray subskribo;
 qlonglong stato;
 int indekso;
 if(ui->sintakseAnalizu->text()=="literaturoj")
 {QByteArray aludo,html;
  interkonsento=QRegularExpression("\\(\\'([^\\']+|\\'{2})+\\'").match(teksto);
  if(interkonsento.hasMatch())
  {aludo=interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8();
   indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
   interkonsento=QRegularExpression("x\\'([0-9A-Fa-f]{2})+\\'").match(teksto,indekso);
   if(interkonsento.hasMatch())
   {html=qUncompress(QByteArray::fromHex(interkonsento.captured().mid(2,interkonsento.captured().length()-3).toUtf8()));
    indekso+=interkonsento.capturedStart()+interkonsento.capturedLength();
    interkonsento=QRegularExpression("\\':([^\\']+|\\'{2})+:\\'").match(teksto,indekso);
    if(interkonsento.hasMatch())
    {subskribo=interkonsento.captured().mid(1,interkonsento.captured().length()-2).toUtf8();
     indekso=interkonsento.capturedStart()+interkonsento.capturedLength();
     interkonsento=QRegularExpression("[0-9]+\\);").match(teksto,indekso);
     if(interkonsento.hasMatch())
     {stato=interkonsento.captured().left(interkonsento.captured().length()-2).toLongLong();
 }}}}}
 if(ui->sintakseAnalizu->text()=="identigiloj")
 {
}}
