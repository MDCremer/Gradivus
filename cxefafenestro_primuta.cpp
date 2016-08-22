#include <Qt>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"

void cxefaFenestro::priMuta(int statuso)
{if(statuso==Qt::Checked)
  ui->informaMontro->page()->setAudioMuted(true);
 else
  if(statuso==Qt::Unchecked)
   ui->informaMontro->page()->setAudioMuted(false);
}
