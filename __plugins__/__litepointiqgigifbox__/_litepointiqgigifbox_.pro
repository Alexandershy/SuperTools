QT += widgets\
      network\
      charts

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _LITEPOINTIQGIGIFBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_litepointiqgigifmodulea_.cpp \
    __module__/_litepointiqgigifmoduleb_.cpp \
    __pathlossdialog__/_pathlossdialog_.cpp \
    __pathlossdialog__/_pathlossdialogui_.cpp \
    __routdialog__/_routdialog_.cpp \
    __routdialog__/_routdialogui_.cpp \
    _litepointiqgigifbox_.cpp

HEADERS += \
    __module__/_litepointiqgigifmodulea_.h \
    __module__/_litepointiqgigifmoduleb_.h \
    __pathlossdialog__/_pathlossdialog_.h \
    __pathlossdialog__/_pathlossdialogui_.h \
    __routdialog__/_routdialog_.h \
    __routdialog__/_routdialogui_.h \
    _litepointiqgigifbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_litepointiqgigifmodulea_.ui \
    __module__/_litepointiqgigifmoduleb_.ui \
    __pathlossdialog__/_pathlossdialogui_.ui \
    __routdialog__/_routdialogui_.ui

DISTFILES += \
    _litepointiqgigifbox_.html \
    _litepointiqgigifbox_.pdf

RESOURCES += \
    _litepointiqgigifbox_.qrc

INCLUDEPATH +=  $$PWD/../../__api__/
INCLUDEPATH +=  $$PWD/../../../SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/

win32{
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
