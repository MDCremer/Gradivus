#ifndef KONFIGURO_H
#define KONFIGURO_H

#include <QDialog>
#include <QListWidgetItem>
#include <QWidget>
#include "rikordoregistrilo.h"

namespace Ui
{class konfiguro;
}

class konfiguro : public QDialog
{Q_OBJECT
 public:
  explicit konfiguro(QWidget *gepatro=0);
  ~konfiguro();
 public slots:
  void priAbortu();
  void priSupro();
  void priSupren();
  void priMalsupren();
  void priMalsupro();
  void lingvoEtikedoSxangxo(QListWidgetItem *aktivaEro);
 private:
  QWidget *patraObjekto;
  Ui::konfiguro *ui;
  rikordoRegistrilo *registrilo;
  int lingvaKvanto;
};

#endif // KONFIGURO_H
