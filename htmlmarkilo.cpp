#include <QFont>
#include <QStringList>
#include <QSyntaxHighlighter>
#include "htmlmarkilo.h"

htmlMarkilo::htmlMarkilo(QTextDocument *gepatro):QSyntaxHighlighter(gepatro)
{markaRegulo regulo;
 sxlosilvortoArangxo.setForeground(Qt::darkRed);
 sxlosilvortoArangxo.setFont(QFont("Monospace",9,QFont::Medium,false));
 QStringList sxlosilvortoSxablonoj;
 sxlosilvortoSxablonoj<<"<\\s*/?[Cc][Ii][Tt][Ee]\\s*>"<<"<\\s*/?[Ss][Tt][Rr][Oo][Nn][Gg]\\s*>"<<"<\\s*/?[Bb]\\s*>"<<
   "<\\s*/*[Ii]\\s*>"<<"<\\s*/?[Uu]\\s*>"<<"<\\s*/?[Ss][Uu]([Pp]|[Bb])\\s*>"<<"<\\s*/?[Ss][Mm][Aa][Ll][Ll]\\s*>"<<
   "<\\s*(([Bb][Rr])|([Hh][Rr]))\\s*>"<<
   "<\\s*[Aa]\\s+(([Hh][Rr][Ee][Ff])|([Nn][Aa][Mm][Ee]))\\s*=\\s*([\"'][^\"']*[\"'])+\\s*>"<<"<\\s*/[Aa]\\s*>"<<
   "<\\s*[Bb][Ll][Oo][Cc][Kk][Qq][Uu][Oo][Tt][Ee](\\s+(([Cc][Ii][Tt][Ee])|([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss])|\
([Tt][Ii][Tt][Ll][Ee]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<"<\\s*/[Hh][123456]\\s*>"<<"<\\s*/?[Cc][Oo][Dd][Ee]\\s*>"<<
   "<\\s*/?[Ee][Mm]\\s*>"<<"<\\s*/?[Ss][Aa][Mm][Pp][Ll][Ee]\\s*>"<<"<\\s*/[Tt][Hh][Ee][Aa][Dd]\\s*>"<<
   "<\\s*[Hh][123456](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Ii][Mm][Gg]\\s+((([Ww][Ii][Dd][Tt][Hh])|([Hh][Ee][Ii][Gg][Hh][Tt])|([Ss][Rr][Cc])|([Ss][Tt][Yy][Ll][Ee])|([Aa]\
[Ll][Tt])|([Tt][Ii][Tt][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"'])\\s*)+>"<<
   "<\\s*[Pp](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*/[Pp]\\s*>"<<"<\\s*/[Bb][Ll][Oo][Cc][Kk][Qq][Uu][Oo][Tt][Ee]\\s*>"<<"<\\s*/?[Dd][Ff][Nn]\\s*>"<<
   "<\\s*([Uu]|[Oo]|[Dd])[Ll](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Ll][Ii](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*/([Uu]|[Oo]|[Dd])[Ll]\\s*>"<<"<\\s*/[Ll][Ii]\\s*>"<<"<\\s*/[Dd]([Tt]|[Dd])\\s*>"<<
   "<\\s*[Dd]([Tt]|[Dd])(\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*/[Tt]([Rr]|[Dd])\\s*>"<<"<\\s*/[Tt][Aa][Bb][Ll][Ee]\\s*>"<<
   "<\\s*[Tt]([Rr]|[Dd])(\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Tt][Aa][Bb][Ll][Ee](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Tt][Hh][Ee][Aa][Dd](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*(([Ff][Ii][Gg][Uu][Rr][Ee])|([Ff][Ii][Gg][Cc][Aa][Pp][Tt][Ii][Oo][Nn]))(\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa]\
[Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*/(([Ff][Ii][Gg][Uu][Rr][Ee])|([Ff][Ii][Gg][Cc][Aa][Pp][Tt][Ii][Oo][Nn]))\\s*>"<<
   "<\\s*[Pp][Rr][Ee](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*/[Pp][Rr][Ee]\\s*>"<<"<\\s*/[Aa][Ss][Ii][Dd][Ee]\\s*>"<<"<\\s*/[Dd][Ii][Vv]\\s*>"<<"<\\s*/[Ss][Aa][Mm][Pp]\\s*>"<<
   "<\\s*[Aa][Ss][Ii][Dd][Ee](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Dd][Ii][Vv](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>"<<
   "<\\s*[Ss][Aa][Mm][Pp](\\s+(([Ss][Tt][Yy][Ll][Ee])|([Cc][Ll][Aa][Ss][Ss]))\\s*=\\s*([\"'][^\"']*[\"']))*\\s*>";                                            ;
 foreach(const QString &sxablono,sxlosilvortoSxablonoj)
 {regulo.sxablono=QRegExp(sxablono);
  regulo.arangxo=sxlosilvortoArangxo;
  reguloj.append(regulo);
 }
 citoArangxo.setForeground(Qt::darkBlue);
 citoArangxo.setFont(QFont("Monospace",9,QFont::Light,false));
 regulo.sxablono=QRegExp("\"[^\"]*\"");
 regulo.arangxo=citoArangxo;
 reguloj.append(regulo);
 regulo.sxablono=QRegExp("'[^']*'");
 reguloj.append(regulo);
 komentoArangxo.setForeground(Qt::darkGray);
 komentoArangxo.setFont(QFont("Monospace",9,QFont::Medium,true));
 komentoStartoEsprimo=QRegExp("<!--");
 komentoFinoEsprimo=QRegExp("-->");
}
