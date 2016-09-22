#ifndef REFERENCOJ_H
#define REFERENCOJ_H

#include <QDialog>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class referencoj;
}

class referencoj:public QDialog
{Q_OBJECT
 public:
  explicit referencoj(QWidget *gepatro=0);
  ~referencoj();
 public slots:
  void priAbortu();
 private:
  void sxargiAludoj();
  cxefaFenestro *patraObjekto;
  Ui::referencoj *ui;
  rikordoRegistrilo *registrilo;
};

#endif // REFERENCOJ_H
