#ifndef TEZAUXRO_H
#define TEZAUXRO_H

#include <QByteArray>
#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class tezauxro;
}

class tezauxro:public QDialog
{Q_OBJECT
 public:
  explicit tezauxro(QWidget *gepatro);
  ~tezauxro();
 public slots:
  void priReiru();
  void priSelektado();
 private:
  Ui::tezauxro *ui;
  cxefaFenestro *patraObjekto;
  QByteArray ajxo;
};

#endif // TEZAUXRO_H
