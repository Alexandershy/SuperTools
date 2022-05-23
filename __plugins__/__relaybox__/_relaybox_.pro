QT += widgets\
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _RELAYBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __channel15__/_channel15_.cpp \
    __channel34__/_channel34_.cpp \
    __module__/_relaymodulea_.cpp \
    __module__/_relaymoduleb_.cpp \
    __module__/_relaymodulec_.cpp \
    _relaybox_.cpp

HEADERS += \
    __channel15__/_channel15_.h \
    __channel34__/_channel34_.h \
    __module__/_relaymodulea_.h \
    __module__/_relaymoduleb_.h \
    __module__/_relaymodulec_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _relaybox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    _relaybox_.html \
    _relaybox_.pdf

RESOURCES += \
    _relaybox_.qrc

FORMS += \
    __channel15__/_channel15_.ui \
    __channel34__/_channel34_.ui \
    __module__/_relaymodulea_.ui \
    __module__/_relaymoduleb_.ui \
    __module__/_relaymodulec_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
