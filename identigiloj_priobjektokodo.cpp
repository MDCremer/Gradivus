#include <QByteArray>
#include <QUuid>
#include "identigiloj.h"
#include "ui_identigiloj.h"

void identigiloj::priObjektoKodo()
{ui->objektoKodo->setText(QUuid::createUuid().toRfc4122().toBase64(QByteArray::Base64UrlEncoding|
   QByteArray::OmitTrailingEquals));
}
