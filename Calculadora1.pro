QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include
SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/preferences.cpp

HEADERS += \
    include/mainwindow.h \
    include/preferences.h

FORMS += \
    src/mainwindow.ui \
    src/preferences.ui

TRANSLATIONS += \
    resources/traducciones/ingles.ts \
    resources/traducciones/portugues.ts \
    resources/traducciones/espanol.ts \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
include(gitversion.pri)

RESOURCES += \
    resources/traducciones.qrc
