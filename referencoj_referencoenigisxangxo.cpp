#include <QDir>
#include <QFile>
#include <QString>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::referencoEnigiSxangxo(int indekso)
{if(indekso==1)
 {QString html("<!doctype html>\n<html>\n<head>\n<meta charset='utf-8'>\n<title>");
  html.append(ui->aludo->text());
  html.append("</title>\n");
  QFile stilo(QDir::homePath()+"/Gradivus/dokumentoj/rimedoj/stilo.css");
  if(stilo.open(QIODevice::ReadOnly|QIODevice::Text))
  {html.append("<style>\n");
   html.append(stilo.readAll());
   html.append("\n</style>\n");
   stilo.close();
  }
  html.append("</head>\n<body>\n<p>");
  html.append(ui->teksto->toPlainText());
  html.append("</p>\n</body>\n</html>");
  ui->spektaklo->setHtml(html);
}}
