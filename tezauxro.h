#ifndef TEZAUXRO_H
#define TEZAUXRO_H

#include <QByteArray>
#include <QDialog>
#include <QTreeWidgetItem>
#include <QWidget>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class tezauxro;
}

class tezauxro:public QDialog
{Q_OBJECT
 public:
  explicit tezauxro(QWidget *gepatro);
  ~tezauxro();
 public slots:
  void priAkceptu();
  void priElektajxoSxangxo(QTreeWidgetItem *aktualo);
  void priFonto();
  void priForigu();
  void priKontribui(bool kontrolita);
  void priMalfaru();
  void priObjekto();
  void priReiru();
  void priSelektado();
 private:
  void sxargi();
  Ui::tezauxro *ui;
  cxefaFenestro *patraObjekto;
  rikordoRegistrilo *registrilo;
  QByteArray ajxo,objekto;
};

#endif // TEZAUXRO_H
