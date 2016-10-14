#ifndef IDENTIGILOJ_H
#define IDENTIGILOJ_H

#include <QDialog>
#include <QString>
#include <QWidget>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class identigiloj;
}

class identigiloj:public QDialog
{Q_OBJECT
 public:
  explicit identigiloj(QWidget *gepatro);
  ~identigiloj();
 public slots:
  void priAkceptu();
  void priElektajxoSxangxo();
  void priFonto();
  void priHistoriaListo(QString teksto);
  void priKodoSxangxo(QString kodo);
  void priKontribui(bool kontrolita);
  void priLimigiTipoj(QString teksto);
  void priLingvoLimigo(QString teksto);
  void priNovaKodo();
  void priObjektoKodo();
  void priReiru();
  void priVakigu();
 private:
  void sxargi();
  cxefaFenestro *patraObjekto;
  Ui::identigiloj *ui;
  rikordoRegistrilo *registrilo;
  QString aktualaIdentigilo;
  QString literaturo;
  QString pagxo;
};

#endif // IDENTIGILOJ_H
