#ifndef DATUMBAZOEKSTRAKTO_H
#define DATUMBAZOEKSTRAKTO_H

#include <QDialog>
#include <QWidget>

namespace Ui
{class datumbazoEkstrakto;
}

class datumbazoEkstrakto:public QDialog
{Q_OBJECT
 public:
  explicit datumbazoEkstrakto(QWidget *gepatro);
  ~datumbazoEkstrakto();
 private:
  Ui::datumbazoEkstrakto *ui;
};

#endif // DATUMBAZOEKSTRAKTO_H
