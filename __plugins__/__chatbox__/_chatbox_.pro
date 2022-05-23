QT += widgets\
      network

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _CHATBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __chatbubble__/_chatbubble_.cpp \
    __chatinfodialog__/_chatinfodialog_.cpp \
    __chatinfodialog__/_chatinfodialogui_.cpp \
    __chatsharedialog__/_chatsharedialog_.cpp \
    __chatsharedialog__/_chatsharedialogui_.cpp \
    __chatter__/_chatter_.cpp \
    __chatuser__/_chatuser_.cpp \
    __module__/_chatmodulea_.cpp \
    __module__/_chatmoduleb_.cpp \
    __module__/_chatmodulec_.cpp \
    __module__/_chatmoduled_.cpp \
    _chatbox_.cpp

HEADERS += \
    __chatbubble__/_chatbubble_.h \
    __chatinfodialog__/_chatinfodialog_.h \
    __chatinfodialog__/_chatinfodialogui_.h \
    __chatsharedialog__/_chatsharedialog_.h \
    __chatsharedialog__/_chatsharedialogui_.h \
    __chatter__/_chatter_.h \
    __chatuser__/_chatuser_.h \
    __module__/_chatmodulea_.h \
    __module__/_chatmoduleb_.h \
    __module__/_chatmodulec_.h \
    __module__/_chatmoduled_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __supergroupbox__/_supergroupbox_.h \
    __supernetwork__/_supernetwork_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _chatbox_.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __chatinfodialog__/_chatinfodialogui_.ui \
    __chatsharedialog__/_chatsharedialogui_.ui \
    __chatter__/_chatter_.ui \
    __module__/_chatmodulea_.ui \
    __module__/_chatmoduleb_.ui \
    __module__/_chatmodulec_.ui \
    __module__/_chatmoduled_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __superprogressbardialog__/_superprogressbardialogui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

DISTFILES += \
    _chatbox_.html \
    _chatbox_.pdf

RESOURCES += \
    _chatbox_.qrc

LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
