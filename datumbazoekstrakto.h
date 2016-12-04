#ifndef DATUMBAZOEKSTRAKTO_H
#define DATUMBAZOEKSTRAKTO_H

#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class datumbazoEkstrakto;
}

class datumbazoEkstrakto:public QDialog
{Q_OBJECT
 public:
  explicit datumbazoEkstrakto(QWidget *gepatro);
  ~datumbazoEkstrakto();
 public slots:
  void priEkstrakto();
  void priRezignu();
 private:
  Ui::datumbazoEkstrakto *ui;
  cxefaFenestro *patraObjekto;
};

#endif // DATUMBAZOEKSTRAKTO_H
