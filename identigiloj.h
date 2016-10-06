#ifndef IDENTIGILOJ_H
#define IDENTIGILOJ_H

#include <QDialog>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class identigiloj;
}

class identigiloj:public QDialog
{Q_OBJECT
 public:
  explicit identigiloj(QWidget *gepatro=0);
  ~identigiloj();
 public slots:
  void priReiru();
 private:
  cxefaFenestro *patraObjekto;
  Ui::identigiloj *ui;
  rikordoRegistrilo *registrilo;
};

#endif // IDENTIGILOJ_H
