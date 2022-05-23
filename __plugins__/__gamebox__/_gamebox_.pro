QT += widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib

DEFINES += _GAMEBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __hitbricks__/_hitbricksdialog_.cpp \
    __hitbricks__/_hitbricksdialogui_.cpp \
    __hitbricks__/_hitbricksscene_.cpp \
    __module__/_gamemodulea_.cpp \
    __object__/_littleball_.cpp \
    __object__/_littlebrick_.cpp \
    __object__/_littleskate_.cpp \
    __object__/_littletext_.cpp \
    _gamebox_.cpp

HEADERS += \
    __hitbricks__/_hitbricksdialog_.h \
    __hitbricks__/_hitbricksdialogui_.h \
    __hitbricks__/_hitbricksscene_.h \
    __module__/_gamemodulea_.h \
    __object__/_littleball_.h \
    __object__/_littlebrick_.h \
    __object__/_littleskate_.h \
    __object__/_littletext_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfilemanager__/_superfilemanager_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _gamebox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __hitbricks__/_hitbricksdialogui_.ui \
    __module__/_gamemodulea_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __superfilemanager__/_superfilemanagerui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

DISTFILES += \
    _gamebox_.html \
    _gamebox_.pdf

RESOURCES += \
    _gamebox_.qrc

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
