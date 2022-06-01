QT += widgets\
      core5compat

CONFIG += c++17
#DEFINES += WINDOWS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __superframe__/_superframe_.cpp \
    __superinit__/_superinit_.cpp \
    __supermain__/_supermain_.cpp \
    __supertray__/_supertray_.cpp \
    _supertools_.cpp

HEADERS += \
    __supercolordialog__/_supercolordialog_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superframe__/_superframe_.h \
    __superinit__/_superinit_.h \
    __supermain__/_supermain_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertabwidget__/_supertabwidget_.h \
    __supertray__/_supertray_.h \
    __superwindow__/_superwindow_.h

FORMS += \
    __superinit__/_superinit_.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _supertools_.qrc

DISTFILES += \
    _supertools_.html \
    _supertools_.ico \
    _supertools_.pdf \
    _supertools_.rc

RC_FILE = _supertools_.rc

win32{
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix{
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}
