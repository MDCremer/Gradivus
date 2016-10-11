#ifndef PAGXOREFERENCO_H
#define PAGXOREFERENCO_H

#include <QDialog>
#include <QWidget>

namespace Ui
{class pagxoReferenco;
}

class pagxoReferenco:public QDialog
{Q_OBJECT
 public:
  explicit pagxoReferenco(QWidget *gepatro=0);
  ~pagxoReferenco();
 private:
  Ui::pagxoReferenco *ui;
};

#endif // PAGXOREFERENCO_H
