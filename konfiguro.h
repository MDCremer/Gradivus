#ifndef KONFIGURO_H
#define KONFIGURO_H

#include <QDialog>

namespace Ui
{class konfiguro;
}

class konfiguro : public QDialog
{Q_OBJECT
 public:
  explicit konfiguro(QWidget *gepatro=0);
  ~konfiguro();
 private:
  Ui::konfiguro *ui;
};

#endif // KONFIGURO_H
