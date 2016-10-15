#include <QString>
#include "referencoj.h"
#include "ui_referencoj.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void referencoj::referencoEnigiSxangxo(int indekso)
{if(indekso==1)
 {QString html(patraObjekto->administranto.akiruValoro(AGORDO_STILO));
  html.append("<title>");
  html.append(ui->aludo->text());
  html.append("</title>\n");
  html.append("</head>\n<body>\n<p>");
  html.append(ui->teksto->toPlainText().replace("\342\233\223\342\231\202\342\233\201/",
    patraObjekto->administranto.akiruValoro(AGORDO_VORTARO)));
  html.append("</p>\n</body>\n</html>");
  ui->spektaklo->setHtml(html);
}}
