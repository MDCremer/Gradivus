#include <QString>
#include "priskribo.h"
#include "ui_priskribo.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void priskribo::pagxoSxangxo(int indekso)
{if(indekso==1)
 {QString html(patraObjekto->administranto.akiruValoro(AGORDO_STILO));
  html.append("<title>");
  html.append(ajxo);
  html.append("</title>\n</head>\n<body>\n<article>\n");
  QString teksto=ui->teksto->toPlainText().replace("\342\233\223\342\231\202\342\233\201/",
    patraObjekto->administranto.akiruValoro(AGORDO_VORTARO));
  for(int nombro=0;nombro<bildoj.count();++nombro)
   teksto.replace("\342\234\202"+QString::number(nombro)+"\360\237\223\267",bildoj[nombro]);
  html.append(teksto);
  html.append("</article>\n</body>\n</html>");
  ui->montru->setHtml(html);
}}
