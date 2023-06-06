#include "../Headers/femto.h"
#include "ui_femto.h"
#include "Headers/codeeditor.h"
#include "Headers/preferences.h"
#include "Headers/qregexhighlighter.h"
Femto::Femto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Femto)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);
//    QShortcut *revert_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_W), this);
//    QObject::connect(revert_shortcut, &QShortcut::activated, this, &Femto::revert);

    // Setup
    //CodeEditor* currentTab = NULL;
    ui->tabWidget->insertTab(ui->tabWidget->count(), new CodeEditor(), "Femto");

    //loadSettings();
//    int i;
//    for (i = 1; i < QApplication::arguments().size(); i++){
//        const QString fileName = QApplication::arguments().at(i);
//        readFile(fileName, 1);
//    }

    // Hihglighting
    CodeEditor* code = getCurrentFile();
    highlighter = new QRegexpHighlighter(ui->tabWidget, "text");
    highlighter->setDocument(code->document());

    if (QApplication::arguments().size() > 1) {

        QString fileName;
        QMimeType type = getMimeType(fileName);
        //code = getCurrentFile();
        code->fileName = fileName;
        for (int i = 1; i < QApplication::arguments().size(); i++){
            fileName = QApplication::arguments().at(i);

            ui->tabWidget->insertTab(ui->tabWidget->currentIndex() + 1, new CodeEditor(), "Femto");
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
            code = getCurrentFile();
            highlighter = new QRegexpHighlighter(ui->tabWidget, type.name());
            highlighter->setDocument(code->document());
            code->fileName = fileName;
        }
        setWindowTitle(fileName);
        // "filename" now contains path and name of the file to open.
    }
}

void Femto::loadSettings(){
    CodeEditor* code = getCurrentFile();
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Style");
    QColor color = qvariant_cast<QColor>(settings.value("color", QColor::fromRgb(255, 255, 255)));
    QColor bgcolor = qvariant_cast<QColor>(settings.value("bgcolor", QColor::fromRgb(14, 12, 19)));
    QFont font = qvariant_cast<QFont>(settings.value("font", QFont(QFont("Monospace", 10))));
    QFontMetrics metrics(code->font());


    code->setTabStopDistance(metrics.horizontalAdvance(' ') * 4);
    //ui->tabWidget->widget(0)->setTabStopDistance(metrics.horizontalAdvance(' ') * 4);
    code->setFont(font);
    code->changecolors();
    code->setStyleSheet("background-color: " + bgcolor.name() + "; color: " + color.name() + ";");
    //ui->textEdit->changecolors();
    settings.endGroup();
}

Femto::~Femto()
{
    delete ui;
}
CodeEditor* Femto::getCurrentFile(){
    CodeEditor* code = NULL;
    QWidget* pWidget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
    code = (CodeEditor*) pWidget;
    return code;
}
void Femto::readFile(QString fileName, int argument){




    QMimeType type = getMimeType(fileName);
    QFileInfo check_file(fileName);
    if (!check_file.exists() && (argument == 0)){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QFile::Text)){
            if (QString::compare(file.errorString(), "No file name specified") == 0){
                return;
            }
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }
//        delete highlighter;
//        QTextStream in(&file);
//        QString text = in.readAll();
//        QString tab = check_file.fileName();
//        code->setPlainText(text);
//        highlighter = new QRegexpHighlighter(this, type.name());
//        highlighter->setDocument(code->document());
//        file.close();
//        code->fileName = fileName;
//        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tab);
//        currentFile = fileName;

        return;
    }

    CodeEditor* code = getCurrentFile();
    if (!code->toPlainText().isEmpty()){
        ui->tabWidget->insertTab(ui->tabWidget->currentIndex() + 1, new CodeEditor(), "Femto");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
    }


    /*CodeEditor**/ code = getCurrentFile();

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        if (QString::compare(file.errorString(), "No file name specified") == 0){
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());

        return;
    }
    QString tab = check_file.fileName();

    //delete highlighter;
    //highlighter = new QRegexpHighlighter(this, type.name());
    //highlighter->setDocument(code->document());
    code->fileName = fileName;
    QTextStream in(&file);
    QString text = in.readAll();
    code->setPlainText(text);

    //currentFile = fileName;
    code->fileName = fileName;
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tab);
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(code->document());
    //currentFile = fileName;
    file.close();

}

