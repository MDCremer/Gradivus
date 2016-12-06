#include <QFileDialog>
#include <QString>
#include "datumbazoekstrakto.h"
#include "ui_datumbazoekstrakto.h"

void datumbazoEkstrakto::priIndekso()
{QString haveblo=ui->indekso->text();
 ui->indekso->setText(QFileDialog::getOpenFileName(this,tr("Modelo por indekso"),ui->dosierujo->text()));
 if(ui->indekso->text().isEmpty())
  ui->indekso->setText(haveblo);
}
