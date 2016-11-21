#ifndef PRISKRIBO_H
#define PRISKRIBO_H

#include <QByteArray>
#include <QDialog>
#include <QString>
#include <QToolButton>
#include <QVector>
#include <QWidget>
#include "cxefafenestro.h"
#include "htmlmarkilo.h"
#include "rikordoregistrilo.h"

#define PRISKRIBO_REFERENCEITA 0
#define PRISKRIBO_CITAJXO 1

namespace Ui
{class priskribo;
}

class priskribo:public QDialog
{Q_OBJECT
 public:
  explicit priskribo(QWidget *gepatro);
  ~priskribo();
 public slots:
  void pagxoSxangxo(int indekso);
  void priBildo();
  void priCitajxo();
  void priKontribui(bool kontrolita);
  void priReferenceita();
  void priReiru();
  void priSelektado();
 private:
  void enigi(int indekso,QString starto,QString fino,QToolButton *butono);
  Ui::priskribo *ui;
  cxefaFenestro *patraObjekto;
  htmlMarkilo *markilo;
  rikordoRegistrilo *registrilo;
  QVector<QByteArray> bildoj;
  QByteArray ajxo;
  bool enigojAktivigita[36];
};

#endif // PRISKRIBO_H
