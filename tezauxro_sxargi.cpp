#include <QFont>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "tezauxro.h"
#include "ui_tezauxro.h"

void tezauxro::sxargi()
{ui->rilatojListo->clear();
 QTreeWidgetItem *hiponimoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 QFont tiparo=hiponimoj->font(0);
 tiparo.setItalic(true);
 hiponimoj->setText(0,tr("hiponima"));
 hiponimoj->setFont(0,tiparo);
 QTreeWidgetItem *meronimoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 meronimoj->setText(0,tr("meronima"));
 meronimoj->setFont(0,tiparo);
 QTreeWidgetItem *disponebloj=new QTreeWidgetItem(ui->rilatojListo,3000);
 disponebloj->setText(0,tr("disponebla"));
 disponebloj->setFont(0,tiparo);
 QTreeWidgetItem *instrumentoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 instrumentoj->setText(0,tr("instrumenta"));
 instrumentoj->setFont(0,tiparo);
 QTreeWidgetItem *suprenirantoj=new QTreeWidgetItem(ui->rilatojListo,3000);
 suprenirantoj->setText(0,tr("supreniranta"));
 suprenirantoj->setFont(0,tiparo);
}
