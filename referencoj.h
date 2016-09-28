#ifndef REFERENCOJ_H
#define REFERENCOJ_H

#include <QByteArray>
#include <QDialog>
#include <QListWidgetItem>
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
  void priAbortu();
  void priCitajxo();
  void priForta();
  void priGrasa();
  void priKursiva();
  void priSubstretika();
  void priSuperskribita();
  void priSuba();
  void priReferenceita();
  void priMinora();
  void priVakigu();
  void priForigu();
  void priAkceptu();
  void priMalfaru();
  void referencoEnigiSxangxo(int indekso);
  void aludojElektajxoSxangxo();
 private:
  void sxargiAludoj();
  void enigi(int indekso,QString starto,QString fino,QToolButton *butono);
  cxefaFenestro *patraObjekto;
  Ui::referencoj *ui;
  htmlMarkilo *markilo;
  rikordoRegistrilo *registrilo;
  QByteArray faktaAludo;
  bool enigojAktivigita[9];
};

#endif // REFERENCOJ_H
