#ifndef RIKORDOREGISTRILO_H
#define RIKORDOREGISTRILO_H

#include <QByteArray>
#include <QPushButton>
#include <QSqlQuery>
#include <QStack>

class rikordoRegistrilo
{public:
  explicit rikordoRegistrilo(QPushButton *butono);
  void aldonu(QByteArray ordono) {if(aktiva) stako.push(ordono);}
  void fermu();
  void komencu();
  bool malfaru();
  bool plenumu(QSqlQuery *registrilo,QByteArray ordono);
 private:
  QPushButton *malfaroButono;
  QStack<QByteArray> stako;
  bool aktiva;
};

#endif // RIKORDOREGISTRILO_H
