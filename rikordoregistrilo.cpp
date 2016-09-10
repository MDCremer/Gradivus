#include <QPushButton>
#include "rikordoregistrilo.h"

rikordoRegistrilo::rikordoRegistrilo(QPushButton *butono)
{malfaroButono=butono;
 malfaroButono->setEnabled(false);
 aktiva=false;
}
