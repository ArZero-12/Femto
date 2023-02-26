#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QSettings>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = nullptr);

    void loadSettings();
    void saveSettings();

    ~Preferences();

private slots:
    void on_buttonBox_accepted();

    void on_foregroundButton_released();

    void on_fontButton_released();



    void on_sidebarfgButton_released();

    void on_sidebarbgButton_released();

    void on_clButton_pressed();

    void on_backgroundButton_released();

private:
    Ui::Preferences *ui;
};

#endif // PREFERENCES_H
