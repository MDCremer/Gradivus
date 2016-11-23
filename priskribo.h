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
#define PRISKRIBO_TITOLOUNUA 2
#define PRISKRIBO_TITOLODUA 3
#define PRISKRIBO_TITOLOTRIA 4
#define PRISKRIBO_TITOLOKVARA 5
#define PRISKRIBO_TITOLOKVINA 6
#define PRISKRIBO_TITOLOSESA 7

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
  void priAkceptu();
  void priBildo();
  void priCitajxo();
  void priFonto();
  void priForigu();
  void priKontribui(bool kontrolita);
  void priLingvo(QString lingvo);
  void priMalfaru();
  void priReferenceita();
  void priReiru();
  void priSelektado();
  void priTitoloUnua();
  void priTitoloDua();
  void priTitoloTria();
  void priTitoloKvara();
  void priTitoloKvina();
  void priTitoloSesa();
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
