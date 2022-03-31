QT += widgets

TEMPLATE = lib
DEFINES += _RESUPER__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __supercore__/_supercore_.cpp \
    _resuper_.cpp

HEADERS += \
    __supercore__/_supercore_.h \
    _resuper_.h \
    _resuper__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \

FORMS += \

RESOURCES += \
