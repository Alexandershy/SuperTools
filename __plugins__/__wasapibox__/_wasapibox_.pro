QT += widgets\
      multimedia\
      charts

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _WASAPIBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __formatdialog__/_wasapiformatdialog_.cpp \
    __formatdialog__/_wasapiformatdialogui_.cpp \
    __module__/_wasapimodulea_.cpp \
    __module__/_wasapimoduleb_.cpp \
    __module__/_wasapimodulec_.cpp \
    _wasapibox_.cpp

HEADERS += \
    __formatdialog__/_wasapiformatdialog_.h \
    __formatdialog__/_wasapiformatdialogui_.h \
    __module__/_wasapimodulea_.h \
    __module__/_wasapimoduleb_.h \
    __module__/_wasapimodulec_.h \
    _wasapibox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __formatdialog__/_wasapiformatdialogui_.ui \
    __module__/_wasapimodulea_.ui \
    __module__/_wasapimoduleb_.ui \
    __module__/_wasapimodulec_.ui

DISTFILES += \
    _wasapibox_.html \
    _wasapibox_.pdf

RESOURCES +=  _wasapibox_.qrc

INCLUDEPATH +=  $$PWD/../../__api__/
INCLUDEPATH +=  $$PWD/../../../SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/

win32{
    LIBS += "C:\repos\SuperTools-Source\__api__\__superfftw__\__windows__\fftw3.lib"
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superfftw__/__linux__/ -lfftw3
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
