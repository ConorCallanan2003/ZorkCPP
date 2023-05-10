QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avatarwidget.cpp \
    boundary.cpp \
    heroavatar.cpp \
    item.cpp \
    level.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    avatarwidget.h \
    boundary.h \
    heroavatar.h \
    item.h \
    level.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Downloads/map.png \
    desert.png \
    field.png \
    graveyard.png

RESOURCES += \
    images.qrc
