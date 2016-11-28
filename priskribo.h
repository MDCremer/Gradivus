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
#define PRISKRIBO_PARAGRAFO 8
#define PRISKRIBO_SEKCIO 9
#define PRISKRIBO_BLOKOCITAJXO 10
#define PRISKRIBO_FIGURO 11
#define PRISKRIBO_FIGUROTITOLO 12
#define PRISKRIBO_MARGXENO 13

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
  void priBlokoCitajxo();
  void priCentrigu();
  void priCitajxo();
  void priDekstre();
  void priFiguro();
  void priFiguroTitolo();
  void priFonto();
  void priForigu();
  void priGxisrandigu();
  void priGlita();
  void priKlaso();
  void priKontribui(bool kontrolita);
  void priLingvo(QString lingvo);
  void priLinifaldo();
  void priMaldekstre();
  void priMalfaru();
  void priMargxeno();
  void priParagrafo();
  void priReferenceita();
  void priReiru();
  void priSekcio();
  void priSelektado();
  void priStilo();
  void priStreko();
  void priTekstoGxisrandigo();
  void priTitolo();
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
