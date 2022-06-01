QT += widgets\
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _GEMINIBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_geminimodulea_.cpp \
    __module__/_geminimoduleb_.cpp \
    _geminibox_.cpp

HEADERS += \
    __module__/_geminimodulea_.h \
    __module__/_geminimoduleb_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    _geminibox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    _geminibox_.html \
    _geminibox_.pdf

RESOURCES += \
    _geminibox_.qrc

win32{
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}

FORMS += \
    __module__/_geminimodulea_.ui \
    __module__/_geminimoduleb_.ui
