#ifndef PAGXOREFERENCO_H
#define PAGXOREFERENCO_H

#include <QDialog>
#include <QString>
#include <QTextDocument>
#include <QWidget>
#include "ui_pagxoreferenco.h"
#include "cxefafenestro.h"
#include "htmlmarkilo.h"

#define PAGXOREFERENCO_CITAJXO 0
#define PAGXOREFERENCO_FORTA 1
#define PAGXOREFERENCO_GRASA 2
#define PAGXOREFERENCO_KURSIVA 3
#define PAGXOREFERENCO_SUBSTRETIKA 4
#define PAGXOREFERENCO_SUPERSKRIBITA 5
#define PAGXOREFERENCO_SUBA 6
#define PAGXOREFERENCO_REFERENCEITA 7
#define PAGXOREFERENCO_MINORA 8

namespace Ui
{class pagxoReferenco;
}

class pagxoReferenco:public QDialog
{Q_OBJECT
 public:
  explicit pagxoReferenco(QWidget *gepatro,cxefaFenestro *avo);
  ~pagxoReferenco();
  void agordiLiteraturo(QString aludo);
  void agordiPagxo(QString teksto) {ui->redakto->document()->setPlainText(teksto);}
  QString akiruHtml() {return html;}
  QString akiruLiteraturo() {return literaturo;}
  QString akiruPagxo() {return pagxo;}
 public slots:
  void pagxosalto(int indekso);
  void priApliku();
  void priCitajxo();
  void priForta();
  void priGrasa();
  void priKursiva();
  void priMinora();
  void priReferenceita();
  void priRezignu();
  void priSuba();
  void priSubstretika();
  void priSuperskribita();
  void priVakigu();
 private:
  void enigi(int indekso,QString starto,QString fino,QToolButton *butono);
  QString literaturo;
  QString pagxo;
  QString html;
  Ui::pagxoReferenco *ui;
  htmlMarkilo *markilo;
  cxefaFenestro *avaObjekto;
  bool enigojAktivigita[9];
};

#endif // PAGXOREFERENCO_H
