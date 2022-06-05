#ifndef _SUPERWINDOW__H
#define _SUPERWINDOW__H
#define _SUPERWINDOW__EXPORT Q_DECL_EXPORT

#include "__supercore__/_supercore_.h"
#include "_supertitle_.h"
#include <QScreen>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {class SuperWindowui;}
QT_END_NAMESPACE

class _SUPERWINDOW__EXPORT SuperWindow : public QWidget
{
    Q_OBJECT

public:

    SuperCore *Core                 = nullptr;
    QColor Backgroundcolor          = {16,81,142};
    QColor Fontcolor                = Qt::black;
    QColor Concolor                 = {239,174,113};

public:

    SuperWindow(
        QWidget *parent = nullptr);

    ~SuperWindow();

public slots:

    void setTitle(
        QString titletext);

    void disableMaxisize();

    void enableMaxisize();

    void enableClose();

    void disableClose();

    void addIconFunction();

    void addThemeFunction();

    void addFrameFunction();

    void addResizeFunction();

    void themeMenuInit();

    void addMenu(
        QMenu *menu,
        QString titlename,
        bool addseparator);

    void addAction(
        QAction *action);

    void addThemesAction(
        QAction *action);

    void show();

    void moveCenter(
        QWidget *widget);

    void setColor(
        QColor color);

    void close();

    void setWidget(
            QWidget *widget);

    QWidget* widget();

protected:

    void keyPressEvent(
        QKeyEvent *event);

    void mousePressEvent(
        QMouseEvent *event);

    void mouseMoveEvent(
        QMouseEvent *event);

    void mouseReleaseEvent(
        QMouseEvent *event);

    void closeEvent(
        QCloseEvent *event);

    bool eventFilter(
        QObject *object,
        QEvent *event);

private:

    Ui::SuperWindowui *ui               = nullptr;
    SuperTitle *Title                   = nullptr;
    QLayout *Pluginlayout               = nullptr;
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
    QWidget *Widget                     = nullptr;
    int Showinterval                    = 10;

private slots:

    void init();

    void objectInit();

    void colorInit();

    void parameterInit();

    void pointerInit();

    void addMaxisizeButton(
        QString colorstyle);

    void addCloseButton(
        QString colorstyle);

    void addMinisizeButton(
        QString colorstyle);

    void mouseEnter(
        bool mouseontitle);

    void changeShowStatus();

    void changeMaxicon();

    void minimized();

    void enableThemesApi(
        bool boola,
        bool boolb,
        bool boolc,
        bool boold,
        QString theme);

    void themeActionInit();

    void themeConnectInit();

    void callMenu();

    void setFrameTheme();

    void setOriginalTheme();

    void selectColorTheme();

    void setColorTheme();

    void setHeartOfIronTheme();

    void setGoerTekTheme();

    void setWidgetTheme();

    void updateSvgFile();

    void setDeactiveTheme();

    Qt::CursorShape calMousePosition(
        QMouseEvent *event);

    void resizeByCursor();

signals:

    void signalWa();

    void signalWb();

    void signalWc();

    void signalWd();

    void signalWe(
        QWidget *widget);

};

#endif // _SUPERWINDOW__H
