#include <QDateTime>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "referencoj.h"
#include "ui_referencoj.h"

void referencoj::aludojIndeksoSxangxo(QListWidgetItem *faktaArtikolo)
{if(faktaArtikolo!=0)
 {if(faktaArtikolo->text()!=faktaAludo)
  {faktaAludo=faktaArtikolo->text().toUtf8();
   ui->aludo->setText(faktaArtikolo->text());
   ui->forigu->setEnabled(true);
   QSqlDatabase datumbazo=QSqlDatabase::database();
   if(datumbazo.open())
   {QSqlQuery informpeto;
    if(informpeto.exec("SELECT html,subskribo,stato FROM literaturoj WHERE aludo='"+faktaAludo.replace("'","''")+"';"))
    {if(informpeto.first())
     {ui->teksto->setPlainText(qUncompress(informpeto.value("html").toByteArray()));
      ui->subskribo->setText(informpeto.value("subskribo").toString());
      QDateTime tempo;
      tempo.setTime_t(informpeto.value("stato").toUInt());
      ui->stato->setText(tempo.toString(Qt::SystemLocaleLongDate));
    }}
    else
     if(informpeto.lastError().isValid())
      QMessageBox::warning(this,tr("Eraro [023]!"),informpeto.lastError().text());
    datumbazo.close();
   }
   else
    if(datumbazo.lastError().isValid())
     QMessageBox::critical(this,tr("Eraro [022]!"),datumbazo.lastError().text());
 }}
 else
 {faktaAludo.clear();
  ui->forigu->setEnabled(false);
  ui->subskribo->setText(":");
  ui->stato->clear();
  ui->teksto->clear();
  ui->aludo->clear();
 }
 ui->referencoEnigi->setCurrentIndex(0);
}
