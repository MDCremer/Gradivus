#ifndef CXEFAFENESTRO_H
#define CXEFAFENESTRO_H

#include <QMainWindow>
#include <QString>
#include <QWidget>
#include "agordoj.h"

namespace Ui
{class cxefaFenestro;
}

class cxefaFenestro:public QMainWindow
{Q_OBJECT
 public:
  explicit cxefaFenestro(QWidget *gepatro=0);
  ~cxefaFenestro();
  void montruInformo(QString dosiero);
  void spektakloMesagxon(QString mesagxo);
  agordoj administranto;
 public slots:
  void priDatumojApogilo();
  void priKonfiguro();
  void priMuta(int statuso);
 private:
  Ui::cxefaFenestro *ui;
};

#endif // CXEFAFENESTRO_H
