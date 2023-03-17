#ifndef QREGEXPHIGHLIGHTER_H
#define QREGEXPHIGHLIGHTER_H

#include <QTextCharFormat>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QColor>
#include <QMimeType>

class QRegexpHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit QRegexpHighlighter(QObject *parent = 0, QString type = "text");
    //void setMimeType(QMimeType type);
    void highlightBlock(const QString &text);
    void setPattern(QString str){pattern = str;}
private:
    QString pattern;
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QList<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat pythonKeywordFormat;
    QTextCharFormat javascriptKeywordFormat;
    QTextCharFormat includeFormat;
    QTextCharFormat classFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat singleQuotationFormat;
    QTextCharFormat functionFormat;

    //QMimeType currentType;

};

#endif // QREGEXPHIGHLIGHTER_H
