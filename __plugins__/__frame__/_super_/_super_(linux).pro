QT += widgets

TEMPLATE = lib
DEFINES += _SUPER__LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    __supercolordialog__/_supercolorbox_.cpp \
    __supercolordialog__/_supercolordialog_.cpp \
    __supercolordialog__/_superpainter_.cpp \
    __supercore__/_supercore_.cpp \
    __superfiledialog__/_superfilebox_.cpp \
    __superfiledialog__/_superfiledialog_.cpp \
    __superfiledialog__/_superfilesystemmodel_.cpp \
    __superinit__/_superinit_.cpp \
    __supermain__/_supermain_.cpp \
    __supernotedialog__/_supernotebox_.cpp \
    __supernotedialog__/_supernotedialog_.cpp \
    __supertabwidget__/_supertabwidget_.cpp \
    __supertray__/_supertray_.cpp \
    __superwindow__/_supertitle_.cpp \
    __superwindow__/_supertitlebutton_.cpp \
    __superwindow__/_superwindow_.cpp \
    _super_.cpp

HEADERS += \
    __supercolordialog__/_supercolorbox_.h \
    __supercolordialog__/_supercolorbox__ui_.h \
    __supercolordialog__/_supercolordialog_.h \
    __supercolordialog__/_superpainter_.h \
    __supercore__/_supercore_.h \
    __superfiledialog__/_superfilebox_.h \
    __superfiledialog__/_superfilebox__ui_.h \
    __superfiledialog__/_superfiledialog_.h \
    __superfiledialog__/_superfilesystemmodel_.h \
    __superinit__/_superinit_.h \
    __superinit__/_superinit__ui_.h \
    __supermain__/_supermain_.h \
    __supernotedialog__/_supernotebox_.h \
    __supernotedialog__/_supernotebox__ui_.h \
    __supernotedialog__/_supernotedialog_.h \
    __supertabwidget__/_supertabwidget_.h \
    __supertray__/_supertray_.h \
    __superwindow__/_supertitle_.h \
    __superwindow__/_supertitle__ui_.h \
    __superwindow__/_supertitlebutton_.h \
    __superwindow__/_superwindow_.h \
    __superwindow__/_superwindow__ui_.h \
    _super_.h \
    _super__global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    _super_.qrc

FORMS += \
    __supercolordialog__/_supercolorbox_.ui \
    __superfiledialog__/_superfilebox_.ui \
    __superinit__/_superinit_.ui \
    __supernotedialog__/_supernotebox_.ui \
    __superwindow__/_supertitle_.ui \
    __superwindow__/_superwindow_.ui

DISTFILES += \
    __supercolordialog__/_ui2h_.bat \
    __superfiledialog__/_ui2h_.bat \
    __supericon__/_appraiserchart_.svg \
    __supericon__/_backward_.svg \
    __supericon__/_bclose_.svg \
    __supericon__/_blank_.png \
    __supericon__/_bmaximize_.svg \
    __supericon__/_bminimize_.svg \
    __supericon__/_brestoredown_.svg \
    __supericon__/_brush_.svg \
    __supericon__/_calfft_.svg \
    __supericon__/_center_.svg \
    __supericon__/_changelanguage_.svg \
    __supericon__/_changemode_.svg \
    __supericon__/_check_.svg \
    __supericon__/_close_.svg \
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
    __supericon__/_maximize_.svg \
    __supericon__/_maxrefreshrate_.svg \
    __supericon__/_menu_.svg \
    __supericon__/_midrefreshrate_.svg \
    __supericon__/_minimize_.svg \
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
    __supericon__/_restoredown_.svg \
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
    __superinit__/_ui2h_.bat \
    __supernotedialog__/_ui2h_.bat \
    __superwindow__/_ui2h_.bat \
    _super_.html \
    _super_.pdf \
    _superapi_.html \
    _superapi_.pdf
