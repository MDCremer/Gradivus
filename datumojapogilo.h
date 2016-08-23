#ifndef DATUMOJAPOGILO_H
#define DATUMOJAPOGILO_H

#include <QDialog>
#include <QWidget>

namespace Ui
{class datumojApogilo;
}

class datumojApogilo:public QDialog
{Q_OBJECT
 public:
  explicit datumojApogilo(QWidget *gepatro=0);
  ~datumojApogilo();
 public slots:
  void priAbortu();
  void priExportu();
 private:
  Ui::datumojApogilo *ui;
};

#endif // DATUMOJAPOGILO_H
