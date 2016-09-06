#include <QList>
#include <QLocale>
#include <QStringList>
#include "konfiguro.h"
#include "ui_konfiguro.h"

konfiguro::konfiguro(QWidget *gepatro):QDialog(gepatro),ui(new Ui::konfiguro)
{ui->setupUi(this);
 QList<QLocale> cxiujKulturoj=QLocale::matchingLocales(QLocale::AnyLanguage,QLocale::AnyScript,QLocale::AnyCountry);
 QStringList lingvoKodoj;
 for(int indekso=0;indekso<cxiujKulturoj.length();++indekso)
  lingvoKodoj.append(cxiujKulturoj[indekso].name());
 lingvoKodoj.sort();
 ui->kulturo->addItem(tr("loka\u0135aro"));
 for(int indekso=0;indekso<lingvoKodoj.length();++indekso)
  if(ui->kulturo->findText(lingvoKodoj[indekso])==-1)
   ui->kulturo->addItem(lingvoKodoj[indekso]);
}
