/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *sidebarbgButton;
    QLabel *label;
    QPushButton *sidebarfgButton;
    QLabel *label_6;
    QPushButton *backgroundButton;
    QPushButton *foregroundButton;
    QLabel *label_4;
    QPushButton *fontButton;
    QPushButton *clButton;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QString::fromUtf8("Preferences"));
        Preferences->resize(380, 240);
        buttonBox = new QDialogButtonBox(Preferences);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 200, 341, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Preferences);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 361, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        sidebarbgButton = new QPushButton(layoutWidget);
        sidebarbgButton->setObjectName(QString::fromUtf8("sidebarbgButton"));

        gridLayout->addWidget(sidebarbgButton, 4, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        sidebarfgButton = new QPushButton(layoutWidget);
        sidebarfgButton->setObjectName(QString::fromUtf8("sidebarfgButton"));

        gridLayout->addWidget(sidebarfgButton, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        backgroundButton = new QPushButton(layoutWidget);
        backgroundButton->setObjectName(QString::fromUtf8("backgroundButton"));

        gridLayout->addWidget(backgroundButton, 1, 1, 1, 1);

        foregroundButton = new QPushButton(layoutWidget);
        foregroundButton->setObjectName(QString::fromUtf8("foregroundButton"));

        gridLayout->addWidget(foregroundButton, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        fontButton = new QPushButton(layoutWidget);
        fontButton->setObjectName(QString::fromUtf8("fontButton"));

        gridLayout->addWidget(fontButton, 6, 1, 1, 1);

        clButton = new QPushButton(layoutWidget);
        clButton->setObjectName(QString::fromUtf8("clButton"));

        gridLayout->addWidget(clButton, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);


        retranslateUi(Preferences);
        QObject::connect(buttonBox, SIGNAL(accepted()), Preferences, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Preferences, SLOT(reject()));

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QCoreApplication::translate("Preferences", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Preferences", "Change background color", nullptr));
        sidebarbgButton->setText(QCoreApplication::translate("Preferences", "Sidebar background", nullptr));
        label->setText(QCoreApplication::translate("Preferences", "Change foreground color", nullptr));
        sidebarfgButton->setText(QCoreApplication::translate("Preferences", "Sidebar", nullptr));
        label_6->setText(QCoreApplication::translate("Preferences", "Change side bar background color", nullptr));
        backgroundButton->setText(QCoreApplication::translate("Preferences", "Background", nullptr));
        foregroundButton->setText(QCoreApplication::translate("Preferences", "Foreground", nullptr));
        label_4->setText(QCoreApplication::translate("Preferences", "Change side bar foreground color", nullptr));
        fontButton->setText(QCoreApplication::translate("Preferences", "Font", nullptr));
        clButton->setText(QCoreApplication::translate("Preferences", "Current line", nullptr));
        label_3->setText(QCoreApplication::translate("Preferences", "Change font", nullptr));
        label_5->setText(QCoreApplication::translate("Preferences", "Change highlighted line color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
