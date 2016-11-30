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
#define PRISKRIBO_GRASA 14
#define PRISKRIBO_FORTA 15
#define PRISKRIBO_KURSIVA 16
#define PRISKRIBO_EMFAZA 17
#define PRISKRIBO_DIFINO 18
#define PRISKRIBO_SPECIMENO 19
#define PRISKRIBO_KODO 20
#define PRISKRIBO_APRIORA 21
#define PRISKRIBO_SUBSTRETIKA 22
#define PRISKRIBO_SUPERSKRIBITA 23
#define PRISKRIBO_SUBA 24
#define PRISKRIBO_MINORA 25
#define PRISKRIBO_NEORDIGITALISTO 26
#define PRISKRIBO_ORDIGITALISTO 27
#define PRISKRIBO_LISTOERO 28
#define PRISKRIBO_DIFINOLISTO 29
#define PRISKRIBO_DIFINOLISTOERO 30
#define PRISKRIBO_DIFINOLISTOTEKSTO 31
#define PRISKRIBO_TABELO 32
#define PRISKRIBO_TABELOKAPO 33
#define PRISKRIBO_TABELOVICO 34
#define PRISKRIBO_TABELOCXELO 35

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
  void priApriora();
  void priBildo();
  void priBlokoCitajxo();
  void priCentrigu();
  void priCitajxo();
  void priDekstre();
  void priDifino();
  void priDifinoListo();
  void priDifinoListoEro();
  void priDifinoListoTeksto();
  void priEmfaza();
  void priFiguro();
  void priFiguroTitolo();
  void priFonto();
  void priForigu();
  void priForta();
  void priGlita();
  void priGrasa();
  void priGxisrandigu();
  void priKlaso();
  void priKodo();
  void priKontribui(bool kontrolita);
  void priKursiva();
  void priLingvo(QString lingvo);
  void priLinifaldo();
  void priListoEro();
  void priMaldekstre();
  void priMalfaru();
  void priMargxeno();
  void priMinora();
  void priNeordigitaListo();
  void priOrdigitaListo();
  void priParagrafo();
  void priReferenceita();
  void priReiru();
  void priSekcio();
  void priSelektado();
  void priSpecimeno();
  void priStilo();
  void priStreko();
  void priSuba();
  void priSubstretika();
  void priSuperskribita();
  void priTabelo();
  void priTabeloCxelo();
  void priTabeloKapo();
  void priTabeloVico();
  void priTekstoGxisrandigo();
  void priTitolo();
  void priTitoloUnua();
  void priTitoloDua();
  void priTitoloTria();
  void priTitoloKvara();
  void priTitoloKvina();
  void priTitoloSesa();
  void priVakigu();
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
