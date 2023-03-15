#include "qregexhighlighter.h"

QRegexpHighlighter::QRegexpHighlighter(QObject *parent, QString type) : QSyntaxHighlighter(parent){
    HighlightingRule rule;

    //classFormat.setFontWeight(QFont::Bold);
    //functionFormat.setFontItalic(true);
    //keywordFormat.setFontWeight(QFont::Bold);
    bool code = false;
    bool python = false;

    //qDebug(stderr) << "Debugging";
    if (type == "text"){
        return;
    }
    // Highlighting C/C++ keywords:
    if ((type.endsWith("csrc")) || (type.endsWith("c++src"))){
    code = true;
    keywordFormat.setForeground(Qt::cyan);
    const QString keywordPatterns[] = {
        QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
        QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
        QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
        QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
        QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
        QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
        QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
        QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
        QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
        QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b"),
        QStringLiteral("\\bthis\\b"),
    };
    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }} else

    // Highlighting Python keywords:
    if ((type.endsWith("python")) || (type.endsWith("python3"))){
    code = true;
    python = true;
    pythonKeywordFormat.setForeground(Qt::magenta);


    const QString pythonKeywordPatterns[] = {
        QStringLiteral("\\bimport\\b"), QStringLiteral("\\bfrom\\b"), QStringLiteral("\\bself\\b"),
        QStringLiteral("\\bdef\\b"), QStringLiteral("\\bis\\b"), QStringLiteral("\\bin\\b"),
        QStringLiteral("\\bnot\\b"), QStringLiteral("\\bfor\\b"), QStringLiteral("\\bTrue\\b"),
        QStringLiteral("\\bFalse\\b"), QStringLiteral("\\bglobal\\b"), QStringLiteral("\\b\and\b"),
        QStringLiteral("\\bwhile\\b"), QStringLiteral("\\bor\\b"), QStringLiteral("\\bxor\\b"),
        QStringLiteral("\\bas\\b"), QStringLiteral("\\bassert\\b"), QStringLiteral("\\bbreak\\b"),
        QStringLiteral("\\bclass\\b"), QStringLiteral("\\bcontinue\\b"), QStringLiteral("\\bdel\\b"),
        QStringLiteral("\\bif\\b"), QStringLiteral("\\belif\\b"), QStringLiteral("\\belse\\b"),
        QStringLiteral("\\bexcept\\b"), QStringLiteral("\\bfinally\\b"), QStringLiteral("\\blambda\\b"),
        QStringLiteral("\\bNone\\b"), QStringLiteral("\\bnonlocal\\b"), QStringLiteral("\\bpass\\b"),
        QStringLiteral("\\braise\\b"), QStringLiteral("\\breturn\\b"), QStringLiteral("\\btry\\b"),
        QStringLiteral("\\bwith\\b"), QStringLiteral("\\byield\\b"), QStringLiteral("\\bfor\\b")
    };
    for (const QString &pattern : pythonKeywordPatterns){
        rule.pattern = QRegularExpression(pattern);
        rule.format = pythonKeywordFormat;
        highlightingRules.append(rule);
    }} else

    // Highlighting Javascript keywords:
    if (type.endsWith("javascript")){
        code = true;
        javascriptKeywordFormat.setForeground(Qt::yellow);
        const QString javascriptKeywordPatterns[] {
            QStringLiteral("\\bimport\\b"), QStringLiteral("\\export\\b"), QStringLiteral("\\benum\\b"),
            QStringLiteral("\\benum\\b"), QStringLiteral("\\bextends\\b"), QStringLiteral("\\bsuper\\b"),
            QStringLiteral("\\babstract\\b"), QStringLiteral("\\barguments\\b"), QStringLiteral("\\bboolean\\b"),
            QStringLiteral("\\bbreak\\b"), QStringLiteral("\\bbyte\\b"), QStringLiteral("\\bcase\\b"),
            QStringLiteral("\\bcatch\\b"), QStringLiteral("\\btry\\b"), QStringLiteral("\\bfinally\\b"),
            QStringLiteral("\\bchar\\b"), QStringLiteral("\\bconst\\b"), QStringLiteral("\\bcontinue\\b"),
            QStringLiteral("\\bdebugger\\b"), QStringLiteral("\\bdefault\\b"), QStringLiteral("\\bdelete\\b"),
            QStringLiteral("\\do\\b"), QStringLiteral("\\bdouble\\b"), QStringLiteral("\\belse\\b"),
            QStringLiteral("\\beval\\b"), QStringLiteral("\\bfalse\\b"), QStringLiteral("\\bfinal\\b"),
            QStringLiteral("\\bfloat\\b"), QStringLiteral("\\bfor\\b"), QStringLiteral("\\bfunction\\b"),
            QStringLiteral("\\bgoto\\b"), QStringLiteral("\\bif\\b"), QStringLiteral("\\bimplements\\b"),
            QStringLiteral("\\bin\\b"), QStringLiteral("\\binstanceof\\b"), QStringLiteral("\\bint\\b"),
            QStringLiteral("\\binterface\\b"), QStringLiteral("\\blet\\b"), QStringLiteral("\\blong\\b"),
            QStringLiteral("\\bnative\\b"), QStringLiteral("\\bnew\\b"), QStringLiteral("\\bnull\\b"),
            QStringLiteral("\\bpackage\\b"), QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"),
            QStringLiteral("\\bpublic\\b"), QStringLiteral("\\breturn\\b"), QStringLiteral("\\bshort\\b"),
            QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bswitch\\b"), QStringLiteral("\\bsynchronized\\b"),
            QStringLiteral("\\bthis\\b"), QStringLiteral("\\bthrow\\b"), QStringLiteral("\\bthrows\\b"),
            QStringLiteral("\\btransiet\\b"), QStringLiteral("\\btrue\\b"), QStringLiteral("\\btypeof\\b"),
            QStringLiteral("\\bvar\\b"), QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"),
            QStringLiteral("\\bwhile\\b"), QStringLiteral("\\bwith\\b"), QStringLiteral("\\byield\\b"),
        };
        for (const QString &pattern : javascriptKeywordPatterns){
            rule.pattern = QRegularExpression(pattern);
            rule.format = javascriptKeywordFormat;
            highlightingRules.append(rule);
        }}

    if (code){
    // Highlighting includes:
    includeFormat.setForeground(Qt::green);
    rule.pattern = QRegularExpression(QStringLiteral("<[a-zA-Z0-9_]{1,100}>"));
    rule.format = includeFormat;
    highlightingRules.append(rule);

    // Highlighting constants
    classFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Z0-9_]{3,100}\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);

    // Highlighting numbers:
    numberFormat.setForeground(QColor::fromRgb(250, 150, 200));
    rule.pattern = QRegularExpression(QStringLiteral("\\b\\d*\\.?\\d*"));
    rule.format = numberFormat;
    highlightingRules.append(rule);

    // Highlighting double quotes:
    quotationFormat.setForeground(QColor::fromRgb(255, 153, 51));
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Highlighting single quotes:
    singleQuotationFormat.setForeground(QColor::fromRgb(255, 153, 51));
    rule.pattern = QRegularExpression(QStringLiteral("\'.*\'"));
    rule.format = singleQuotationFormat;
    highlightingRules.append(rule);

    // Highlighting functions:
    functionFormat.setForeground(QColor::fromRgb(250, 0, 127));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // Highlighting single-line comments:
    singleLineCommentFormat.setForeground(Qt::gray);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Highlighting multi-line comments:
    multiLineCommentFormat.setForeground(Qt::gray);
    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
    rule.format = multiLineCommentFormat;
    highlightingRules.append(rule);

    // Highlighting Python single-line comments:
    if (python){
        singleLineCommentFormat.setForeground(Qt::gray);
        rule.pattern = QRegularExpression(QStringLiteral("#[^\n]*"));
        rule.format = singleLineCommentFormat;
        highlightingRules.append(rule);
    }
    }



}


void QRegexpHighlighter::highlightBlock(const QString &text){
    for (const HighlightingRule &rule : std::as_const(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }

        int startIndex = 0;
        if (previousBlockState() != 1)
            startIndex = text.indexOf(commentStartExpression);
        while (startIndex >= 0) {
            QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
            int endIndex = match.capturedStart();
            int commentLength = 0;
            if (endIndex == -1) {
                setCurrentBlockState(1);
                commentLength = text.length() - startIndex;
            } else {
                commentLength = endIndex - startIndex + match.capturedLength();
            }
            setFormat(startIndex, commentLength, multiLineCommentFormat);
            startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
        }
    }
}
