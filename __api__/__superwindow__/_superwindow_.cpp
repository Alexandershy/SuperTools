#include "_superwindow_.h"
#include "ui__supertitleui_.h"
#include "ui__superwindowui_.h"

SuperWindow::SuperWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SuperWindowui)
{
    ui->setupUi(this);
    init();
    installEventFilter(this);
}

SuperWindow::~SuperWindow()
{
    removeEventFilter(this);
}

void SuperWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
        {
            close();
            break;
        }
    }
}

/*  define key;*/

void SuperWindow::mousePressEvent(QMouseEvent *event)
{
    Point = event->globalPosition();
    Geometry = geometry();
    Pressed = true;
}

/*  record this global pos;*/

void SuperWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(Mouseontitle && Pressed)
    {
        if(isMaximized())
        {
            changeMaxicon();
            move(Point.x() - Normalgeometry.width() / 2,Point.y() - Title->height() / 2);
        }
        int dx = event->globalPosition().x() - Point.x();
        int dy = event->globalPosition().y() - Point.y();
        Point = event->globalPosition();
        move(x() + dx,y() + dy);
    }
    else if(!isMaximized() && !Pressed)
    {
        setCursor(calMousePosition(event));
    }
    else if(!isMaximized() && Pressed)
    {
        resizeByCursor();
    }
}

/*  move to this global pos;*/

void SuperWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Point = event->globalPosition();
    Pressed = false;
}

/*  move to global pos;*/

bool SuperWindow::eventFilter(QObject* object,QEvent *event)
{
    switch (event->type())
    {
        case QEvent::WindowActivate:
        {
            emit signalWa();
            break;
        }
        case QEvent::WindowDeactivate:
        {
            emit signalWc();
            break;
        }
        default:
        {
            break;
        }
    }
    return QWidget::eventFilter(object, event);
}

/*  use event filter accept window activate event and update title style sheet;*/

void SuperWindow::init()
{
    objectInit();
    colorInit();
    parameterInit();
    pointerInit();
}

/*  class init;*/

void SuperWindow::objectInit()
{
    Core = new SuperCore(this);
    Title = new SuperTitle(this);
    Timer = new QTimer(this);
    connect(Title->Minisizebutton,      &QPushButton::clicked,  this,&SuperWindow::minimized);
    connect(Title->Maxisizebutton,      &QPushButton::clicked,  this,&SuperWindow::changeMaxicon);
    connect(Title->Closebutton,         &QPushButton::clicked,  this,&SuperWindow::close);
    connect(Title,                      &SuperTitle::signalSa,  this,&SuperWindow::mouseEnter);
    connect(Title,                      &SuperTitle::signalSb,  this,&SuperWindow::changeMaxicon);
    connect(Title,                      &SuperTitle::signalSc,  this,&SuperWindow::setCursor);
    connect(this,                       &SuperWindow::signalWa, this,&SuperWindow::setWidgetTheme);
    connect(this,                       &SuperWindow::signalWc, this,&SuperWindow::setDeactiveTheme);
    connect(Timer,                      &QTimer::timeout,       this,&SuperWindow::signalWd);
    connect(Timer,                      &QTimer::timeout,       Timer,&QTimer::deleteLater);
}

/*  objectinit;*/

void SuperWindow::colorInit()
{
    QStringList rgbbackgroundcolor = Core->readOnlyFile(Backgroundcolorpath).split(",");
    QStringList rgbfontcolor = Core->readOnlyFile(Fontcolorpath).split(",");
    if(rgbbackgroundcolor.count() >= 3 && rgbfontcolor.count() >= 3)
    {
        Backgroundcolor.setRgb(rgbbackgroundcolor.at(0).toInt(),rgbbackgroundcolor.at(1).toInt(),rgbbackgroundcolor.at(2).toInt());
        Fontcolor.setRgb(rgbfontcolor.at(0).toInt(),rgbfontcolor.at(1).toInt(),rgbfontcolor.at(2).toInt());
        Concolor.setRgb(255 - rgbbackgroundcolor.at(0).toInt(),255 - rgbbackgroundcolor.at(1).toInt(),255 - rgbbackgroundcolor.at(2).toInt());
    }
    Strrgbbackgroundcolor = "rgb(" + Core->rgbColor(&Backgroundcolor) + ")";
    Strrgbfontcolor = "rgb(" + Core->rgbColor(&Fontcolor) + ")";
    Strrgbconcolor = "rgb(" + Core->rgbColor(&Concolor) + ")";
}

