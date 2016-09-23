#ifndef HTMLMARKILO_H
#define HTMLMARKILO_H

#include <QRegExp>
#include <QString>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QVector>

class htmlMarkilo:public QSyntaxHighlighter
{Q_OBJECT
 public:
  htmlMarkilo(QTextDocument *gepatro=0);
 protected:
  void highlightBlock(const QString &teksto) Q_DECL_OVERRIDE;
 private:
  struct markaRegulo
  {QRegExp sxablono;
   QTextCharFormat arangxo;
  };
  QVector<markaRegulo> reguloj;
  QRegExp komentoStartoEsprimo;
  QRegExp komentoFinoEsprimo;
  QTextCharFormat komentoArangxo;
  QTextCharFormat sxlosilvortoArangxo;
  QTextCharFormat citoArangxo;
};

#endif // HTMLMARKILO_H
