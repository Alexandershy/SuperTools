QT += widgets\
      multimedia\

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _FSMPEGBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    _fsmpegbox_.html \
    _fsmpegbox_.pdf

RESOURCES += \
    _fsmpegbox_.qrc

FORMS += \
    __audioformatdialog__/_audioformatdialogui_.ui

HEADERS += \
    __audioformatdialog__/_audioformatdialog_.h \
    __audioformatdialog__/_audioformatdialogui_.h \
    __superape__/APETag.h \
    __superape__/All.h \
    __superape__/CharacterHelper.h \
    __superape__/IO.h \
    __superape__/MACDll.h \
    __superape__/MACLib.h \
    __superape__/NoWindows.h \
    __superape__/SmartPtr.h \
    __superape__/Version.h \
    __superape__/WindowsEnvironment.h \
    __supercodec__/_superapedecoder_.h \
    __supercodec__/_superflacdecoder_.h \
    __supercodec__/_supermp3decoder_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superflac__/FLAC/all.h \
    __superflac__/FLAC/assert.h \
    __superflac__/FLAC/callback.h \
    __superflac__/FLAC/export.h \
    __superflac__/FLAC/format.h \
    __superflac__/FLAC/metadata.h \
    __superflac__/FLAC/ordinals.h \
    __superflac__/FLAC/stream_decoder.h \
    __superflac__/FLAC/stream_encoder.h \
    __superflac__/ogg/ogg.h \
    __superflac__/ogg/os_types.h \
    __superflac__/share/alloc.h \
    __superflac__/share/compat.h \
    __superflac__/share/endswap.h \
    __superflac__/share/getopt.h \
    __superflac__/share/grabbag.h \
    __superflac__/share/grabbag/cuesheet.h \
    __superflac__/share/grabbag/file.h \
    __superflac__/share/grabbag/picture.h \
    __superflac__/share/grabbag/replaygain.h \
    __superflac__/share/grabbag/seektable.h \
    __superflac__/share/macros.h \
    __superflac__/share/msvc2005_int.h \
    __superflac__/share/private.h \
    __superflac__/share/replaygain_analysis.h \
    __superflac__/share/replaygain_synthesis.h \
    __superflac__/share/safe_str.h \
    __superflac__/share/utf8.h \
    __superflac__/share/win_utf8_io.h \
    __superflac__/share/windows_unicode_filenames.h \
    __supergroupbox__/_supergroupbox_.h \
    __superlogger__/_superlogger_.h \
    __supermp3__/fmt123.h \
    __supermp3__/mpg123.h \
    __supermultimedia__/_supermultimedia_.h \
    __supernotedialog__/_supernotedialog_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __supertab__/_supertab_.h \
    __superwindow__/_superwindow_.h \
    _fsmpegbox_.h

SOURCES += \
    __audioformatdialog__/_audioformatdialog_.cpp \
    __audioformatdialog__/_audioformatdialogui_.cpp \
    _fsmpegbox_.cpp

win32{
    LIBS += "C:\repos\SuperTools-Source\__api__\__superflac__\__windows__\flac.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__superape__\__windows__\MACDll.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__supermp3__\__windows__\libmpg123-0.lib"
    LIBS += "C:\repos\SuperTools-Build\build-_superapi_-Desktop_Qt_6_3_0_MSVC2019_64bit\release\_superapi_.lib"
}
unix {
    QMAKE_LFLAGS += -Wl,-rpath=./
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superape__/__linux__/ -lMAC
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__superflac__/__linux__/ -lFLAC
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Source/__api__/__supermp3__/__linux__/ -lmpg123
    LIBS += -L/home/alexandershy/Documents/repos/SuperTools-Build/build-_superapi_-Desktop_Qt_6_3_0_GCC_64bit/release/ -l_superapi_
}


