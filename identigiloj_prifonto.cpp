#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "pagxoreferenco.h"

void identigiloj::priFonto()
{pagxoReferenco referenco(this,patraObjekto);
 if(!literaturo.isEmpty())
  referenco.agordiLiteraturo(literaturo);
 if(!pagxo.isEmpty())
  referenco.agordiPagxo(pagxo);
 if(referenco.exec())
 {literaturo=referenco.akiruLiteraturo();
  pagxo=referenco.akiruPagxo();
  ui->referenco->setHtml(referenco.akiruHtml());
}}
