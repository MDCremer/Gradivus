#ifndef DATUMOJAPOGILO_H
#define DATUMOJAPOGILO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class datumojApogilo;
}

class datumojApogilo:public QDialog
{Q_OBJECT
 public:
  explicit datumojApogilo(QWidget *gepatro=0);
  ~datumojApogilo();
 public slots:
  void priRezignu();
  void priEksportu();
  void priElektuCxiuj();
 private:
  cxefaFenestro *patraObjekto;
  Ui::datumojApogilo *ui;
};

#endif // DATUMOJAPOGILO_H
