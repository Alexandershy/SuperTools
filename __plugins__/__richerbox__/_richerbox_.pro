QT += widgets\
      printsupport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _RICHERBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __datadialog__/_richerdatadialog_.cpp \
    __datadialog__/_richerdatadialogui_.cpp \
    _richerbox_.cpp

HEADERS += \
    __datadialog__/_richerdatadialog_.h \
    __datadialog__/_richerdatadialogui_.h \
    __supercolordialog__/_supercolordialog_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superfinddialog__/_superfinddialog_.h \
    __superfontdialog__/_superfontdialog_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _richerbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _richerbox_.qrc

FORMS += \
    __datadialog__/_richerdatadialogui_.ui

DISTFILES += \
    _richerbox_.html \
    _richerbox_.pdf

win32{
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
