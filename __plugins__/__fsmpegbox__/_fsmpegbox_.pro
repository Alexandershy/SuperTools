QT += widgets\
      multimedia\

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _FSMPEGBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    _fsmpegbox_.html \
    _fsmpegbox_.pdf

RESOURCES += \
    _fsmpegbox_.qrc

FORMS += \
    __audioformatdialog__/_audioformatdialogui_.ui

HEADERS += \
    __audioformatdialog__/_audioformatdialog_.h \
    __audioformatdialog__/_audioformatdialogui_.h \
    _fsmpegbox_.h

SOURCES += \
    __audioformatdialog__/_audioformatdialog_.cpp \
    __audioformatdialog__/_audioformatdialogui_.cpp \
    _fsmpegbox_.cpp

INCLUDEPATH +=  $$PWD/../../__api__/
INCLUDEPATH +=  $$PWD/../../../SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/

win32{
    LIBS += "C:\repos\SuperTools-Source\__api__\__superflac__\__windows__\flac.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__superape__\__windows__\MACDll.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__supermp3__\__windows__\libmpg123-0.lib"
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superape__/__linux__/ -lMAC
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superflac__/__linux__/ -lFLAC
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__supermp3__/__linux__/ -lmpg123
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}


