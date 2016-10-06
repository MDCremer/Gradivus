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
  bool konsento(QWidget *gepatro);
  void montruInformo(QString dosiero);
  void spektakloMesagxon(QString mesagxo);
  agordoj administranto;
 public slots:
  void priDatumojApogilo();
  void priKonfiguro();
  void priReferencoj();
  void priMuta(int statuso);
  void priStartoPagxo();
  void priDatumojRestauxro();
  void priIdentigiloj();
 private:
  Ui::cxefaFenestro *ui;
};

#endif // CXEFAFENESTRO_H
