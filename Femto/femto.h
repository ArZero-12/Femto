#ifndef FEMTO_H
#define FEMTO_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFontDialog>
#include <QFontMetrics>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <fstream>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QRegularExpression>
#include <QSettings>
#include "qregexhighlighter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Femto; }
QT_END_NAMESPACE

class Femto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Femto(QWidget *parent = 0);
    ~Femto();
    void readFile(QString fileName, int argument);
private:
    //Preferences preferences;
    QRegexpHighlighter* highlighter;
    QMimeDatabase db;
    QMimeType getMimeType(QString fileName);
    void loadSettings();
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_textEdit_textChanged();

    //void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);



    void on_actionPreferences_triggered();

private:
    Ui::Femto *ui;
    QString currentFile = "";
};
#endif // FEMTO_H
