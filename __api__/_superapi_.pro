QT += serialport\
      multimedia\
      network\
      charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TEMPLATE = lib
DEFINES += _SUPERAPI__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __superchartview__/_superchartview_.cpp \
    __supercodec__/_superapedecoder_.cpp \
    __supercodec__/_superflacdecoder_.cpp \
    __supercodec__/_supermp3decoder_.cpp \
    __supercolordialog__/_supercolordialog_.cpp \
    __supercolordialog__/_supercolordialogui_.cpp \
    __supercolordialog__/_superpainter_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfiledialogui_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __superfilemanager__/_superfilemanager_.cpp \
    __superfinddialog__/_superfinddialog_.cpp \
    __superfinddialog__/_superfinddialogui_.cpp \
    __superfontdialog__/_superfontdialog_.cpp \
    __superfontdialog__/_superfontdialogui_.cpp \
    __supergroupbox__/_supergroupbox_.cpp \
    __superhook__/_superhook_.cpp \
    __superlogger__/_superlineedit_.cpp \
    __superlogger__/_superlogger_.cpp \
    __superlogger__/_supertextbrowser_.cpp \
    __supermultimedia__/_supermultimedia_.cpp \
    __supernetwork__/_superhttp_.cpp \
    __supernetwork__/_supernetwork_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __supernotedialog__/_supernotedialogui_.cpp \
    __superprogressbardialog__/_superprogressbardialog_.cpp \
    __superprogressbardialog__/_superprogressbardialogui_.cpp \
    __supersender__/_supersender_.cpp \
    __superserial__/_superserial_.cpp \
    __supertab__/_supertab_.cpp \
    __supertabwidget__/_supertabwidget_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp

HEADERS += \
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
    __superchartview__/_superchartview_.h \
    __supercodec__/_superapedecoder_.h \
    __supercodec__/_superflacdecoder_.h \
    __supercodec__/_supermp3decoder_.h \
    __supercolordialog__/_supercolordialog_.h \
    __supercolordialog__/_supercolordialogui_.h \
    __supercolordialog__/_superpainter_.h \
    __supercore__/_supercore_.h \
    __superfftw__/fftw3.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfiledialogui_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __superfilemanager__/_superfilemanager_.h \
    __superfinddialog__/_superfinddialog_.h \
    __superfinddialog__/_superfinddialogui_.h \
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
    __superfontdialog__/_superfontdialog_.h \
    __superfontdialog__/_superfontdialogui_.h \
    __supergroupbox__/_supergroupbox_.h \
    __superhook__/_superhook_.h \
    __superlogger__/_superlineedit_.h \
    __superlogger__/_superlogger_.h \
    __superlogger__/_supertextbrowser_.h \
    __supermp3__/fmt123.h \
    __supermp3__/mpg123.h \
    __supermultimedia__/_supermultimedia_.h \
    __supernetwork__/_superhttp_.h \
    __supernetwork__/_supernetwork_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supernotedialog__/_supernotedialogui_.h \
    __superprogressbardialog__/_superprogressbardialog_.h \
    __superprogressbardialog__/_superprogressbardialogui_.h \
    __supersender__/_supersender_.h \
    __superserial__/_superserial_.h \
    __supertab__/_supertab_.h \
    __supertabwidget__/_supertabwidget_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h

RESOURCES += _superapi_.qrc

FORMS += \
    __supercolordialog__/_supercolordialogui_.ui \
    __superfiledialog__/_superfiledialogui_.ui \
    __superfilemanager__/_superfilemanagerui_.ui \
    __superfinddialog__/_superfinddialogui_.ui \
    __superfontdialog__/_superfontdialogui_.ui \
    __supernotedialog__/_supernotedialogui_.ui \
    __superprogressbardialog__/_superprogressbardialogui_.ui \
    __supersender__/_supersenderui_.ui \
    __supertab__/_supertabui_.ui \
    __superwindow__/_supertitleui_.ui \
    __superwindow__/_superwindowui_.ui

