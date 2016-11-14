#ifndef PRISKRIBO_H
#define PRISKRIBO_H

#include <QByteArray>
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
 public slots:
  void priSelektado();
 private:
  Ui::priskribo *ui;
  cxefaFenestro *patraObjekto;
  QByteArray ajxo;
};

#endif // PRISKRIBO_H
