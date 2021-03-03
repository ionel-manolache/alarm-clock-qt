QT += core
QT += gui
QT += multimedia
QT += widgets

TARGET = alarm-clock-qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/alarmsdialog.cpp \
    src/application.cpp \
    src/main.cpp \
    src/preferencesdialog.cpp \
    src/settings.cpp \
    src/alarms.cpp \

HEADERS += \
    src/alarmsdialog.h \
    src/application.h \
    src/preferencesdialog.h \
    src/settings.h \
    src/alarms.h \

FORMS += \
    forms/alarmsdialog.ui \
    forms/preferencesdialog.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc
