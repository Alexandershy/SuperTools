QT += widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib

DEFINES += _GAMEBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __hitbricks__/_hitbricksbox_.cpp \
    __hitbricks__/_hitbricksdialog_.cpp \
    __hitbricks__/_hitbricksscene_.cpp \
    __module__/_modulea_.cpp \
    __object__/_littleball_.cpp \
    __object__/_littlebrick_.cpp \
    __object__/_littleskate_.cpp \
    __object__/_littletext_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __superfilemanager__/_superfilemanager_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __supertab__/_supertab_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _gamebox_.cpp

HEADERS += \
    __hitbricks__/_hitbricksbox_.h \
    __hitbricks__/_hitbricksbox__ui_.h \
    __hitbricks__/_hitbricksdialog_.h \
    __hitbricks__/_hitbricksscene_.h \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
    __object__/_littleball_.h \
    __object__/_littlebrick_.h \
    __object__/_littleskate_.h \
    __object__/_littletext_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superfilemanager__/_superfilemanager__ui_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supernotedialog__/_supernotebox_.h \
    __supernotedialog__/_supernotebox__ui_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertab__/_supertab_.h \
    __supertab__/_supertab__ui_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitle__ui_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h \
    __superwindow__/_superwindow__ui_.h \
    _gamebox_.h \
    _gamebox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __hitbricks__/_hitbricksbox_.ui \
    __module__/_modulea_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __superfilemanager__/_superfilemanager_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __hitbricks__/_ui2h_.bat \
    __module__/_ui2h_.bat \
    __superfiledialog__/_ui2h_.bat \
    __superfilemanager__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _gamebox_.html \
    _gamebox_.pdf

RESOURCES += \
    _gamebox_.qrc
