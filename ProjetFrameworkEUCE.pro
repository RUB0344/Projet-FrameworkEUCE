QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 moc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/testController.cpp \
    Model/testModel.cpp \
    View/viewHome.cpp \
    View/viewMainCSV.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Controller/testController.h \
    Model/testModel.h \
    View/viewHome.h \
    View/viewMainCSV.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
