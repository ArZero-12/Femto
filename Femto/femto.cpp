#include "femto.h"
#include "ui_femto.h"
#include "preferences.h"

Femto::Femto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Femto)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    QFontMetrics metrics(ui->textEdit->font());
    highlighter = new QRegexpHighlighter(this, "text");
    highlighter->setDocument(ui->textEdit->document());
    ui->textEdit->setTabStopDistance(metrics.horizontalAdvance(' ') * 4);
    loadSettings();

    if (QApplication::arguments().size() > 1) {
        const QString fileName = QApplication::arguments().at(1);
        readFile(fileName, 1);
        // "filename" now contains path and name of the file to open.
    }
}

void Femto::loadSettings(){
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Font");
    QColor color = qvariant_cast<QColor>(settings.value("color"));
    QColor bgcolor = qvariant_cast<QColor>(settings.value("bgcolor"));
    QFont font = qvariant_cast<QFont>(settings.value("font"));
    ui->textEdit->setFont(font);
    ui->textEdit->changecolors();
    this->setStyleSheet("background-color: " + bgcolor.name() + "; color: " + color.name() + ";");
    settings.endGroup();
}

Femto::~Femto()
{
    delete ui;
}

void Femto::readFile(QString fileName, int argument){
    QMimeType type = getMimeType(fileName);
    //qDebug() << "Mime type:" << type.name();
    //ui->textEdit->setText(type.name());
    delete highlighter;
    QFileInfo check_file(fileName);
    if ((!check_file.exists()) && (argument == 0)){
        delete highlighter;
        QFile file(fileName);
        currentFile = fileName;
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setPlainText(text);
        highlighter = new QRegexpHighlighter(this, type.name());
        highlighter->setDocument(ui->textEdit->document());
        file.close();
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    currentFile = fileName;
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);


    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(ui->textEdit->document());

    //currentFile = fileName;
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
    //std::cout << fileName.toStdString();
    readFile(fileName, 0);
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
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFile = fileName;

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

    /*
    delete highlighter;
    QMimeType type = db.mimeTypeForFile(fileName);
    highlighter = new QRegexpHighlighter(this, type.name());
    highlighter->setDocument(ui->textEdit->document());
    */

    setWindowTitle(fileName);
}


void Femto::on_actionSave_as_triggered()
{
    delete highlighter;
    QString fileName = QFileDialog::getSaveFileName(this, "Save as: ");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
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
    if (windowTitle()[0] == '*'){
        return;
    }
    setWindowTitle('*' + windowTitle());
}

QMimeType Femto::getMimeType(QString fileName){
    return db.mimeTypeForFile(fileName);
}

void Femto::saveSettings(QFont font){
    QSettings setting("ArZero", "Femto");
    setting.beginGroup("Font");
    setting.setValue("font", font);
    setting.endGroup();
}

void Femto::on_actionChange_Font_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Monospace", 10), this);
    if (ok){
        ui->textEdit->setFont(font);
        saveSettings(font);

        return;
    }
    QMessageBox::warning(this, "Warning", "Cannot set font!");


}


void Femto::on_actionPreferences_triggered()
{
    Preferences preferences;
    preferences.setModal(false);
    preferences.exec();

    loadSettings();
}

