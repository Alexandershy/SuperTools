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
    __datadialog__/_wavdatadialog_.cpp \
    __datadialog__/_wavdatadialogui_.cpp \
    __module__/_wavdatamodulea_.cpp \
    _wavdatabox_.cpp

HEADERS += \
    __datadialog__/_wavdatadialog_.h \
    __datadialog__/_wavdatadialogui_.h \
    __module__/_wavdatamodulea_.h \
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
    __datadialog__/_wavdatadialogui_.ui \
    __module__/_wavdatamodulea_.ui

DISTFILES += \
    _wavdatabox_.html \
    _wavdatabox_.pdf

RESOURCES += \
    _wavdatabox_.qrc

win32{
    LIBS += -luser32
    LIBS += "C:\repos\SuperTools-Source\__api__\__superfftw__\__windows__\fftw3.lib"
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superfftw__/__linux__/ -lfftw3
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
