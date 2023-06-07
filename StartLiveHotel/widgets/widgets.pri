#用户界面层

HEADERS += \
    $$PWD/iabstractwidget.h

SOURCES += \
    $$PWD/iabstractwidget.cpp

include(displayTableWidgets/displayTableWidgets.pri)
include(roomWidgets/roomWidgets.pri)
include(mainWidgets/mainWidgets.pri)
