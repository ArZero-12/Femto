QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/codeeditor.cpp \
    Sources/femto.cpp \
    Sources/main.cpp \
    Sources/preferences.cpp \
    Sources/qregexhighlighter.cpp

HEADERS += \
    Headers/codeeditor.h \
    Headers/femto.h \
    Headers/preferences.h \
    Headers/qregexhighlighter.h

FORMS += \
    Forms/femto.ui \
    Forms/preferences.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Resources.qrc

DISTFILES +=

TARGET = femto
RC_ICONS = icon.ico
macx:ICON = Resources/icon.icns
