/*
 * Copyright (C) 2018 The Qt Company Ltd.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.
 * Neither the name of The Qt Company Ltd nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// Source code can be found here: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/widgets/codeeditor?h=5.15
#include "codeeditor.h"



CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    changecolors();
    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);


    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}


int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = lnc;

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.setFont(QFont(QFont("Monospace")));

    painter.fillRect(event->rect(), sdc);


    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(sdfc);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::changecolors(){
    //lnc = line;
    //sdc = side;
    //sdfc = sidefg;
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Style");
    lnc = qvariant_cast<QColor>(settings.value("lncolor", QColor::fromRgb(139, 0, 139)));
    sdfc = qvariant_cast<QColor>(settings.value("sideforecolor", QColor::fromRgb(255, 255, 255)));
    sdc = qvariant_cast<QColor>(settings.value("sidecolor", QColor::fromRgb(120, 0, 255)));
    settings.endGroup();
    highlightCurrentLine();
}

void CodeEditor::keyPressEvent(QKeyEvent *e){
    QChar currChar = this->document()->characterAt(this->textCursor().position() - 1);
    QChar nextChar = this->document()->characterAt(this->textCursor().position());
    switch (e->key()){
    case Qt::Key_Backspace: {
        QPlainTextEdit::keyPressEvent(e);
        if ((currChar == nextChar) && ((currChar == '"') || (currChar == '\'') || (currChar == '`'))){
            this->textCursor().deleteChar();
        } else if (((currChar == '(') && (nextChar == ')')) || ((currChar == '{') && (nextChar == '}')) || ((currChar == '[') && (nextChar == ']'))){
            this->textCursor().deleteChar();
        }
        break;
    }

    case Qt::Key_Return: {
        QChar lastChar = this->document()->characterAt(this->textCursor().position() - 1);
        QString tabs = "";
        QTextCursor curs = this->textCursor();
        curs.select(QTextCursor::BlockUnderCursor);

        static QRegularExpression rx("(?<=\u2029)(\\s+)");
        QRegularExpressionMatch match = rx.match(curs.selectedText());

        if (match.hasMatch()){
            tabs = match.captured(0);
        }
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText(tabs);
        if ((lastChar == '{' ) || (lastChar == ':')){
            this->insertPlainText("\t");
            QPlainTextEdit::keyPressEvent(e);
            this->insertPlainText(tabs);
            this->moveCursor(QTextCursor::Up, QTextCursor::MoveAnchor);
            this->moveCursor(QTextCursor::Right, QTextCursor::MoveAnchor);
        }
        break;
    }
    case Qt::Key_ParenLeft: {
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText(")");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_ParenRight:{
        if (nextChar == ')') {
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        break;
    }
    case Qt::Key_BraceLeft: {
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText("}");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_BraceRight: {
        if (nextChar == '}'){
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        break;
    }
    case Qt::Key_BracketLeft: {
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText("]");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_BracketRight: {
        if (nextChar == ']'){
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        break;
    }
    case Qt::Key_QuoteDbl: {
        if (nextChar == '"'){
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText("\"");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_Apostrophe: {
        if (nextChar == '\''){
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText("'");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_QuoteLeft: {
        if (nextChar == '`'){
            this->moveCursor(QTextCursor::Right);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        this->insertPlainText("`");
        this->moveCursor(QTextCursor::Left);
        break;
    }
    case Qt::Key_Asterisk: {
        if (currChar == '/'){
            this->insertPlainText("**/");
            this->moveCursor(QTextCursor::Left);
            this->moveCursor(QTextCursor::Left);
            break;
        }
        QPlainTextEdit::keyPressEvent(e);
        break;
    }

    default: {
        QPlainTextEdit::keyPressEvent(e);
        break;
    }
    }
}


