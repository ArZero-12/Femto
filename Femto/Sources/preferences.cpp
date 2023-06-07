#include "Headers/preferences.h"
#include "ui_preferences.h"



Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    loadSettings();
    //parent->setStyleSheet("background-color: black;");
//    parent->parent()->setStyleSheet("background-color: black;");

    //fontchoice = QFont("Monospace", 10);
}

Preferences::~Preferences()
{
    delete ui;
}


void Preferences::on_foregroundButton_released()
{
    Tempc = QColorDialog::getColor();
    if (Tempc == nullptr) return;
    color = Tempc;
    ui->foregroundButton->setStyleSheet("background-color: " + color.name() + ';');
}

void Preferences::loadSettings(){


//    color = qvariant_cast<QColor>(settings.value("color", QColor::fromRgb(255, 255, 255)));
//    bgcolor = qvariant_cast<QColor>(settings.value("bgcolor", QColor::fromRgb(14, 12, 19)));
//    textfont = qvariant_cast<QFont>(settings.value("font", QFont(QFont("Monospace", 10))));

//    lnc = qvariant_cast<QColor>(settings.value("lncolor", QColor::fromRgb(139, 0, 139)));
//    sdfc = qvariant_cast<QColor>(settings.value("sideforecolor", QColor::fromRgb(255, 255, 255)));
//    sdc = qvariant_cast<QColor>(settings.value("sidecolor", QColor::fromRgb(120, 0, 255)));


    QSettings settings("ArZero", "Femto");
    settings.beginGroup("Style");
    color = qvariant_cast<QColor>(settings.value("color", QColor::fromRgb(255, 255, 255)));
    bgcolor = qvariant_cast<QColor>(settings.value("bgcolor", QColor::fromRgb(14, 12, 19)));
    sdcolor = qvariant_cast<QColor>(settings.value("sidecolor", QColor::fromRgb(120, 0, 255)));
    sdfcolor = qvariant_cast<QColor>(settings.value("sideforecolor", QColor::fromRgb(255, 255, 255)));
    lncolor = qvariant_cast<QColor>(settings.value("lncolor", QColor::fromRgb(139, 0, 139)));
    fontchoice = qvariant_cast<QFont>(settings.value("font", QFont(QFont("Monospace", 10))));
    settings.endGroup();
}

void Preferences::saveSettings(){
    QSettings setting("ArZero", "Femto");
    setting.beginGroup("Style");
    setting.setValue("font", fontchoice);
    setting.setValue("color", color);
    setting.setValue("bgcolor", bgcolor);
    setting.setValue("lncolor", lncolor);
    setting.setValue("sidecolor", sdcolor);
    setting.setValue("sideforecolor", sdfcolor);
    //setting.setValue();
    setting.endGroup();
}

void Preferences::on_fontButton_released()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
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
    Tempc = QColorDialog::getColor();
    if (Tempc == nullptr) return;
    sdfcolor = Tempc;
    ui->sidebarfgButton->setStyleSheet("background-color: " + sdfcolor.name() + ';');
}



void Preferences::on_sidebarbgButton_released()
{
    Tempc = QColorDialog::getColor();
    if (Tempc == nullptr) return;
    sdcolor = Tempc;
    ui->sidebarbgButton->setStyleSheet("background-color: " + sdcolor.name() + ';');
}


void Preferences::on_clButton_pressed()
{

    Tempc = QColorDialog::getColor();
    if (Tempc == nullptr) return;
    lncolor = Tempc;
    ui->clButton->setStyleSheet("background-color: " + lncolor.name() + ';');
}


void Preferences::on_backgroundButton_released()
{
    Tempc = QColorDialog::getColor();
    if (Tempc == nullptr) return;
    bgcolor = Tempc;
    ui->backgroundButton->setStyleSheet("background-color: " + bgcolor.name() + ';');
}

