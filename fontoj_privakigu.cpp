#include "fontoj.h"
#include "ui_fontoj.h"

void fontoj::priVakigu()
{ui->listo->clearSelection();
 ui->aludo->clear();
 ui->montru->setHtml(patraObjekto->administranto.akiruValoro(AGORDO_STILO)+"</head>\n<body>\n</body>\n</html>");
 literaturo.clear();
 pagxo.clear();
 ui->subskribo->clear();
 ui->stato->clear();
}
