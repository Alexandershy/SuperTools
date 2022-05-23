QT += widgets\
      network

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _TCPSERVERBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_tcpservermodulea_.cpp \
    __module__/_tcpservermoduleb_.cpp \
    _tcpserverbox_.cpp

HEADERS += \
    __module__/_tcpservermodulea_.h \
    __module__/_tcpservermoduleb_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supernetwork__/_supernetwork_.h \
    __supertab__/_supertab_.h \
    _tcpserverbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_tcpservermodulea_.ui \
    __module__/_tcpservermoduleb_.ui \
    __supertab__/_supertabui_.ui

DISTFILES += \
    _tcpserverbox_.html \
    _tcpserverbox_.pdf

RESOURCES += \
    _tcpserverbox_.qrc

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
