QT += widgets\
      multimedia\
      printsupport

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
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supermultimedia__/_supermultimedia_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __superplot__/_superplot_.cpp \
    __superplot__/qcustomplot.cpp \
    __supertab__/_supertab_.cpp \
    __supertabwidget__/_supertabwidget_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _wasapibox_.cpp

HEADERS += \
    __formatdialog__/_formatbox_.h \
    __formatdialog__/_formatbox__ui.h \
    __formatdialog__/_formatdialog_.h \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
    __module__/_moduleb_.h \
    __module__/_moduleb__ui_.h \
    __module__/_modulec_.h \
    __module__/_modulec__ui_.h \
    __supercore__/_supercore_.h \
    __superfftw__/fftw3.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supermultimedia__/_supermultimedia_.h \
    __supernotedialog__/_supernotebox_.h \
    __supernotedialog__/_supernotebox__ui_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superplot__/_superplot_.h \
    __superplot__/qcustomplot.h \
    __supertab__/_supertab_.h \
    __supertab__/_supertab__ui_.h \
    __supertabwidget__/_supertabwidget_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitle__ui_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h \
    __superwindow__/_superwindow__ui_.h \
    _wasapibox_.h \
    _wasapibox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __formatdialog__/_formatbox_.ui \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __module__/_modulec_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __formatdialog__/_ui2h_.bat \
    __module__/_ui2h_.bat \
    __superfftw__/__x64__/libfftw3-3.dll \
    __superfftw__/__x64__/libfftw3-3.lib \
    __superfftw__/__x64__/libfftw3f-3.dll \
    __superfftw__/__x64__/libfftw3f-3.lib \
    __superfftw__/__x64__/libfftw3l-3.dll \
    __superfftw__/__x64__/libfftw3l-3.lib \
    __superfftw__/__x86__/libfftw3-3.dll \
    __superfftw__/__x86__/libfftw3-3.lib \
    __superfftw__/__x86__/libfftw3f-3.dll \
    __superfftw__/__x86__/libfftw3f-3.lib \
    __superfftw__/__x86__/libfftw3l-3.dll \
    __superfftw__/__x86__/libfftw3l-3.lib \
    __superfiledialog__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _wasapibox_.html \
    _wasapibox_.pdf

LIBS += "C:\repos\SuperTools-Source\__plugins__\__device__\_wasapibox_\__superfftw__\__x64__\libfftw3-3.lib"

RESOURCES += \
    _wasapibox_.qrc
