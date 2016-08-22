#ifndef DATUMOJAPOGILO_H
#define DATUMOJAPOGILO_H

#include <QDialog>
#include <QWidget>

namespace Ui
{class datumojApogilo;
}

class datumojApoligo:public QDialog
{Q_OBJECT
 public:
  explicit datumojApoligo(QWidget *gepatro=0);
  ~datumojApoligo();
 private:
  Ui::datumojApogilo *ui;
};

#endif // DATUMOJAPOGILO_H
