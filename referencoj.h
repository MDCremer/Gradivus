#ifndef REFERENCOJ_H
#define REFERENCOJ_H

#include <QDialog>
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
  void referencoEnigiSxangxo(int indekso);
 private:
  void sxargiAludoj();
  void enigi(int indekso,QString starto,QString fino,QToolButton *butono);
  cxefaFenestro *patraObjekto;
  Ui::referencoj *ui;
  htmlMarkilo *markilo;
  rikordoRegistrilo *registrilo;
  bool enigojAktivigita[9];
};

#endif // REFERENCOJ_H
