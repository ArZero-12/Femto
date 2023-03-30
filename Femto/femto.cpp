#include "femto.h"
#include "ui_femto.h"

#include "preferences.h"
#include "qregexhighlighter.h"
Femto::Femto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Femto)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    QShortcut *revert_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_W), this);
    QObject::connect(revert_shortcut, &QShortcut::activated, this, &Femto::revert);
    highlighter = new QRegexpHighlighter(this, "text");
    highlighter->setDocument(ui->textEdit->document());

    loadSettings();
    if (QApplication::arguments().size() > 1) {
        const QString fileName = QApplication::arguments().at(1);
        readFile(fileName, 1);
        // "filename" now contains path and name of the file to open.
    }
}

void Femto::loadSettings(){
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Style");
    QColor color = qvariant_cast<QColor>(settings.value("color", QColor::fromRgb(255, 255, 255)));
    QColor bgcolor = qvariant_cast<QColor>(settings.value("bgcolor", QColor::fromRgb(14, 12, 19)));
    QFont font = qvariant_cast<QFont>(settings.value("font", QFont(QFont("Monospace", 10))));
    QFontMetrics metrics(ui->textEdit->font());
    ui->textEdit->setTabStopDistance(metrics.horizontalAdvance(' ') * 4);
    ui->textEdit->setFont(font);
    ui->textEdit->changecolors();
    ui->textEdit->setStyleSheet("background-color: " + bgcolor.name() + "; color: " + color.name() + ";");
    ui->textEdit->changecolors();
    settings.endGroup();
}

Femto::~Femto()
{
    delete ui;
}

void Femto::readFile(QString fileName, int argument){
    QMimeType type = getMimeType(fileName);
    QFileInfo check_file(fileName);
    if (!check_file.exists()){
        QFile file(fileName);
        if ((!file.open(QIODevice::ReadOnly | QFile::Text)) && (argument == 0)){
            if (QString::compare(file.errorString(), "No file name specified") == 0){
                return;
            }
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }
        delete highlighter;
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setPlainText(text);

        highlighter = new QRegexpHighlighter(this, type.name());
        highlighter->setDocument(ui->textEdit->document());
        file.close();
        currentFile = fileName;
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        if (QString::compare(file.errorString(), "No file name specified") == 0){
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    delete highlighter;

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);


    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(ui->textEdit->document());
    currentFile = fileName;
    file.close();

}
void Femto::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setPlainText(QString());
    setWindowTitle("Femto");
}

void Femto::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select file: ");
    readFile(fileName, 0);
    currentFile = fileName;
    setWindowTitle(fileName);
}


void Femto::on_actionSave_triggered()
{
    QString fileName = currentFile;
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

    currentFile = fileName;

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    setWindowTitle(currentFile);
    QMimeType type = getMimeType(fileName);
    delete highlighter;
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(ui->textEdit->document());
}


void Femto::on_actionSave_as_triggered()
{
    delete highlighter;
    QString fileName = QFileDialog::getSaveFileName(this, "Save as: ");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        if (QString::compare(file.errorString(), "No file name specified") == 0){
            return;
        }
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(fileName);
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(ui->textEdit->document());
    currentFile = fileName;
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    setWindowTitle(fileName);
}


void Femto::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if (!pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot access printer!");
        return;
    }
    ui->textEdit->print(&printer);


}


void Femto::on_actionExit_triggered()
{
    QApplication::exit();
}


void Femto::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Femto::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Femto::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Femto::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Femto::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void Femto::on_textEdit_textChanged()
{
    if (windowTitle().at(0) == '*'){
        return;
    }
    setWindowTitle('*' + windowTitle());
}

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


void Femto::revert()
{
    //delete ui->textEdit;
    QTextCursor tmpCursor = ui->textEdit->textCursor();
    tmpCursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
    ui->textEdit->setTextCursor(tmpCursor);
}

