#ifndef DATUMOJRESTAUXRO_H
#define DATUMOJRESTAUXRO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"
#include "sqlmarkilo.h"

namespace Ui
{class datumojrestauxro;
}

class datumojRestauxro:public QDialog
{Q_OBJECT
 public:
  explicit datumojRestauxro(QWidget *gepatro=0);
  ~datumojRestauxro();
 public slots:
  void priAbortu();
  void priSintakseAnalizu();
 private:
  cxefaFenestro *patraObjekto;
  sqlMarkilo *markilo;
  Ui::datumojrestauxro *ui;
};

#endif // DATUMOJRESTAUXRO_H
