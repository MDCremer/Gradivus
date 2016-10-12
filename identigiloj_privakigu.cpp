#include "identigiloj.h"
#include "ui_identigiloj.h"
#include "cxefafenestro.h"
#include "agordoj.h"

void identigiloj::priVakigu()
{ui->etno->setCurrentIndex(0);
 ui->nomo->clear();
 ui->lingvo->setCurrentIndex(0);
 ui->referenco->setHtml(patraObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n</body>\n</html>");
 ui->objektoKodo->clear();
 ui->subskribo->clear();
 ui->stato->clear();
}
