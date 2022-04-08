QT += widgets \
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _SERIALPORTBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_modulea_.cpp \
    __module__/_moduleb_.cpp \
    __supercore__/_supercore_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __supersender__/_supersender_.cpp \
    __superserial__/_superserial_.cpp \
    __supertab__/_supertab_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _serialportbox_.cpp

HEADERS += \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
    __module__/_moduleb_.h \
    __module__/_moduleb__ui_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supernotedialog__/_supernotebox_.h \
    __supernotedialog__/_supernotebox__ui_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supersender__/_supersender_.h \
    __supersender__/_supersender__ui_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    __supertab__/_supertab__ui_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitle__ui_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h \
    __superwindow__/_superwindow__ui_.h \
    _serialportbox_.h \
    _serialportbox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __supersender__/_supersender_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __module__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __supersender__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _serialportbox_.html \
    _serialportbox_.pdf

RESOURCES += \
    _serialportbox_.qrc
