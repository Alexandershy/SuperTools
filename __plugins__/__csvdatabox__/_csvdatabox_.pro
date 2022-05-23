QT += widgets\
      charts

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _CSVDATABOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __datadialog__/_csvdatadialog_.cpp \
    __datadialog__/_csvdatadialogui_.cpp \
    __infodialog__/_csvdatainfodialog_.cpp \
    __infodialog__/_csvdatainfodialogui_.cpp \
    __itemdialog__/_csvdataitemdialog_.cpp \
    __itemdialog__/_csvdataitemdialogui_.cpp \
    __module__/_csvdatamodulea_.cpp \
    _csvdatabox_.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __datadialog__/_csvdatadialogui_.ui \
    __infodialog__/_csvdatainfodialogui_.ui \
    __itemdialog__/_csvdataitemdialogui_.ui \
    __module__/_csvdatamodulea_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __superfilemanager__/_superfilemanagerui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __superprogressbardialog__/_superprogressbardialogui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

DISTFILES += \
    _csvdatabox_.html \
    _csvdatabox_.pdf

RESOURCES += \
    _csvdatabox_.qrc

HEADERS += \
    __datadialog__/_csvdatadialog_.h \
    __datadialog__/_csvdatadialogui_.h \
    __infodialog__/_csvdatainfodialog_.h \
    __infodialog__/_csvdatainfodialogui_.h \
    __itemdialog__/_csvdataitemdialog_.h \
    __itemdialog__/_csvdataitemdialogui_.h \
    __module__/_csvdatamodulea_.h \
    __superchartview__/_superchartview_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfilemanager__/_superfilemanager_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _csvdatabox_.h

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
