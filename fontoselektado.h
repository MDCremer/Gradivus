#ifndef FONTOSELEKTADO_H
#define FONTOSELEKTADO_H

#include <QByteArray>
#include <QDialog>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class fontoSelektado;
}

class fontoSelektado:public QDialog
{Q_OBJECT
 public:
  explicit fontoSelektado(QWidget *gepatro,cxefaFenestro *avo,QByteArray kodo);
  ~fontoSelektado();
  QByteArray akiruAludo() {return aludo;}
 public slots:
  void priApliku();
  void priElektajxoSxangxo();
  void priRezignu();
 private:
  Ui::fontoSelektado *ui;
  cxefaFenestro *avaObjekto;
  QByteArray ajxo;
  QByteArray aludo;
};

#endif // FONTOSELEKTADO_H
