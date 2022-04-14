QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    korttimain.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp

HEADERS += \
    korttimain.h \
    login.h \
    mainwindow.h \
    myurl.h

FORMS += \
    korttimain.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/../DLLPinCode/DLLPinCode/build/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/../DLLPinCode/DLLPinCode
DEPENDPATH += $$PWD/../DLLPinCode/DLLPinCode
