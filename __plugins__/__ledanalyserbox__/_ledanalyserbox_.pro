QT += widgets\
      serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _LEDANALYSERBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_ledanalysermodulea_.cpp \
    __module__/_ledanalysermoduleb_.cpp \
    _ledanalyserbox_.cpp

HEADERS += \
    __module__/_ledanalysermodulea_.h \
    __module__/_ledanalysermoduleb_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    _ledanalyserbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_ledanalysermodulea_.ui \
    __module__/_ledanalysermoduleb_.ui \
    __supertab__/_supertabui_.ui

DISTFILES += \
    _ledanalyserbox_.html \
    _ledanalyserbox_.pdf

RESOURCES += \
    _ledanalyserbox_.qrc

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
