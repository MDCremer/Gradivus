#ifndef SQLMARKILO_H
#define SQLMARKILO_H

#include <QRegularExpression>
#include <QString>
#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QToolButton>

class sqlMarkilo:public QSyntaxHighlighter
{Q_OBJECT
 public:
  sqlMarkilo(QToolButton *butono,QTextDocument *gepatro=0);
 protected:
  void highlightBlock(const QString &teksto) Q_DECL_OVERRIDE;
 private:
  QToolButton *asociitaButono;
  QRegularExpression literaturoj;
  QRegularExpression identigiloj;
  QRegularExpression fontoj;
  QTextCharFormat rekonisStrukturo;
};

#endif // SQLMARKILO_H
