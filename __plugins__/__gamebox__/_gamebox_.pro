QT += widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib

DEFINES += _GAMEBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _gamebox_.qrc

DISTFILES += \
    _gamebox_.html \
    _gamebox_.pdf

FORMS += \
    __hitbricks__/_hitbricksdialogui_.ui \
    __module__/_gamemodulea_.ui

HEADERS += \
    __hitbricks__/_hitbricksdialog_.h \
    __hitbricks__/_hitbricksdialogui_.h \
    __hitbricks__/_hitbricksscene_.h \
    __module__/_gamemodulea_.h \
    __object__/_littleball_.h \
    __object__/_littlebrick_.h \
    __object__/_littleskate_.h \
    __object__/_littletext_.h \
    _gamebox_.h

SOURCES += \
    __hitbricks__/_hitbricksdialog_.cpp \
    __hitbricks__/_hitbricksdialogui_.cpp \
    __hitbricks__/_hitbricksscene_.cpp \
    __module__/_gamemodulea_.cpp \
    __object__/_littleball_.cpp \
    __object__/_littlebrick_.cpp \
    __object__/_littleskate_.cpp \
    __object__/_littletext_.cpp \
    _gamebox_.cpp

INCLUDEPATH +=  $$PWD/../../__api__/
INCLUDEPATH +=  $$PWD/../../../SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/

win32{
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
