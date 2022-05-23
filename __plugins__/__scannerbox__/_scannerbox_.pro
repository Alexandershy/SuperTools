QT += widgets\
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _SCANNERBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_scannermodulea_.cpp \
    __module__/_scannermoduleb_.cpp \
    _scannerbox_.cpp

HEADERS += \
    __module__/_scannermodulea_.h \
    __module__/_scannermoduleb_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    _scannerbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_scannermodulea_.ui \
    __module__/_scannermoduleb_.ui \
    __supertab__/_supertabui_.ui

DISTFILES += \
    _scannerbox_.html \
    _scannerbox_.pdf

RESOURCES += \
    _scannerbox_.qrc

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
