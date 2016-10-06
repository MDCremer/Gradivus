#ifndef IDENTIGILOJ_H
#define IDENTIGILOJ_H

#include <QDialog>

namespace Ui
{class identigiloj;
}

class identigiloj:public QDialog
{Q_OBJECT
 public:
  explicit identigiloj(QWidget *gepatro=0);
  ~identigiloj();
 private:
  Ui::identigiloj *ui;
};

#endif // IDENTIGILOJ_H
