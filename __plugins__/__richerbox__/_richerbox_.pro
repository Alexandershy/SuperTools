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
    __datadialog__/_databox_.cpp \
    __datadialog__/_datadialog_.cpp \
    __supercolordialog__/_supercolorbox_.cpp \
    __supercolordialog__/_supercolordialog_.cpp \
    __supercolordialog__/_superpainter_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __superfilemanager__/_superfilemanager_.cpp \
    __superfinddialog__/_superfindbox_.cpp \
    __superfinddialog__/_superfinddialog_.cpp \
    __superfontdialog__/_superfontbox_.cpp \
    __superfontdialog__/_superfontdialog_.cpp \
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
    _richerbox_.cpp

HEADERS += \
    __datadialog__/_databox_.h \
    __datadialog__/_databox__ui_.h \
    __datadialog__/_datadialog_.h \
    __supercolordialog__/_supercolorbox_.h \
    __supercolordialog__/_supercolorbox__ui_.h \
    __supercolordialog__/_supercolordialog_.h \
    __supercolordialog__/_superpainter_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superfilemanager__/_superfilemanager__ui_.h \
    __superfinddialog__/_superfindbox_.h \
    __superfinddialog__/_superfindbox__ui_.h \
    __superfinddialog__/_superfinddialog_.h \
    __superfontdialog__/_superfontbox_.h \
    __superfontdialog__/_superfontbox__ui_.h \
    __superfontdialog__/_superfontdialog_.h \
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
    _richerbox_.h \
    _richerbox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _richerbox_.qrc

FORMS += \
    __datadialog__/_databox_.ui \
    __supercolordialog__/_supercolorbox_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __superfilemanager__/_superfilemanager_.ui \
    __superfinddialog__/_superfindbox_.ui \
    __superfontdialog__/_superfontbox_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    .gitignore \
    __datadialog__/_ui2h_.bat \
    __supercolordialog__/_ui2h_.bat \
    __superfiledialog__/_ui2h_.bat \
    __superfilemanager__/_ui2h_.bat \
    __superfinddialog__/_ui2h_.bat \
    __superfontdialog__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _richerbox_.html \
    _richerbox_.pdf
