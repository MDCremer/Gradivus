#include <QFont>
#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QToolButton>
#include "sqlmarkilo.h"

sqlMarkilo::sqlMarkilo(QToolButton *butono,QTextDocument *gepatro):QSyntaxHighlighter(gepatro)
{asociitaButono=butono;
 literaturoj=QRegularExpression("^INSERT\\sOR\\sREPLACE\\sINTO\\sliteraturoj\\s\\(aludo,html,subskribo,stato\\)\\sVALUES\\s\
\\(\\'([^\\']+|\\'{2})+\\',[xX]\\'([0-9A-Fa-f]{2})+\\',\\':([^\\']+|\\'{2})+:\\',[0-9]+\\);$");
 identigiloj=QRegularExpression("^INSERT\\sOR\\sREPLACE\\sINTO\\sidentigiloj\\s\\(etno,nomo,lingvo,tipo,literaturo,pagxo,uu\
id,subskribo,stato\\)\\sVALUES\\s\\(\\'[A-Z]{2}\\',\\'([^\\']+|\\'{2})+\\',\\'[a-z]{2}\\',[0-9]+,(NULL|\\'([^\\']+|\\'{2})+\
\\'),(NULL|[xX]\\'([0-9A-Fa-f]{2})+\\'),\\'[a-zA-Z0-9_-]{22}\\',\\':([^\\']+|\\'{2})+:\\',[0-9]+\\);$");
 fontoj=QRegularExpression("^INSERT\\sOR\\sREPLACE\\sINTO\\sfontoj\\s\\(uuid,aludo,literaturo,pagxo,subskribo,stato\\)\\sVA\
LUES\\s\\(\\'[a-zA-Z0-9_-]{22}\\',\\'[a-zA-Z0-9]{3}\\',(NULL|\\'([^\\']+|\\'{2})+\\'),(NULL|[xX]\\'([0-9A-Fa-f]{2})+\\'),\\\
':([^\\']+|\\'{2})+:\\',[0-9]+\\);$");
 rekonisStrukturo.setForeground(Qt::darkGreen);
 rekonisStrukturo.setFont(QFont("Monospace",9,QFont::Bold,false));
}
