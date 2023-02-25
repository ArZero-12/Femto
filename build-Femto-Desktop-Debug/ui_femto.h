/********************************************************************************
** Form generated from reading UI file 'femto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEMTO_H
#define UI_FEMTO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "codeeditor.h"

QT_BEGIN_NAMESPACE

class Ui_Femto
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionPreferences;
    QWidget *centralwidget;
    CodeEditor *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;

    void setupUi(QMainWindow *Femto)
    {
        if (Femto->objectName().isEmpty())
            Femto->setObjectName(QString::fromUtf8("Femto"));
        Femto->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Femto->setWindowIcon(icon);
        Femto->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);\n"
"selection-color: cyan;\n"
"color: rgb(255, 255, 255);"));
        actionNew = new QAction(Femto);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon1);
        actionOpen = new QAction(Femto);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon2);
        actionSave = new QAction(Femto);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave->setIcon(icon3);
        actionSave_as = new QAction(Femto);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_as->setIcon(icon4);
        actionPrint = new QAction(Femto);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("document-print");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPrint->setIcon(icon5);
        actionExit = new QAction(Femto);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("document-revert");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon6);
        actionCopy = new QAction(Femto);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon7);
        actionPaste = new QAction(Femto);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon8);
        actionCut = new QAction(Femto);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon9);
        actionUndo = new QAction(Femto);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionUndo->setIcon(icon10);
        actionRedo = new QAction(Femto);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRedo->setIcon(icon11);
        actionPreferences = new QAction(Femto);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        centralwidget = new QWidget(Femto);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new CodeEditor(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 9, 771, 551));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"	border: none;\n"
"	width: 10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"	border: none;\n"
"	height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle {\n"
"	background-color: deeppink;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:hover {\n"
"	background-color: hotpink;\n"
"}\n"
"\n"
"QScrollBar::add-line {\n"
"	border: none;\n"
"	background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        textEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        Femto->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Femto);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        Femto->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionPreferences);

        retranslateUi(Femto);

        QMetaObject::connectSlotsByName(Femto);
    } // setupUi

    void retranslateUi(QMainWindow *Femto)
    {
        Femto->setWindowTitle(QCoreApplication::translate("Femto", "Femto", nullptr));
        actionNew->setText(QCoreApplication::translate("Femto", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("Femto", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("Femto", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("Femto", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("Femto", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("Femto", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("Femto", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("Femto", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("Femto", "Print", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("Femto", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("Femto", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Femto", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("Femto", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("Femto", "Paste", nullptr));
        actionCut->setText(QCoreApplication::translate("Femto", "Cut", nullptr));
        actionUndo->setText(QCoreApplication::translate("Femto", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("Femto", "Redo", nullptr));
        actionPreferences->setText(QCoreApplication::translate("Femto", "Preferences", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Femto", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Femto", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Femto: public Ui_Femto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEMTO_H
