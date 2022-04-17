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
    __formatdialog__/_formatbox_.cpp \
    __formatdialog__/_formatdialog_.cpp \
    __module__/_modulea_.cpp \
    __module__/_moduleb_.cpp \
    __module__/_modulec_.cpp \
    _wasapibox_.cpp

HEADERS += \
    __formatdialog__/_formatbox_.h \
    __formatdialog__/_formatdialog_.h \
    __module__/_modulea_.h \
    __module__/_moduleb_.h \
    __module__/_modulec_.h \
    __superchartview__/_superchartview_.h \
    __supercore__/_supercore_.h \
    __superfftw__/fftw3.h \
    __superfiledialog__/_superfiledialog_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supermultimedia__/_supermultimedia_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertab__/_supertab_.h \
    __supertabwidget__/_supertabwidget_.h \
    __superwindow__/_superwindow_.h \
    _wasapibox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __formatdialog__/_formatbox_.ui \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __module__/_modulec_.ui

DISTFILES += \
    _wasapibox_.html \
    _wasapibox_.pdf

LIBS += "C:\repos\SuperTools-Source\__api__\__superfftw__\fftw3.lib"
LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"

RESOURCES += \
    _wasapibox_.qrc \
    _wasapibox_.qrc