QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += C:\Qt\Docs\Qt-6.7.1\qtsql

SOURCES += main.cpp \
    customerwindow.cpp \
    databasemanager.cpp \
    secondwindow.cpp \
    thirdwindow.cpp \
    usermanager.cpp \
    workerwindow.cpp

HEADERS += \
    customerwindow.h \
    databasemanager.h \
    secondwindow.h \
    thirdwindow.h \
    usermanager.h \
    workerwindow.h

FORMS += \
    thirdwindow.ui \
    customerwindow.ui \
    secondwindow.ui \
    workerwindow.ui
