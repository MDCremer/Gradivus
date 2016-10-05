#ifndef REFERENCOJ_H
#define REFERENCOJ_H

#include <QByteArray>
#include <QDialog>
#include <QListWidgetItem>
#include <QNetworkReply>
#include <QString>
#include <QToolButton>
#include "cxefafenestro.h"
#include "htmlmarkilo.h"
#include "rikordoregistrilo.h"

#define REFERENCO_CITAJXO 0
#define REFERENCO_FORTA 1
#define REFERENCO_GRASA 2
#define REFERENCO_KURSIVA 3
#define REFERENCO_SUBSTRETIKA 4
#define REFERENCO_SUPERSKRIBITA 5
#define REFERENCO_SUBA 6
#define REFERENCO_REFERENCEITA 7
#define REFERENCO_MINORA 8

namespace Ui
{class referencoj;
}

class referencoj:public QDialog
{Q_OBJECT
 public:
  explicit referencoj(QWidget *gepatro=0);
  ~referencoj();
 public slots:
  void aludojElektajxoSxangxo();
  void kompletigitaRespondo(QNetworkReply *respondo);
  void priAkceptu();
  void priCitajxo();
  void priForigu();
  void priForta();
  void priGrasa();
  void priKontribui(bool kontrolita);
  void priKursiva();
  void priMinora();
  void priReferenceita();
  void priReiru();
  void priSubstretika();
  void priSuperskribita();
  void priSuba();
  void priVakigu();
  void priMalfaru();
  void referencoEnigiSxangxo(int indekso);
 private:
  void enigi(int indekso,QString starto,QString fino,QToolButton *butono);
  void sxargiAludoj();
  cxefaFenestro *patraObjekto;
  Ui::referencoj *ui;
  htmlMarkilo *markilo;
  rikordoRegistrilo *registrilo;
  QByteArray faktaAludo;
  bool enigojAktivigita[9];
};

#endif // REFERENCOJ_H
