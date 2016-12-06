#include <QFileDialog>
#include <QString>
#include "datumbazoekstrakto.h"
#include "ui_datumbazoekstrakto.h"

void datumbazoEkstrakto::priDosierujo()
{QString haveblo=ui->dosierujo->text();
 ui->dosierujo->setText(QFileDialog::getExistingDirectory(this,tr("Dosierujo por ekstrakto"),haveblo,
   QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks));
 if(ui->dosierujo->text().isEmpty())
  ui->dosierujo->setText(haveblo);
}
