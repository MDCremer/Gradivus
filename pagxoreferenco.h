#ifndef PAGXOREFERENCO_H
#define PAGXOREFERENCO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"
#include "htmlmarkilo.h"

namespace Ui
{class pagxoReferenco;
}

class pagxoReferenco:public QDialog
{Q_OBJECT
 public:
  explicit pagxoReferenco(QWidget *gepatro,cxefaFenestro *avo);
  ~pagxoReferenco();
 public slots:
  void priRezignu();
 private:
  Ui::pagxoReferenco *ui;
  htmlMarkilo *markilo;
  cxefaFenestro *avaObjekto;
};

#endif // PAGXOREFERENCO_H
