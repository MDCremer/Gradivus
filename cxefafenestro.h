#ifndef CXEFAFENESTRO_H
#define CXEFAFENESTRO_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QWidget>
#include "agordoj.h"
#include "ui_cxefafenestro.h"

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
  void montruPriskribo(QByteArray html) {ui->informaMontro->setHtml(html);}
  QStringList etnoNomoj;
  QStringList identigiloTipoj;
  agordoj administranto;
 public slots:
  void kompletigitaRespondo(QNetworkReply *respondo);
  void priDatumbazoEkstrakto();
  void priDatumojApogilo();
  void priDatumojRestauxro();
  void priFontoj();
  void priHierarkio();
  void priIdentigiloj();
  void priIndekso();
  void priKonfiguro();
  void priMuta(int statuso);
  void priPdfEldono();
  void priPriskribo();
  void priPriskriboj();
  void priReferencoj();
  void priStartoPagxo();
  void priTezauxro();
 private:
  Ui::cxefaFenestro *ui;
  QString testiRilatoj(QStringList *celoj,QStringList *objektoj,QSqlQuery *informpeto);
};

#endif // CXEFAFENESTRO_H
