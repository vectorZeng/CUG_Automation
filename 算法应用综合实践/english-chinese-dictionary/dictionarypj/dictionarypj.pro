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
    form1.cpp \
    form2.cpp \
    form3.cpp \
    hashmap.cpp \
    main.cpp \
    orderedlist.cpp \
    tool.cpp \
    trietree.cpp \
    widget.cpp

HEADERS += \
    form1.h \
    form2.h \
    form3.h \
    hashmap.h \
    orderedlist.h \
    tool.h \
    trietree.h \
    widget.h

FORMS += \
    form1.ui \
    form2.ui \
    form3.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
