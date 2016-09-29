#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "cxefafenestro.h"

bool cxefaFenestro::konsento(QWidget *gepatro)
{QMessageBox interkonsento(gepatro);
 interkonsento.setIcon(QMessageBox::Question);
 QString titolo("<html>\n<head />\n<body>\n<p align='center'><span style='font-weight:600;'>");
 titolo.append(tr("Konsenton por la datumoj transporto"));
 titolo.append("</span></p>\n</body>\n</html>");
 interkonsento.setText(titolo);
 QString teksto("<html>\n<head />\n<body>\n<p align='justify'>");
 teksto.append(tr("Per konfirmante \304\211i mesa\304\235on, klarigi konsentas transdoni datumoj "));
 teksto.append(tr("super la interreto al la pa\304\235o, kiu estas specifita en la agordoj."));
 teksto.append("</p>\n<p align='justify'>");
 teksto.append(tr("Plie, vi konsentas ke la datumoj povus esti pasita sub la Gradivus projekto (CC BY 4.0)."));
 teksto.append("</p>\n<p align='justify'>");
 teksto.append(tr("Fine, vi meriti ke vi estas la sola rajto posedantoj pri kopirajto au similaj rajtoj "));
 teksto.append(tr("kaj ke la kopiado neniu rajtoj tria vundita."));
 teksto.append("</p>\n<p align='justify'><b>");
 teksto.append(tr("Devus aparta necertecojn pro askuron en terminoj de rajtoj, "));
 teksto.append(tr("estas pli bone por foriri de transdoni la datumojn."));
 teksto.append("</b></p>\n</body>\n</html>");
 interkonsento.setInformativeText(teksto);
 interkonsento.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
 interkonsento.setDefaultButton(QMessageBox::No);
 return interkonsento.exec()==QMessageBox::Yes;
}
