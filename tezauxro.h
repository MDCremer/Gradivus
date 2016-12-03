#ifndef TEZAUXRO_H
#define TEZAUXRO_H

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
 private:
  Ui::tezauxro *ui;
  cxefaFenestro *patraObjekto;
};

#endif // TEZAUXRO_H