/*  if rgb file exist,use color saved,else use default color;*/

void SuperWindow::parameterInit()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    setStyleSheet("QGroupBox{border:1px solid " + Strrgbbackgroundcolor + "}");
    setWindowIcon(QIcon(":/__supericon__/_supertools_.ico"));
    Title->setStyleSheet("QFrame#SuperTitleui{border-image:url(./__depycache__/__cache__/__picture__/_localtitle_.png);background-color:" + Strrgbbackgroundcolor + "}QWidget{color:" + Strrgbfontcolor + "}");
    Title->ui->pushButton_5->setStyleSheet("border-image:url(:/__supericon__/_supertools_.ico);");
    Title->Minisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "minimize_.svg"));
    Title->ui->label_2->setText(objectName());
    ui->Titlelayout->addWidget(Title);
    addMaxisizeButton(Activatestatus);
    addCloseButton(Activatestatus);
}

/*  style init;*/

void SuperWindow::pointerInit()
{
    Pluginlayout = ui->Pluginlayout;
}

/*  public pointer;*/

void SuperWindow::addMaxisizeButton(QString colorstyle)
{
    if(Enablemaxbutton)
    {
        if(isMaximized())
        {
            Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "restoredown_.svg"));
        }
        else
        {
            Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "maximize_.svg"));
        }
    }
}

/*  add maxisize button;*/

void SuperWindow::addCloseButton(QString colorstyle)
{
    if(Enableclosebutton)
    {
        Title->Closebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "close_.svg"));
    }
}

/*  add close button;*/

void SuperWindow::addMinisizeButton(QString colorstyle)
{
    Title->Minisizebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "minimize_.svg"));
}

/*  add minisize button;*/

void SuperWindow::setTitle(QString titletext)
{
    Title->ui->label_2->setText(titletext);
}

/*  set title;*/

void SuperWindow::disableMaxisize()
{
    disconnect(Title,                   &SuperTitle::signalSb,  this,&SuperWindow::changeMaxicon);
    disconnect(Title->Maxisizebutton,   &QPushButton::clicked,  this,&SuperWindow::changeMaxicon);
    Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_blank_.png"));
    Title->Maxisizebutton->setEnabled(false);
    Enablemaxbutton = false;
}

/*  disable maxisize function and button;*/

void SuperWindow::enableMaxisize()
{
    Enablemaxbutton = true;
    connect(Title,                  &SuperTitle::signalSb,this,&SuperWindow::changeMaxicon);
    connect(Title->Maxisizebutton,  &QPushButton::clicked,this,&SuperWindow::changeMaxicon);
    Title->Maxisizebutton->setEnabled(true);
    addMaxisizeButton(Activatestatus);
}

/*  enable maxisize function and button;*/

void SuperWindow::disableClose()
{
    disconnect(Title->Closebutton,&QPushButton::clicked,this,&::SuperWindow::close);
    Title->Closebutton->setIcon(QIcon(":/__supericon__/_blank_.png"));
    Title->Closebutton->setEnabled(false);
    Enableclosebutton = false;
}

/*  disable close function and button;*/

void SuperWindow::enableClose()
{
    Enableclosebutton = true;
    connect(Title->Closebutton,&QPushButton::clicked,this,&SuperWindow::close);
    addCloseButton(Activatestatus);
}

/*  enable maxisize function and button;*/

void SuperWindow::mouseEnter(bool mouseontitle)
{
    Mouseontitle = mouseontitle;
}

