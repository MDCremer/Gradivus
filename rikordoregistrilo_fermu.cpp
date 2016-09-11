#include <QStack>
#include "rikordoregistrilo.h"

void rikordoRegistrilo::fermu()
{stako.push("BEGIN;");
 aktiva=false;
 malfaroButono->setEnabled(true);
}
