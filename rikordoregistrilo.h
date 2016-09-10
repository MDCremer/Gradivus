#ifndef RIKORDOREGISTRILO_H
#define RIKORDOREGISTRILO_H

#include <QByteArray>
#include <QPushButton>
#include <QStack>

class rikordoRegistrilo
{public:
  explicit rikordoRegistrilo(QPushButton *butono);
 private:
  QPushButton *malfaroButono;
  QStack<QByteArray> stako;
  bool aktiva;
};

#endif // RIKORDOREGISTRILO_H
