QT += widgets\
      multimedia

greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _FSMPEGBOX__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __audioformatdialog__/_audioformatbox_.cpp \
    __audioformatdialog__/_audioformatdialog_.cpp \
    __supercodec__/_apedecoder_.cpp \
    __supercodec__/_flacdecoder_.cpp \
    __supercodec__/_mp3decoder_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __superfilemanager__/_superfilemanager_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supermultimedia__/_supermultimedia_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __superprogressbardialog__/_superprogressbarbox_.cpp \
    __superprogressbardialog__/_superprogressbardialog_.cpp \
    __supertab__/_supertab_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _fsmpegbox_.cpp

HEADERS += \
    __audioformatdialog__/_audioformatbox_.h \
    __audioformatdialog__/_audioformatbox__ui.h \
    __audioformatdialog__/_audioformatdialog_.h \
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
    __supercodec__/_apedecoder_.h \
    __supercodec__/_flacdecoder_.h \
    __supercodec__/_mp3decoder_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superfilemanager__/_superfilemanager__ui_.h \
    __superflac__/FLAC/all.h \
    __superflac__/FLAC/assert.h \
    __superflac__/FLAC/callback.h \
    __superflac__/FLAC/export.h \
    __superflac__/FLAC/format.h \
    __superflac__/FLAC/metadata.h \
    __superflac__/FLAC/ordinals.h \
    __superflac__/FLAC/stream_decoder.h \
    __superflac__/FLAC/stream_encoder.h \
    __superflac__/ogg/config_types.h.in \
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
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supermp3__/fmt123.h \
    __supermp3__/mpg123.h \
    __supermultimedia__/_supermultimedia_.h \
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
    _fsmpegbox_.h \
    _fsmpegbox__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    __audioformatdialog__/_ui2h_.bat \
    __superape__/__x64__/MACDll.dll \
    __superape__/__x64__/MACDll.lib \
    __superape__/__x86__/MACDll.dll \
    __superape__/__x86__/MACDll.lib \
    __superfiledialog__/_ui2h_.bat \
    __superfilemanager__/_ui2h_.bat \
    __superflac__/__x64__/libFLAC_dynamic.dll \
    __superflac__/__x64__/libFLAC_dynamic.lib \
    __superflac__/__x86__/libFLAC_dynamic.dll \
    __superflac__/__x86__/libFLAC_dynamic.lib \
    __supermp3__/__x64__/libmpg123-0.dll \
    __supermp3__/__x64__/libmpg123-0.lib \
    __supermp3__/__x86__/libmpg123-0.dll \
    __supermp3__/__x86__/libmpg123-0.lib \
    __supernotedialog__/_ui2h_.bat \
    __superprogressbardialog__/_ui2h_.bat \
    __supertab__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _fsmpegbox_.html \
    _fsmpegbox_.pdf

RESOURCES += \
    _fsmpegbox_.qrc

FORMS += \
    __audioformatdialog__/_audioformatbox_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __superfilemanager__/_superfilemanager_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __superprogressbardialog__/_superprogressbarbox_.ui \
    __supertab__/_supertab_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

LIBS += "C:\repos\SuperTools-Source\__plugins__\__device__\_fsmpegbox_\__superflac__\__x64__\libFLAC_dynamic.lib"
LIBS += "C:\repos\SuperTools-Source\__plugins__\__device__\_fsmpegbox_\__superape__\__x64__\MACDll.lib"
LIBS += "C:\repos\SuperTools-Source\__plugins__\__device__\_fsmpegbox_\__supermp3__\__x64__\libmpg123-0.lib"
