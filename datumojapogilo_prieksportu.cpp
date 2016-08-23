#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include "datumojapogilo.h"

void datumojApogilo::priExportu()
{QString eligoDosiernomo=QFileDialog::getSaveFileName(this,tr("Dosiero selektado por sekurkopioj"),QDir::homePath()+
  "/Gradivus/skriptoj/SQL/provizaro.sql",tr("SQL-dosiero")+" (*.sql)");
 if(!eligoDosiernomo.isNull())
 {QFile eligoDosiero(eligoDosiernomo);
  eligoDosiero.open(QIODevice::WriteOnly);
  if(eligoDosiero.isOpen())
  {eligoDosiero.close();
  }
  accept();
}}
