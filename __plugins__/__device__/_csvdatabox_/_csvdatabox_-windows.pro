QT += widgets\
      printsupport

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _CSVDATABOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __datadialog__/_databox_.cpp \
    __datadialog__/_datadialog_.cpp \
    __infodialog__/_infobox_.cpp \
    __infodialog__/_infodialog_.cpp \
    __itemdialog__/_itembox_.cpp \
    __itemdialog__/_itemdialog_.cpp \
    __module__/_modulea_.cpp \
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
    __superplot__/_superplot_.cpp \
    __superplot__/qcustomplot.cpp \
    __superprogressbardialog__/_superprogressbarbox_.cpp \
    __superprogressbardialog__/_superprogressbardialog_.cpp \
    __supertab__/_supertab_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _csvdatabox_.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __datadialog__/_databox_.ui \
    __infodialog__/_infobox_.ui \
    __itemdialog__/_itembox_.ui \
    __module__/_modulea_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __superfilemanager__/_superfilemanager_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __superprogressbardialog__/_superprogressbarbox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __datadialog__/_ui2h_.bat \
    __infodialog__/_ui2h_.bat \
    __itemdialog__/_ui2h_.bat \
    __module__/_ui2h_.bat \
    __superfiledialog__/_ui2h_.bat \
    __superfilemanager__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __superprogressbardialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _csvdatabox_.html \
    _csvdatabox_.pdf

RESOURCES += \
    _csvdatabox_.qrc

HEADERS += \
    __datadialog__/_databox_.h \
    __datadialog__/_databox__ui_.h \
    __datadialog__/_datadialog_.h \
    __infodialog__/_infobox_.h \
    __infodialog__/_infobox__ui_.h \
    __infodialog__/_infodialog_.h \
    __itemdialog__/_itembox_.h \
    __itemdialog__/_itembox__ui_.h \
    __itemdialog__/_itemdialog_.h \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
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
    __superplot__/_superplot_.h \
    __superplot__/qcustomplot.h \
    __superprogressbardialog__/_superprogressbarbox_.h \
    __superprogressbardialog__/_superprogressbarbox__ui_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __supertab__/_supertab_.h \
    __supertab__/_supertab__ui_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitle__ui_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h \
    __superwindow__/_superwindow__ui_.h \
    _csvdatabox_.h \
    _csvdatabox__global.h
