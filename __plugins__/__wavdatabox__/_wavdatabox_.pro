QT += widgets\
      multimedia\
      charts

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _WAVDATABOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __datadialog__/_databox_.cpp \
    __datadialog__/_datadialog_.cpp \
    __module__/_modulea_.cpp \
    _wavdatabox_.cpp

HEADERS += \
    __datadialog__/_databox_.h \
    __datadialog__/_datadialog_.h \
    __module__/_modulea_.h \
    __superchartview__/_superchartview_.h \
    __supercore__/_supercore_.h \
    __superfftw__/fftw3.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfilemanager__/_superfilemanager_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superhook__/_superhook_.h \
    __superlogger__/_superlogger_.h \
    __supermultimedia__/_supermultimedia_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _wavdatabox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __datadialog__/_databox_.ui \
    __module__/_modulea_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __superfilemanager__/_superfilemanagerui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __superprogressbardialog__/_superprogressbardialogui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

DISTFILES += \
    _wavdatabox_.html \
    _wavdatabox_.pdf

LIBS += -luser32
LIBS += "C:\repos\SuperTools-Source\__api__\__superfftw__\__x64__\libfftw3-3.lib"
LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"

RESOURCES += \
    _wavdatabox_.qrc
