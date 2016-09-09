#ifndef KONFIGURO_H
#define KONFIGURO_H

#include <QDialog>
#include <QListWidgetItem>

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
  Ui::konfiguro *ui;
};

#endif // KONFIGURO_H
