#ifndef PROVAJXO_H
#define PROVAJXO_H

#include <QByteArray>
#include <QDialog>
#include <QPlainTextEdit>
#include <QString>
#include <QWidget>
#include "ui_provajxo.h"
#include "htmlmarkilo.h"

namespace Ui
{class provajxo;
}

class provajxo:public QDialog
{Q_OBJECT
 public:
  explicit provajxo(QWidget *gepatro=0);
  ~provajxo();
  void agordiCxefsxlosilo(QByteArray teksto) {ui->cxefsxlosilo->setText(teksto);}
  void agordiKodo(QByteArray teksto) {ui->kodo->setPlainText(teksto);}
  void agordiMalnovaDatumoj(QByteArray teksto) {ui->malnovaDatumoj->setHtml(teksto);}
  void agordiMalnovaSubskribo(QByteArray teksto) {ui->malnovaSubskribo->setText(teksto);}
  void agordiMalnovaStato(QString teksto) {ui->malnovaStato->setText(teksto);}
  void agordiRekomendo(QString teksto) {ui->rekomendo->setText(teksto);}
  void agordiSubskribo(QByteArray teksto) {ui->subskribo->setText(teksto);}
  void agordiStato(QString teksto) {ui->stato->setText(teksto);}
  void agordiVido(QByteArray teksto) {ui->vido->setHtml(teksto);}
  void montruVidon() {ui->tabWidget->setCurrentIndex(1);}
 public slots:
  void priAbortu();
 private:
  Ui::provajxo *ui;
  htmlMarkilo *markilo;
};

#endif // PROVAJXO_H
