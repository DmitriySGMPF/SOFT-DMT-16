QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewdevtoorg.cpp \
    backend.cpp \
    devback.cpp \
    devinlist.cpp \
    downloadmanager.cpp \
    favorites.cpp \
    fileinfoforlist.cpp \
    fileman.cpp \
    infodev.cpp \
    inforight.cpp \
    main.cpp \
    mainwindow.cpp \
    reginfoforlist.cpp \
    scrollinfodev.cpp \
    sortdrives.cpp \
    sttngs.cpp

HEADERS += \
    ZYFLib.h \
    addnewdevtoorg.h \
    backend.h \
    devback.h \
    devinlist.h \
    dmt22.h \
    downloadmanager.h \
    favorites.h \
    fileinfoforlist.h \
    fileman.h \
    infodev.h \
    inforight.h \
    mainwindow.h \
    reginfoforlist.h \
    scrollinfodev.h \
    sortdrives.h \
    sttngs.h

FORMS += \
    addnewdevtoorg.ui \
    devinlist.ui \
    favorites.ui \
    fileinfoforlist.ui \
    fileman.ui \
    infodev.ui \
    inforight.ui \
    mainwindow.ui \
    reginfoforlist.ui \
    scrollinfodev.ui \
    sttngs.ui

QT += multimedia multimediawidgets

#LIBS += "D:\DMT10.dll"
LIBS += "D:\DMT22.dll"
#LIBS += "D:\DMT22.lib"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
