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
    __chatinfodialog__/_chatinfobox_.cpp \
    __chatinfodialog__/_chatinfodialog_.cpp \
    __chatsharedialog__/_chatsharebox_.cpp \
    __chatsharedialog__/_chatsharedialog_.cpp \
    __chatter__/_chatter_.cpp \
    __chatuser__/_chatuser_.cpp \
    __module__/_modulea_.cpp \
    __module__/_moduleb_.cpp \
    __module__/_modulec_.cpp \
    __module__/_moduled_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __supernetwork__/_supernetwork_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __superprogressbardialog__/_superprogressbarbox_.cpp \
    __superprogressbardialog__/_superprogressbardialog_.cpp \
    __supertab__/_supertab_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _chatbox_.cpp

HEADERS += \
    __chatbubble__/_chatbubble_.h \
    __chatinfodialog__/_chatinfobox_.h \
    __chatinfodialog__/_chatinfobox__ui_.h \
    __chatinfodialog__/_chatinfodialog_.h \
    __chatsharedialog__/_chatsharebox_.h \
    __chatsharedialog__/_chatsharebox__ui_.h \
    __chatsharedialog__/_chatsharedialog_.h \
    __chatter__/_chatter_.h \
    __chatter__/_chatter__ui_.h \
    __chatuser__/_chatuser_.h \
    __module__/_modulea_.h \
    __module__/_modulea__ui_.h \
    __module__/_moduleb_.h \
    __module__/_moduleb__ui_.h \
    __module__/_modulec_.h \
    __module__/_modulec__ui_.h \
    __module__/_moduled_.h \
    __module__/_moduled__ui_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __supergroupbox__/_supergroupbox_.h \
    __supernetwork__/_supernetwork_.h \
    __supernotedialog__/_supernotebox_.h \
    __supernotedialog__/_supernotebox__ui_.h \
    __supernotedialog__/_supernotedialog_.h \
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
    _chatbox_.h \
    _chatbox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    __chatinfodialog__/_chatinfobox_.ui \
    __chatsharedialog__/_chatsharebox_.ui \
    __chatter__/_chatter_.ui \
    __module__/_modulea_.ui \
    __module__/_moduleb_.ui \
    __module__/_modulec_.ui \
    __module__/_moduled_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __superprogressbardialog__/_superprogressbarbox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    .gitignore \
    __chatinfodialog__/_ui2h_.bat \
    __chatsharedialog__/_ui2h_.bat \
    __chatter__/_ui2h_.bat \
    __module__/_ui2h_.bat \
    __superfiledialog__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __superprogressbardialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _chatbox_.html \
    _chatbox_.pdf

RESOURCES += \
    _chatbox_.qrc