/*  title send signal if mouse enter;*/

void SuperWindow::changeShowStatus()
{
    if(isMaximized())
    {
        showNormal();
        setGeometry(Normalgeometry);
    }
    else
    {
        Normalgeometry = geometry();
        showMaximized();
    }
}

/*  change frame status,minimized or maximized;*/

void SuperWindow::changeMaxicon()
{
    if(isMaximized())
    {
        Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "maximize_.svg"));
    }
    else
    {
        Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "restoredown_.svg"));
    }
    changeShowStatus();
}

/*  change button status,minimized or maximized;*/

void SuperWindow::minimized()
{
    showMinimized();
}

/*  min size;*/

void SuperWindow::addThemeFunction()
{
    themeActionInit();
    themeConnectInit();
    setFrameTheme();
}

/*  add theme function;*/

void SuperWindow::themeMenuInit()
{
    Themes = new QMenu(this);
    Themes->setIcon(QIcon(":/__supericon__/_themes_.svg"));
}

/*  enable themes menu interface;*/

void SuperWindow::themeActionInit()
{
    themeMenuInit();
    Actionoriginal = new QAction(QIcon(":/__supericon__/_original_.svg"),"Original",this);
    Actioncolor = new QAction(QIcon(":/__supericon__/_color_.png"),"Color",this);
    Actionheartofiron = new QAction(QIcon(":/__supericon__/_heartofiron_.ico"),"Heartofiron",this);
    Actiongoertek = new QAction(QIcon(":/__supericon__/_goertek_.png"),"Goertek",this);
    Themevector = {Actionoriginal,Actioncolor,Actionheartofiron,Actiongoertek};
    Themes->addAction(Actionoriginal);
    Themes->addAction(Actioncolor);
    Themes->addAction(Actionheartofiron);
    Themes->addAction(Actiongoertek);
}

/*  add action to themes menu interface;*/

void SuperWindow::addIconFunction()
{
    connect(Title->ui->pushButton_5,&QPushButton::clicked,  this,&SuperWindow::callMenu);
}

/*  enable icon function;*/

void SuperWindow::themeConnectInit()
{
    addIconFunction();
    connect(Actionoriginal,         &QAction::triggered,    this,&SuperWindow::setOriginalTheme);
    connect(Actioncolor,            &QAction::triggered,    this,&SuperWindow::selectColorTheme);
    connect(Actionheartofiron,      &QAction::triggered,    this,&SuperWindow::setHeartOfIronTheme);
    connect(Actiongoertek,          &QAction::triggered,    this,&SuperWindow::setGoerTekTheme);
}

/*  enable themes' function;*/

void SuperWindow::callMenu()
{
    if(Functionenable)
    {
        Supermenu->exec(Core->widgetLeftBottomPoint(Title));
    }
    else
    {
        Themes->exec(Core->widgetLeftBottomPoint(Title));
    }
}

/*  exec file menu;*/

void SuperWindow::setFrameTheme()
{
    bool boola = false;
    QString stringindex = Core->readOnlyFile(Themepath);
    stringindex.toInt(&boola);
    if(boola)
    {
        Themevector.at(stringindex.toInt())->setChecked(true);
    }
    else
    {
        stringindex = "0";
        Themevector.at(0)->setChecked(true);
    }
    switch (stringindex.toInt())
    {
        case 0:
        {
            setOriginalTheme();
            break;
        }
        case 1:
        {
            setColorTheme();
            break;
        }
        case 2:
        {
            setHeartOfIronTheme();
            break;
        }
        case 3:
        {
            setGoerTekTheme();
            break;
        }
    }
}

/*  set theme by which action checked;*/

void SuperWindow::enableThemesApi(bool boola,bool boolb,bool boolc,bool boold,QString theme)
{
    Actionoriginal->setCheckable(boola);
    Actioncolor->setCheckable(boolb);
    Actionheartofiron->setCheckable(boolc);
    Actiongoertek->setCheckable(boold);
    Actionoriginal->setChecked(boola);
    Actioncolor->setChecked(boolb);
    Actionheartofiron->setChecked(boolc);
    Actiongoertek->setChecked(boold);
    Core->writeOnlyFile(Themepath,theme);
}

