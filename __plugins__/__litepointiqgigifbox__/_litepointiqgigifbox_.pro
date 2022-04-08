QT += widgets\
      printsupport\
      network

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _LITEPOINTIQGIGIFBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __module__/_modulea_.cpp \
    __module__/_moduleb_.cpp \
    __pathlossdialog__/_pathlossbox_.cpp \
    __pathlossdialog__/_pathlossdialog_.cpp \
    __routdialog__/_routbox_.cpp \
    __routdialog__/_routdialog_.cpp \
    __supercore__/_supercore_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supernetwork__/_supernetwork_.cpp \
    __superplot__/_superplot_.cpp \
    __superplot__/qcustomplot.cpp \
    __supertab__/_supertab_.cpp \
    __supertabwidget__/_supertabwidget_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _litepointiqgigifbox_.cpp

HEADERS += \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
    __module__/_moduleb_.h \
    __module__/_moduleb__ui_.h \
    __pathlossdialog__/_pathlossbox_.h \
    __pathlossdialog__/_pathlossbox__ui_.h \
    __pathlossdialog__/_pathlossdialog_.h \
    __routdialog__/_routbox_.h \
    __routdialog__/_routbox__ui_.h \
    __routdialog__/_routdialog_.h \
    __supercore__/_supercore_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supernetwork__/_supernetwork_.h \
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
    _litepointiqgigifbox_.h \
    _litepointiqgigifbox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __pathlossdialog__/_pathlossbox_.ui \
    __routdialog__/_routbox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __module__/_ui2h_.bat \
    __pathlossdialog__/_ui2h_.bat \
    __routdialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _litepointiqgigifbox_.html \
    _litepointiqgigifbox_.pdf

RESOURCES += \
    _litepointiqgigifbox_.qrc
