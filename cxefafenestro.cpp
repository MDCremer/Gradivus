#include <QCheckBox>
#include <QMainWindow>
#include <QPushButton>
#include <QStringList>
#include <QWidget>
#include <QWebEngineSettings>
#include <QtWebEngineWidgets>
#include "cxefafenestro.h"
#include "ui_cxefafenestro.h"
#include "agordoj.h"
#include "hipertekstopagxo.h"

cxefaFenestro::cxefaFenestro(QWidget *gepatro):QMainWindow(gepatro),ui(new Ui::cxefaFenestro)
{QWebEngineSettings *foliumiloAgordoj=QWebEngineSettings::globalSettings();
 foliumiloAgordoj->setFontSize(QWebEngineSettings::DefaultFontSize,16);
 foliumiloAgordoj->setFontFamily(QWebEngineSettings::SansSerifFont,"Noto Sans UI");
 ui->setupUi(this);
 ui->informaMontro->setPage(new hipertekstoPagxo(this,this));
 connect(ui->datumojApogilo,&QPushButton::clicked,this,&cxefaFenestro::priDatumojApogilo);
 connect(ui->konfiguro,&QPushButton::clicked,this,&cxefaFenestro::priKonfiguro);
 connect(ui->referencoj,&QPushButton::clicked,this,&cxefaFenestro::priReferencoj);
 connect(ui->muta,&QCheckBox::stateChanged,this,&cxefaFenestro::priMuta);
 connect(ui->startoPagxo,&QPushButton::clicked,this,&cxefaFenestro::priStartoPagxo);
 connect(ui->datumojRestauxro,&QPushButton::clicked,this,&cxefaFenestro::priDatumojRestauxro);
 connect(ui->identigiloj,&QPushButton::clicked,this,&cxefaFenestro::priIdentigiloj);
 connect(ui->indekso,&QPushButton::clicked,this,&cxefaFenestro::priIndekso);
 connect(ui->pdfEldono,&QPushButton::clicked,this,&cxefaFenestro::priPdfEldono);
 connect(ui->priskribo,&QPushButton::clicked,this,&cxefaFenestro::priPriskribo);
 connect(ui->datumbazoEkstrakto,&QPushButton::clicked,this,&cxefaFenestro::priDatumbazoEkstrakto);
 connect(ui->fontoj,&QPushButton::clicked,this,&cxefaFenestro::priFontoj);
 etnoNomoj=QStringList()<<tr("AD: andoranoj")<<tr("AE: anoj de Unui\304\235intaj Arabaj Emirlandoj")<<tr("AF: afganoj")
   <<tr("AG: antigvanoj kaj barbudanoj")<<tr("AL: albanoj")<<tr("AM: armenoj")<<tr("AO: angolanoj")<<tr("AR: argentinanoj")
   <<tr("AT: a\305\255stroj")<<tr("AU: a\305\255stralianoj")<<tr("AZ: azerbaj\304\235ananoj")
   <<tr("BA: bosnoj kaj hercegovinanoj")<<tr("BB: barbadanoj")<<tr("BD: banglade\304\235anoj")<<tr("BE: belgoj")
   <<tr("BF: burkinanoj")<<tr("BG: bulgaroj")<<tr("BH: barejnanoj")<<tr("BI: burundanoj")<<tr("BJ: beninanoj")
   <<tr("BN: brunejanoj")<<tr("BO: bolivianoj")<<tr("BR: brazilanoj")<<tr("BS: bahamanoj")<<tr("BT: butananoj")
   <<tr("BW: bocvananoj")<<tr("BY: belarusoj")<<tr("BZ: belizanoj")<<tr("CA: kanadanoj")
   <<tr("CD: anoj de Demokratia Respubliko Kongo")<<tr("CF: centrafrikanoj")<<tr("CG: anoj de Respubliko Kongo")
   <<tr("CH: svisoj")<<tr("CI: eburbordanoj")<<tr("CL: \304\211ilianoj")<<tr("CM: kamerunanoj")<<tr("CN: \304\211inoj")
   <<tr("CO: kolombianoj")<<tr("CR: kostarikanoj")<<tr("CU: kubanoj")<<tr("CV: kaboverdanoj")<<tr("CY: kipranoj")
   <<tr("CZ: \304\211e\304\245oj")<<tr("DE: germanoj")<<tr("DJ: \304\235ibutianoj")<<tr("DK: danoj")<<tr("DM: dominikanoj")
   <<tr("DO: dominganoj")<<tr("DZ: al\304\235erianoj")<<tr("EC: ekvadoranoj")<<tr("EE: estonoj")<<tr("EG: egiptoj")
   <<tr("ER: eritreanoj")<<tr("ES: hispanoj")<<tr("ET: etiopoj")<<tr("FI: finnoj")<<tr("FJ: fi\304\235ianoj")
   <<tr("FO: feroanoj")<<tr("FR: francoj")<<tr("GA: gabonanoj")<<tr("GB: britoj")<<tr("GD: grenadanoj")<<tr("GE: kartveloj")
   <<tr("GH: ganaanoj")<<tr("GL: gronlandanoj")<<tr("GM: gambianoj")<<tr("GN: gvineanoj")<<tr("GQ: anoj de Ekvatora Gvineo")
   <<tr("GR: grekoj")<<tr("GT: gvatemalanoj")<<tr("GW: gvineo-bisa\305\255anoj")<<tr("GY: gujananoj")<<tr("HN: honduranoj")
   <<tr("HR: kroatoj")<<tr("HT: haitianoj")<<tr("HU: hungaroj")<<tr("ID: indonezianoj")<<tr("IE: irlandanoj")
   <<tr("IL: israelanoj")<<tr("IN: baratanoj")<<tr("IQ: irakanoj")<<tr("IR: irananoj")<<tr("IS: islandanoj")
   <<tr("IT: italoj")<<tr("JM: jamajkanoj")<<tr("JO: jordanianoj")<<tr("JP: japanoj")<<tr("KE: kenjanoj")
   <<tr("KG: kirgistananoj")<<tr("KH: kambo\304\235anoj")<<tr("KI: kiribatanoj")<<tr("KM: komoranoj")
   <<tr("KN: anoj de Sankta Kristoforo kaj Neviso")<<tr("KP: nord-koreanoj")<<tr("KR: koreanoj")<<tr("KU: kurdoj")
   <<tr("KW: kuvajtanoj")<<tr("KZ: kaza\304\245stananoj")<<tr("LA: laosanoj")<<tr("LB: libananoj")<<tr("LC: sent-lucianoj")
   <<tr("LI: li\304\245ten\305\235tejnanoj")<<tr("LK: srilankanoj")<<tr("LR: liberianoj")<<tr("LS: lesotanoj")
   <<tr("LT: litovoj")<<tr("LU: luksemburganoj")<<tr("LV: latvoj")<<tr("LY: libianoj")<<tr("MA: marokanoj")
   <<tr("MC: monakanoj")<<tr("MD: moldavoj")<<tr("ME: montenegranoj")<<tr("MG: madagaskaranoj")<<tr("MH: mar\305\235alanoj")
   <<tr("MK: makedonoj")<<tr("ML: malianoj")<<tr("MM: birmanoj")<<tr("MN: mongoloj")<<tr("MO: makaanoj")
   <<tr("MR: ma\305\255ritanoj")<<tr("MT: maltanoj")<<tr("MU: ma\305\255ricianoj")<<tr("MV: maldivanoj")
   <<tr("MW: malavianoj")<<tr("MX: meksikanoj")<<tr("MY: malajzianoj")<<tr("MZ: mozambikanoj")<<tr("NA: namibianoj")
   <<tr("NE: ni\304\235eranoj")<<tr("NG: ni\304\235erianoj")<<tr("NI: nikeragvanoj")<<tr("NL: nederlandanoj")
   <<tr("NO: norvegoj")<<tr("NP: nepalanoj")<<tr("NR: nauranoj")<<tr("NZ: nov-zelandanoj")<<tr("OM: omananoj")
   <<tr("PA: panamanoj")<<tr("PE: peruanoj")<<tr("PG: papuanoj")<<tr("PK: pakistananoj")<<tr("PL: poloj")
   <<tr("PR: portorikanoj")<<tr("PS: palestinanoj")<<tr("PT: portugaloj")<<tr("PW: pala\305\255anoj")
   <<tr("PY: paragvajanoj")<<tr("QR: kataranoj")<<tr("RO: rumanuoj")<<tr("RS: serboj")<<tr("RU: rusoj")<<tr("RW: ruandanoj")
   <<tr("SA: saud-araboj")<<tr("SC: sej\305\235elanoj")<<tr("SD: sudananoj")<<tr("SE: svedoj")<<tr("SG: singapuranoj")
   <<tr("SK: slovakoj")<<tr("SI: slovenoj")<<tr("SM: sanmariananoj")<<tr("SN: senegaleanoj")<<tr("SO: somaloj")
   <<tr("SR: surinamanoj")<<tr("SS: sud-sudananoj")<<tr("ST: saotomeanoj")<<tr("SV: salvadoranoj")<<tr("SY: sirianoj")
   <<tr("SZ: svazioj")<<tr("TB: tibetanoj")<<tr("TD: \304\211adanoj")<<tr("TG: togolanoj")<<tr("TH: tajoj")
   <<tr("TJ: ta\304\235ikistananoj")<<tr("TL: orienta-timoranoj")<<tr("TM: turkmenoj")<<tr("TN: tunizianoj")
   <<tr("TO: tonganoj")<<tr("TR: turkoj")<<tr("TT: trinidadanoj kaj tobaganoj")<<tr("TV: tuvalanoj")<<tr("TW: tajvananoj")
   <<tr("TZ: tanzanianoj")<<tr("UA: ukrajnanoj")<<tr("UG: ugandanoj")<<tr("US: usonanoj")<<tr("UY: urugvajanoj")
   <<tr("UZ: uzbekistananoj")<<tr("VA: vatikananoj")<<tr("VC: sent-vincentanoj kaj grenadinanoj")<<tr("VE: venezuelanoj")
   <<tr("VN: vjetnamoj")<<tr("VU: vanuatuanoj")<<tr("WS: samoanoj")<<tr("YE: jemenanoj")<<tr("ZA: sud-afrikanoj")
   <<tr("ZM: zambianoj")<<tr("ZW: zimbabvanoj");
 identigiloTipoj=QStringList()<<tr("Plena identigilo")<<tr("Parte \305\235parvojo")<<tr("\305\234parvojo")<<
   tr("Kamuflada identigilo")<<tr("Fabrikanta identigilo")<<tr("Alnomo")<<tr("Komisio kodo");
 administranto.sxargu();
 montruInformo("bonvenon");
}
