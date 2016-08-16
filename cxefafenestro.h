#ifndef CXEFAFENESTRO_H
#define CXEFAFENESTRO_H

#include <QMainWindow>
#include <QWidget>

namespace Ui
{class cxefaFenestro;
}

class cxefaFenestro:public QMainWindow
{Q_OBJECT
 public:
  explicit cxefaFenestro(QWidget *parent=0);
  ~cxefaFenestro();
 private:
  Ui::cxefaFenestro *ui;
};

#endif // CXEFAFENESTRO_H
