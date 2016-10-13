#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "pagxoreferenco.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void identigiloj::priFonto()
{pagxoReferenco referenco(this,patraObjekto);
 if(!literaturo.isEmpty())
  referenco.agordiLiteraturo(literaturo);
 if(!pagxo.isEmpty())
  referenco.agordiPagxo(pagxo);
 if(referenco.exec()==QDialog::Accepted)
 {literaturo=referenco.akiruLiteraturo();
  pagxo=referenco.akiruPagxo();
  ui->referenco->setHtml(referenco.akiruHtml());
 }
 else
 {literaturo.clear();
  pagxo.clear();
  ui->referenco->setHtml(patraObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n</body>\n</html>");
}}