void Femto::on_actionNew_triggered()
{

    CodeEditor* code = getCurrentFile();
    code->fileName.clear();
    code->setPlainText(QString());
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), "Femto");
    setWindowTitle("Femto");
}

void Femto::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select file: ");
    readFile(fileName, 0);
    //currentFile = fileName;
    setWindowTitle(fileName);
}


void Femto::on_actionSave_triggered()
{
    CodeEditor* code = getCurrentFile();
    //delete highlighter;
    QString fileName = code->fileName;
//#include <QDebug>
//    qDebug() << fileName;
    if (fileName.isEmpty()){
        fileName = QFileDialog::getSaveFileName(this, "Save as: ");
    }

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        if (QString::compare(file.errorString(), "No file name specified") == 0){
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    code->fileName = fileName;
    QTextStream out(&file);
    QString text = code->toPlainText();
    out << text;
    file.close();
    QMimeType type = getMimeType(code->fileName);
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(code->document());
    fileName = code->fileName;
    setWindowTitle(fileName);
}


void Femto::on_actionSave_as_triggered()
{
    CodeEditor* code = getCurrentFile();
    QString fileName = QFileDialog::getSaveFileName(this, "Save as: ");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        if (QString::compare(file.errorString(), "No file name specified") == 0){
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    //delete highlighter;
    QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(fileName);
//    code->fileName = fileName;
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(code->document());
    code->fileName = fileName;
    QTextStream out(&file);
    QString text = code->toPlainText();
    out << text;
    file.close();
    setWindowTitle(code->fileName);
}


void Femto::on_actionPrint_triggered()
{
    CodeEditor* code = getCurrentFile();
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if (!pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot access printer!");
        return;
    }
    code->print(&printer);


}


void Femto::on_actionExit_triggered()
{
    QApplication::exit();
}


void Femto::on_actionCopy_triggered()
{
    CodeEditor* code = getCurrentFile();
    code->copy();
}


void Femto::on_actionPaste_triggered()
{
    CodeEditor* code = getCurrentFile();
    code->paste();
}


void Femto::on_actionCut_triggered()
{
    CodeEditor* code = getCurrentFile();
    code->cut();
}


void Femto::on_actionUndo_triggered()
{
    CodeEditor* code = getCurrentFile();
    code->undo();
}


void Femto::on_actionRedo_triggered()
{
    CodeEditor* code = getCurrentFile();
    code->redo();
}


//void Femto::on_textEdit_textChanged()
//{
//    if (windowTitle().at(0) == '*'){
//        return;
//    }
//    setWindowTitle('*' + windowTitle());
//}

QMimeType Femto::getMimeType(QString fileName){
    return db.mimeTypeForFile(fileName);
}


void Femto::on_actionPreferences_triggered()
{
    Preferences preferences;
    preferences.setModal(false);
    preferences.exec();

    loadSettings();
}


void Femto::on_actionFullscreen_triggered()
{
    if (fullScreen){
        this->setWindowState(Qt::WindowFullScreen);
        fullScreen = false;
        return;
    }
    this->setWindowState(Qt::WindowMaximized);
    fullScreen = true;
}


//void Femto::revert()
//{
//    //delete ui->textEdit;
//    CodeEditor* code = getCurrentFile();
//    QTextCursor tmpCursor = code->textCursor();
//    tmpCursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
//    code->setTextCursor(tmpCursor);
//}


void Femto::on_actionNew_Tab_triggered()
{
    ui->tabWidget->insertTab(ui->tabWidget->currentIndex() + 1, new CodeEditor(), "Femto");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
    setWindowTitle("Femto");

}


void Femto::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    //CodeEditor* code = getCurrentFile();
    //setWindowTitle(code->fileName);
}





void Femto::on_tabWidget_currentChanged()
{
    CodeEditor* code = getCurrentFile();
//    currentFile = code->fileName;
    setWindowTitle(code->fileName);
}

