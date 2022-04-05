#ifndef _SUPERWINDOW__H
#define _SUPERWINDOW__H

#include "_supertitle_.h"
#include "_superwindow__ui_.h"
#include "__supercore__/_supercore_.h"
//#include <X11/Xlib.h>
#include <QScreen>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {class SuperWindow;}
QT_END_NAMESPACE

class SuperWindow : public QWidget
{
    Q_OBJECT

public:

    SuperCore *SuperC               = nullptr;
    QLayout *Pluginlayout           = nullptr;
    QColor Backgroundcolor          = {16,81,142};
    QColor Fontcolor                = Qt::black;
    QColor Concolor                 = {239,174,113};

public:

    SuperWindow(
        QWidget *parent = nullptr);

    ~SuperWindow();

public slots:

    void Settitle(
        QString titletext);

    void Disablemaxisize();

    void Enablemaxisize();

    void Enableclose();

    void Disableclose();

    void Addiconfunction();

    void Addthemefunction();

    void Addframefunction();

    void Addresizefunction();

    void Thememenuinit();

    void Addmenu(
        QMenu *menu,
        QString titlename,
        bool addseparator);

    void Addaction(
        QAction *action);

    void Addthemesaction(
        QAction *action);

    void Show();

    void Movecenter(
        QWidget *widget);

    void Setcolor(
        QColor color);

protected:

    void mousePressEvent(
        QMouseEvent *event);

    void mouseMoveEvent(
        QMouseEvent *event);

    void mouseReleaseEvent(
        QMouseEvent *event);

    bool eventFilter(
        QObject *object,
        QEvent *event);

private:

    Ui::SuperWindow *ui                 = nullptr;
    SuperTitle *Title                   = nullptr;
    bool Mouseontitle                   = false;
    bool Enablemaxbutton                = true;
    bool Enableclosebutton              = true;
    bool Themeenable                    = false;
    bool Functionenable                 = false;
    bool Pressed                        = false;
    bool Showtimes                      = false;
    QString Activatestatus              = "w";
    int Border                          = 10;
    QPointF Point                       = {0,0};
    QRect Geometry                      = {0,0,0,0};
    QRect Normalgeometry                = {0,0,0,0};
    QString Strrgbbackgroundcolor       = "";
    QString Strrgbfontcolor             = "";
    QString Strrgbconcolor              = "";
    QString Localtitlepath              = "./__depycache__/__cache__/__picture__/_localtitle_.png";
    QString Backgroundcolorpath         = "./__depycache__/__cache__/__ini__/_backgroundcolor_.ini";
    QString Fontcolorpath               = "./__depycache__/__cache__/__ini__/_fontcolor_.ini";
    QString Themepath                   = "./__depycache__/__cache__/__ini__/_theme_.ini";
    QVector<QAction*> Themevector       = {};
    QMenu *Supermenu                    = nullptr;
    QMenu *Themes                       = nullptr;
    QAction *Actionoriginal             = nullptr;
    QAction *Actioncolor                = nullptr;
    QAction *Actionheartofiron          = nullptr;
    QAction *Actiongoertek              = nullptr;
    QTimer *Timer                       = nullptr;
    int Showinterval                    = 10;

private slots:

    void Init();

    void Objectinit();

    void Colorinit();

    void Parameterinit();

    void Pointerinit();

    void Addmaxisizebutton(
        QString colorstyle);

    void Addclosebutton(
        QString colorstyle);

    void Addminisizebutton(
        QString colorstyle);

    void Mouseenter(
        bool mouseontitle);

    void Changeshowstatus();

    void Changemaxicon();

    void Minimized();

    void Enablethemesapi(
        bool boola,
        bool boolb,
        bool boolc,
        bool boold,
        QString theme);

    void Themeactioninit();

    void Themeconnectinit();

    void Callmenu();

    void Setframetheme();

    void Setoriginaltheme();

    void Selectcolortheme();

    void Setcolortheme();

    void Setheartofirontheme();

    void Setgoertektheme();

    void Setwidgettheme();

    void Updatesvgfile();

    void Setdeactivetheme();

    Qt::CursorShape Calmouseposition(
        QMouseEvent *event);

    void Resizebycursor();

    void Close();

signals:

    void Signalwa();

    void Signalwb();

    void Signalwc();

    void Signalwd();

};

#endif // _SUPERWINDOW__H
