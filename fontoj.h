#ifndef FONTOJ_H
#define FONTOJ_H

#include <QByteArray>
#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class fontoj;
}

class fontoj:public QDialog
{Q_OBJECT
 public:
  explicit fontoj(QWidget *gepatro);
  ~fontoj();
 public slots:
  void priSelektado();
 private:
  Ui::fontoj *ui;
  cxefaFenestro *patraObjekto;
  rikordoRegistrilo *registrilo;
  QByteArray ajxo;
};

#endif // FONTOJ_H
