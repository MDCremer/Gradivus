#include "fontoj.h"
#include "ui_fontoj.h"
#include "pagxoreferenco.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void fontoj::priEnigo()
{pagxoReferenco referenco(this,patraObjekto);
 if(!literaturo.isEmpty())
  referenco.agordiLiteraturo(literaturo);
 if(!pagxo.isEmpty())
  referenco.agordiPagxo(pagxo);
 if(referenco.exec()==QDialog::Accepted)
 {literaturo=referenco.akiruLiteraturo();
  pagxo=referenco.akiruPagxo();
  ui->montru->setHtml(referenco.akiruHtml());
 }
 else
 {literaturo.clear();
  pagxo.clear();
  ui->montru->setHtml(patraObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n</body>\n</html>");
}}
