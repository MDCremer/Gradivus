#ifndef FONTOJ_H
#define FONTOJ_H

#include <QByteArray>
#include <QDialog>
#include <QString>
#include <QWidget>
#include "cxefafenestro.h"
#include "rikordoregistrilo.h"

namespace Ui
{class fontoj;
}

class fontoj:public QDialog
{Q_OBJECT
 public:
  explicit fontoj(QWidget *gepatro);
  ~fontoj();
 public slots:
  void priAkceptu();
  void priElektajxoSxangxo();
  void priEnigo();
  void priForigu();
  void priKontribui(bool kontrolita);
  void priMalfaru();
  void priReiru();
  void priSelektado();
  void priVakigu();
 private:
  void sxargi();
  Ui::fontoj *ui;
  cxefaFenestro *patraObjekto;
  rikordoRegistrilo *registrilo;
  QByteArray ajxo;
  QString literaturo;
  QString pagxo;
  QString aktualaFonto;
};

#endif // FONTOJ_H
