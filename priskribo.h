#ifndef PRISKRIBO_H
#define PRISKRIBO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class priskribo;
}

class priskribo:public QDialog
{Q_OBJECT
 public:
  explicit priskribo(QWidget *gepatro);
  ~priskribo();
 private:
  Ui::priskribo *ui;
  cxefaFenestro *patraObjekto;
};

#endif // PRISKRIBO_H
