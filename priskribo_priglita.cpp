#include <QPlainTextEdit>
#include "priskribo.h"
#include "ui_priskribo.h"

void priskribo::priGlita()
{ui->teksto->setFocus();
 ui->teksto->insertPlainText("float:");
}
