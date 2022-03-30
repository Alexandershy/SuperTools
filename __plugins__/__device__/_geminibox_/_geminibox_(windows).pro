QT += widgets\
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _GEMINIBOX__LIBRARY

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
    __superserial__/_superserial_.cpp \
    __supertab__/_supertab_.cpp \
    _geminibox_.cpp

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
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    __supertab__/_supertab__ui_.h \
    _geminibox_.h \
    _geminibox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __supertab__/_supertab_.ui

DISTFILES += \
    __module__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    _geminibox_.html \
    _geminibox_.pdf

RESOURCES += \
    _geminibox_.qrc