/*  set tabwidget background color;*/

void SuperWindow::setOriginalTheme()
{
    enableThemesApi(true,false,false,false,"0");
    Core->replaceFile(":/__supericon__/_originaltitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(16,81,142);
    Fontcolor.setRgb(255,255,255);
    setWidgetTheme();
}

/*  set original theme;*/

void SuperWindow::selectColorTheme()
{
    emit signalWb();
}

/*  select color theme;*/

void SuperWindow::setColor(QColor color)
{
    Backgroundcolor = color;
    Core->writeOnlyFile(Backgroundcolorpath,Core->rgbColor(&Backgroundcolor));
    if(Backgroundcolor.red() + Backgroundcolor.green() + Backgroundcolor.blue() > 380)
    {
        Fontcolor.setRgb(0,0,0);
    }
    else
    {
        Fontcolor.setRgb(255,255,255);
    }
    Core->writeOnlyFile(Fontcolorpath,Core->rgbColor(&Fontcolor));
    setColorTheme();
}

/*  set color;*/

void SuperWindow::setColorTheme()
{
    enableThemesApi(false,true,false,false,"1");
    QStringList backgroundrgb = Core->readOnlyFile(Backgroundcolorpath).split(",");
    QStringList fontrgb = Core->readOnlyFile(Fontcolorpath).split(",");
    Core->replaceFile(":/__supericon__/_colortitle_.png",Localtitlepath);
    if(backgroundrgb.count() >= 3 && fontrgb.count() >= 3)
    {
        Backgroundcolor.setRgb(backgroundrgb.at(0).toInt(),backgroundrgb.at(1).toInt(),backgroundrgb.at(2).toInt());
        Fontcolor.setRgb(fontrgb.at(0).toInt(),fontrgb.at(1).toInt(),fontrgb.at(2).toInt());
    }
    setWidgetTheme();
}

/*  set color theme;*/

void SuperWindow::setHeartOfIronTheme()
{
    enableThemesApi(false,false,true,false,"2");
    Core->replaceFile(":/__supericon__/_heartofirontitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(121,35,32);
    Fontcolor.setRgb(255,255,255);
    setWidgetTheme();
}

/*  set Heart of iron theme;*/

void SuperWindow::setGoerTekTheme()
{
    enableThemesApi(false,false,false,true,"3");
    Core->replaceFile(":/__supericon__/_goertektitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(69,86,17);
    Fontcolor.setRgb(255,255,255);
    setWidgetTheme();
}

/*  set goertek theme;*/

void SuperWindow::setWidgetTheme()
{
    Strrgbbackgroundcolor = "rgb(" + Core->rgbColor(&Backgroundcolor) + ")";
    Strrgbfontcolor = "rgb(" + Core->rgbColor(&Fontcolor) + ")";
    setStyleSheet("QGroupBox{border:1px solid " + Strrgbbackgroundcolor + "}");
    Title->setStyleSheet("QFrame#SuperTitleui{border-image:url(" + Localtitlepath + ");background-color:" + Strrgbbackgroundcolor + "}QWidget{color:" + Strrgbfontcolor + "}");
    Title->setSourceColor(Strrgbbackgroundcolor);
    Core->writeOnlyFile(Backgroundcolorpath,Core->rgbColor(&Backgroundcolor));
    Core->writeOnlyFile(Fontcolorpath,Core->rgbColor(&Fontcolor));
    updateSvgFile();
}

/*  set widget style sheet;*/

void SuperWindow::updateSvgFile()
{
    if(Backgroundcolor.red() + Backgroundcolor.green() + Backgroundcolor.blue() > 380)
    {
        Activatestatus = "b";
    }
    else
    {
        Activatestatus = "w";
    }
    addMaxisizeButton(Activatestatus);
    addCloseButton(Activatestatus);
    addMinisizeButton(Activatestatus);
}

/*  update svg file when change color and frame show status;*/

void SuperWindow::setDeactiveTheme()
{
    Activatestatus = "b";
    Title->setStyleSheet("");
    addMaxisizeButton(Activatestatus);
    addCloseButton(Activatestatus);
    addMinisizeButton(Activatestatus);
}

/*  set deactive style sheet;*/

void SuperWindow::addFrameFunction()
{
    Functionenable = true;
    Supermenu = new QMenu(this);
    Core->addMenu(Supermenu,Themes,"Themes");
    enableMaxisize();
}

/*  enable frames' function;*/

void SuperWindow::addMenu(QMenu *menu,QString titlename,bool addseparator)
{
    Core->addMenu(Supermenu,menu,titlename);
    if(addseparator)
    {
        Supermenu->addSeparator();
    }
}

/*  frame add menu interface;*/

void SuperWindow::addAction(QAction *action)
{
    Supermenu->addAction(action);
}

/*  frame add action interface;*/

void SuperWindow::addThemesAction(QAction *action)
{
    Themes->addAction(action);
}

/*  themes add action interface;*/

void SuperWindow::show()
{
    if(windowState().testFlag(Qt::WindowNoState) && !Showtimes)
    {
        QWidget::show();
        moveCenter(this);
        activateWindow();
        Showtimes = true;
        Timer->start(Showinterval);
    }
    else if(windowState().testFlag(Qt::WindowMinimized) && windowState().testFlag(Qt::WindowMaximized))
    {
        showMaximized();
    }
    else if(windowState().testFlag(Qt::WindowMaximized) && isHidden())
    {
        showMaximized();
    }
    else
    {
        showNormal();
        activateWindow();
    }
}

/*  dialog show,move to center and activate windows;*/

void SuperWindow::moveCenter(QWidget *widget)
{
    int width = qApp->primaryScreen()->geometry().width();
    int height = qApp->primaryScreen()->geometry().height();
    move((width - widget->width()) / 2,(height - widget->height()) / 2);
}

/*  cal screen width and height and move to center;*/

void SuperWindow::addResizeFunction()
{
    setMouseTracking(true);
    ui->PluginBox->setMouseTracking(true);
}

/*  add drag function;*/

Qt::CursorShape SuperWindow::calMousePosition(QMouseEvent *event)
{
    int mousewidth = event->position().x();
    int mouseheight = event->position().y();
    if(mousewidth && mousewidth)
    {
        int windowwidth = width();
        int windowheight = height();
        int posx = abs(mousewidth - windowwidth);
        int posy = abs(mouseheight - windowheight);
        if(posx < Border && posy < Border)
        {
            return Qt::SizeFDiagCursor;
        }
        else if(posx > Border && posy < Border)
        {
            return Qt::SizeVerCursor;
        }
        else if(posx < Border && posy > Border)
        {
            return Qt::SizeHorCursor;
        }
    }
    return Qt::ArrowCursor;
}

/*  cal mouse position;*/

void SuperWindow::resizeByCursor()
{
    QPointF movesize = QCursor::pos() - Point;
    QRectF tempgeometry = Geometry;
    switch (cursor().shape())
    {
        case Qt::SizeFDiagCursor:
        {
            tempgeometry.setBottomRight(Geometry.bottomRight() + movesize);
            setGeometry(tempgeometry.toRect());
            break;
        }
        case Qt::SizeVerCursor:
        {
            tempgeometry.setBottom(Geometry.bottom() + movesize.y());
            setGeometry(tempgeometry.toRect());
            break;
        }
        case Qt::SizeHorCursor:
        {
            tempgeometry.setRight(Geometry.right() + movesize.x());
            setGeometry(tempgeometry.toRect());
            break;
        }
        default:
        {
            break;
        }
    }
}

/*  resize;*/

void SuperWindow::close()
{
    Mouseontitle = false;
    QWidget::close();
}

/*  close and reset parameter;*/
