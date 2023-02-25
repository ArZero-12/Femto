#include "preferences.h"
#include "ui_preferences.h"

QColor color;
QColor bgcolor;
QColor sdcolor;
QColor sdfcolor;
QColor lncolor;
QFont fontchoice;

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    loadSettings();
    //parent->setStyleSheet("background-color: black;");
    fontchoice = QFont("Monospace", 10);
}

Preferences::~Preferences()
{
    delete ui;
}


void Preferences::on_foregroundButton_released()
{
    color = QColorDialog::getColor();
    ui->foregroundButton->setStyleSheet("background-color: " + color.name() + ';');
}

void Preferences::loadSettings(){
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Font");
    color = qvariant_cast<QColor>(settings.value("color"));
    bgcolor = qvariant_cast<QColor>(settings.value("bgcolor"));
    sdcolor = qvariant_cast<QColor>(settings.value("sidecolor"));
    sdfcolor = qvariant_cast<QColor>(settings.value("sideforecolor"));
    lncolor = qvariant_cast<QColor>(settings.value("lncolor"));
    fontchoice = qvariant_cast<QFont>(settings.value("font"));
    settings.endGroup();
}

void Preferences::saveSettings(){
    QSettings setting("ArZero", "Femto");
    setting.beginGroup("Font");
    setting.setValue("font", fontchoice);
    setting.setValue("color", color);
    setting.setValue("bgcolor", bgcolor);
    setting.setValue("lncolor", lncolor);
    setting.setValue("sidecolor", sdcolor);
    setting.setValue("sideforecolor", sdfcolor);
    //setting.setValue();
    setting.endGroup();
}
/*
void Femto::loadSettings(){
    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Font");
    QColor color = qvariant_cast<QColor>(settings.value("color"));
    QColor bgcolor = qvariant_cast<QColor>(settings.value("bgcolor"));
    QColor linecolor = qvariant_cast<QColor>(settings.value("lncolor"));
    QColor sidecolor = qvariant_cast<QColor>(settings.value("sidecolor"));
    QFont font = qvariant_cast<QFont>(settings.value("font"));
    //ui->textEdit->setFont(font);
    settings.endGroup();
}
*/
void Preferences::on_fontButton_released()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Monospace", 10), this);
    if (ok){
        fontchoice = font;
        return;
    }
    QMessageBox::warning(this, "Warning", "Cannot set font!");
}

void Preferences::on_buttonBox_accepted()
{
    saveSettings();
}

void Preferences::on_sidebarfgButton_released()
{
    sdfcolor = QColorDialog::getColor();
    ui->sidebarfgButton->setStyleSheet("background-color: " + sdfcolor.name() + ';');
}



void Preferences::on_sidebarbgButton_released()
{
    sdcolor = QColorDialog::getColor();
    ui->sidebarbgButton->setStyleSheet("background-color: " + sdcolor.name() + ';');
}


void Preferences::on_clButton_pressed()
{
    lncolor = QColorDialog::getColor();
    ui->clButton->setStyleSheet("background-color: " + lncolor.name() + ';');
}


void Preferences::on_backgroundButton_released()
{
    bgcolor = QColorDialog::getColor();
    ui->backgroundButton->setStyleSheet("background-color: " + bgcolor.name() + ';');
}

