#ifndef CXEFAFENESTRO_H
#define CXEFAFENESTRO_H

#include <QMainWindow>
#include <QString>
#include <QWidget>

namespace Ui
{class cxefaFenestro;
}

class cxefaFenestro:public QMainWindow
{Q_OBJECT
 public:
  explicit cxefaFenestro(QWidget *parent=0);
  ~cxefaFenestro();
  void montruInformo(QString dosiero);
 private:
  Ui::cxefaFenestro *ui;
};

#endif // CXEFAFENESTRO_H
