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
  explicit cxefaFenestro(QWidget *gepatro=0);
  ~cxefaFenestro();
  void montruInformo(QString dosiero);
 public slots:
  void priDatumojApogilo();
  void priMuta(int statuso);
 private:
  Ui::cxefaFenestro *ui;
};

#endif // CXEFAFENESTRO_H
