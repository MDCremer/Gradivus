#ifndef KONFIGURO_H
#define KONFIGURO_H

#include <QDialog>
#include <QListWidgetItem>
#include <QWidget>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class konfiguro;
}

class konfiguro:public QDialog
{Q_OBJECT
 public:
  explicit konfiguro(QWidget *gepatro=0);
  ~konfiguro();
 public slots:
  void priKonfirmu();
  void priMalfaru();
  void priMalsupren();
  void priMalsupro();
  void priReiru();
  void priSupren();
  void priSupro();
  void lingvoEtikedoSxangxo(QListWidgetItem *aktivaEro);
 private:
  cxefaFenestro *patraObjekto;
  Ui::konfiguro *ui;
  rikordoRegistrilo *registrilo;
  int lingvaKvanto;
};

#endif // KONFIGURO_H
