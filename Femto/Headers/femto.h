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
#include <QMimeData>
#include <QMimeDatabase>
#include <QRegularExpression>
#include <QSettings>
#include <QShortcut>
#include <QDir>
#include "qregexhighlighter.h"
#include <Headers/codeeditor.h>
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
    //CodeEditor* code = NULL;
    CodeEditor* getCurrentFile();
    QRegexpHighlighter* highlighter;
    QMimeDatabase db;
    QMimeType getMimeType(QString fileName);
    void loadSettings();
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    //void dragMoveEvent(QDragMoveEvent *event) override;
    //void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

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

//    void on_textEdit_textChanged();

    //void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);

    void on_actionPreferences_triggered();

    void on_actionFullscreen_triggered();

//    void revert();
    void on_actionNew_Tab_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    //void on_tabWidget_tabBarClicked(int index);

    void on_tabWidget_currentChanged();

private:
    Ui::Femto *ui;
//    QString currentFile = "";
    bool fullScreen = true;
};
#endif // FEMTO_H
