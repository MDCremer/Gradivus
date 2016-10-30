#ifndef KODOSELEKTADO_H
#define KODOSELEKTADO_H

#include <QDialog>
#include <QListWidgetItem>
#include <QString>
#include <QWidget>
#include "cxefafenestro.h"

namespace Ui
{class kodoSelektado;
}

class kodoSelektado:public QDialog
{Q_OBJECT
 public:
  explicit kodoSelektado(QWidget *gepatro,cxefaFenestro *avo);
  ~kodoSelektado();
  QString akiruKodo() {return kodo;}
 public slots:
  void priApliku();
  void priDevasEnhavi(bool kontrolita);
  void priDuobleAlklako(QListWidgetItem *aktualo);
  void priElektajxoSxangxo();
  void priKompletigitaEnigu();
  void priRezignu();
 private:
  void sxargi();
  cxefaFenestro *avaObjekto;
  Ui::kodoSelektado *ui;
  QString kodo;
};

#endif // KODOSELEKTADO_H
