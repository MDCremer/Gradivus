#include <QFileDialog>
#include <QString>
#include "datumbazoekstrakto.h"
#include "ui_datumbazoekstrakto.h"

void datumbazoEkstrakto::priArtikoloj()
{QString haveblo=ui->artikoloj->text();
 ui->artikoloj->setText(QFileDialog::getOpenFileName(this,tr("Modelo por artikoloj"),ui->dosierujo->text()));
 if(ui->artikoloj->text().isEmpty())
  ui->artikoloj->setText(haveblo);
}
