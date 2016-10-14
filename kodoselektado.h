#ifndef KODOSELEKTADO_H
#define KODOSELEKTADO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class kodoSelektado;
}

class kodoSelektado : public QDialog
{Q_OBJECT
 public:
  explicit kodoSelektado(QWidget *gepatro,cxefaFenestro *avo);
  ~kodoSelektado();
 private:
  void sxargi();
  cxefaFenestro *avaObjekto;
  Ui::kodoSelektado *ui;
};

#endif // KODOSELEKTADO_H