DISTFILES += \
    __superape__/__windows__/MACDll.dll \
    __superape__/__windows__/MACDll.lib \
    __superfftw__/__windows__/fftw3.dll \
    __superfftw__/__windows__/fftw3.lib \
    __superflac__/__windows__/flac.dll \
    __superflac__/__windows__/flac.lib \
    __supericon__/_appraiserchart_.svg \
    __supericon__/_backward_.svg \
    __supericon__/_bclose_.svg \
    __supericon__/_blank_.png \
    __supericon__/_bmaximize_.svg \
    __supericon__/_bminimize_.svg \
    __supericon__/_brestoredown_.svg \
    __supericon__/_brush_.svg \
    __supericon__/_center_.svg \
    __supericon__/_changelanguage_.svg \
    __supericon__/_changemode_.svg \
    __supericon__/_check_.svg \
    __supericon__/_color_.png \
    __supericon__/_colortitle_.png \
    __supericon__/_computermanager_.png \
    __supericon__/_config_.svg \
    __supericon__/_delete2_.svg \
    __supericon__/_delete_.svg \
    __supericon__/_doublelimitcpk_.svg \
    __supericon__/_download_.svg \
    __supericon__/_drag_.svg \
    __supericon__/_edit_.svg \
    __supericon__/_fexitinductionmode_.png \
    __supericon__/_find2_.svg \
    __supericon__/_find_.svg \
    __supericon__/_finductionmode_.png \
    __supericon__/_frs232comportmode_.png \
    __supericon__/_fs361415r_.png \
    __supericon__/_fusbcomportmode_.png \
    __supericon__/_fusbkeyboardmode_.png \
    __supericon__/_getformat_.svg \
    __supericon__/_goertek_.png \
    __supericon__/_goertektitle_.png \
    __supericon__/_heartofiron_.ico \
    __supericon__/_heartofirontitle_.png \
    __supericon__/_help_.svg \
    __supericon__/_hexitinductionmode_.png \
    __supericon__/_highrefreshrate_.svg \
    __supericon__/_hinductionmode_.png \
    __supericon__/_histogramchart_.svg \
    __supericon__/_honeywell1900_.png \
    __supericon__/_hrs485comportmode1_.png \
    __supericon__/_hrs485comportmode2_.png \
    __supericon__/_husbcomportmode_.png \
    __supericon__/_husbkeyboardmode_.png \
    __supericon__/_info_.svg \
    __supericon__/_initquit_.svg \
    __supericon__/_insert_.svg \
    __supericon__/_instructions_.svg \
    __supericon__/_interactionchart_.svg \
    __supericon__/_justify_.svg \
    __supericon__/_last_.svg \
    __supericon__/_left_.svg \
    __supericon__/_linechart_.svg \
    __supericon__/_listloop_.svg \
    __supericon__/_load_.svg \
    __supericon__/_loadpathloss_.svg \
    __supericon__/_localtitle_.png \
    __supericon__/_location_.svg \
    __supericon__/_lock_.svg \
    __supericon__/_lowerlimitcpk_.svg \
    __supericon__/_lowrefreshrate_.svg \
    __supericon__/_maxrefreshrate_.svg \
    __supericon__/_menu_.svg \
    __supericon__/_midrefreshrate_.svg \
    __supericon__/_network_.svg \
    __supericon__/_newfolder_.svg \
    __supericon__/_next_.svg \
    __supericon__/_open_.svg \
    __supericon__/_opencachefolder_.svg \
    __supericon__/_openpath_.svg \
    __supericon__/_original_.svg \
    __supericon__/_originaltitle_.png \
    __supericon__/_painter_.svg \
    __supericon__/_palette_.svg \
    __supericon__/_partchart_.svg \
    __supericon__/_peak_.svg \
    __supericon__/_picture_.svg \
    __supericon__/_play_.svg \
    __supericon__/_playing_.svg \
    __supericon__/_plugin_.svg \
    __supericon__/_print_.svg \
    __supericon__/_quit_.svg \
    __supericon__/_random_.svg \
    __supericon__/_rangechart_.svg \
    __supericon__/_regedit_.png \
    __supericon__/_reset_.svg \
    __supericon__/_right_.svg \
    __supericon__/_rms_.svg \
    __supericon__/_save_.svg \
    __supericon__/_saveas_.svg \
    __supericon__/_savepathloss_.svg \
    __supericon__/_scanner_.png \
    __supericon__/_scatterchart_.svg \
    __supericon__/_select_.svg \
    __supericon__/_setting_.svg \
    __supericon__/_singlecycle_.svg \
    __supericon__/_stopplay_.svg \
    __supericon__/_superapi_.svg \
    __supericon__/_supergirl_.png \
    __supericon__/_supertools_.ico \
    __supericon__/_superwizard_.png \
    __supericon__/_suspended_.svg \
    __supericon__/_taskmanager_.png \
    __supericon__/_themes_.svg \
    __supericon__/_toggleleft_.svg \
    __supericon__/_toggleright_.svg \
    __supericon__/_unlock_.svg \
    __supericon__/_upperlimitcpk_.svg \
    __supericon__/_version_.svg \
    __supericon__/_wclose_.svg \
    __supericon__/_wmaximize_.svg \
    __supericon__/_wminimize_.svg \
    __supericon__/_wrestoredown_.svg \
    __supermp3__/__windows__/libmpg123-0.dll \
    __supermp3__/__windows__/libmpg123-0.lib \
    _superapi_.html \
    _superapi_.pdf

win32
{
    LIBS += -luser32
    LIBS += "C:\repos\SuperTools-Source\__api__\__superfftw__\__windows__\fftw3.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__superape__\__windows__\MACDll.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__supermp3__\__windows__\libmpg123-0.lib"
    LIBS += "C:\repos\SuperTools-Source\__api__\__superflac__\__windows__\flac.lib"
}

unix
{

}



