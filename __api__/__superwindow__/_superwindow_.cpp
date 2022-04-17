#include "_superwindow_.h"

SuperWindow::SuperWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SuperWindowui)
{
    ui->setupUi(this);
    Init();
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
            Close();
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
            Changemaxicon();
            move(Point.x() - Normalgeometry.width() / 2,Point.y() - Title->height() / 2);
        }
        int dx = event->globalPosition().x() - Point.x();
        int dy = event->globalPosition().y() - Point.y();
        Point = event->globalPosition();
        move(x() + dx,y() + dy);
    }
    else if(!isMaximized() && !Pressed)
    {
        setCursor(Calmouseposition(event));
    }
    else if(!isMaximized() && Pressed)
    {
        Resizebycursor();
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
            emit Signalwa();
            break;
        }
        case QEvent::WindowDeactivate:
        {
            emit Signalwc();
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

void SuperWindow::Init()
{
    Objectinit();
    Colorinit();
    Parameterinit();
    Pointerinit();
}

/*  class init;*/

void SuperWindow::Objectinit()
{
    Core = new SuperCore(this);
    Title = new SuperTitle(this);
    Timer = new QTimer(this);
    connect(Title->Minisizebutton,      &QPushButton::clicked,  this,&SuperWindow::Minimized);
    connect(Title->Maxisizebutton,      &QPushButton::clicked,  this,&SuperWindow::Changemaxicon);
    connect(Title->Closebutton,         &QPushButton::clicked,  this,&SuperWindow::Close);
    connect(Title,                      &SuperTitle::Signalsa,  this,&SuperWindow::Mouseenter);
    connect(Title,                      &SuperTitle::Signalsb,  this,&SuperWindow::Changemaxicon);
    connect(Title,                      &SuperTitle::Signalsc,  this,&SuperWindow::setCursor);
    connect(this,                       &SuperWindow::Signalwa, this,&SuperWindow::Setwidgettheme);
    connect(this,                       &SuperWindow::Signalwc, this,&SuperWindow::Setdeactivetheme);
    connect(Timer,                      &QTimer::timeout,       this,&SuperWindow::Signalwd);
    connect(Timer,                      &QTimer::timeout,       Timer,&QTimer::deleteLater);
}

/*  objectinit;*/

void SuperWindow::Colorinit()
{
    QStringList rgbbackgroundcolor = Core->Readonlyfile(Backgroundcolorpath).split(",");
    QStringList rgbfontcolor = Core->Readonlyfile(Fontcolorpath).split(",");
    if(rgbbackgroundcolor.count() >= 3 && rgbfontcolor.count() >= 3)
    {
        Backgroundcolor.setRgb(rgbbackgroundcolor.at(0).toInt(),rgbbackgroundcolor.at(1).toInt(),rgbbackgroundcolor.at(2).toInt());
        Fontcolor.setRgb(rgbfontcolor.at(0).toInt(),rgbfontcolor.at(1).toInt(),rgbfontcolor.at(2).toInt());
        Concolor.setRgb(255 - rgbbackgroundcolor.at(0).toInt(),255 - rgbbackgroundcolor.at(1).toInt(),255 - rgbbackgroundcolor.at(2).toInt());
    }
    Strrgbbackgroundcolor = "rgb(" + Core->Rgbcolor(&Backgroundcolor) + ")";
    Strrgbfontcolor = "rgb(" + Core->Rgbcolor(&Fontcolor) + ")";
    Strrgbconcolor = "rgb(" + Core->Rgbcolor(&Concolor) + ")";
}

/*  if rgb file exist,use color saved,else use default color;*/

void SuperWindow::Parameterinit()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    setStyleSheet("QGroupBox{border:1px solid " + Strrgbbackgroundcolor + "}");
    setWindowIcon(QIcon(":/__supericon__/_supertools_.ico"));
    Title->setStyleSheet("QFrame#SuperTitleui{border-image:url(./__depycache__/__cache__/__picture__/_localtitle_.png);background-color:" + Strrgbbackgroundcolor + "}QWidget{color:" + Strrgbfontcolor + "}");
    Title->ui->pushButton_5->setStyleSheet("border-image:url(:/__supericon__/_supertools_.ico);");
    Title->Minisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "minimize_.svg"));
    Title->ui->label_2->setText(objectName());
    ui->Titlelayout->addWidget(Title);
    Addmaxisizebutton(Activatestatus);
    Addclosebutton(Activatestatus);
}

/*  style init;*/

void SuperWindow::Pointerinit()
{
    Pluginlayout = ui->Pluginlayout;
}

/*  public pointer;*/

void SuperWindow::Addmaxisizebutton(QString colorstyle)
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

void SuperWindow::Addclosebutton(QString colorstyle)
{
    if(Enableclosebutton)
    {
        Title->Closebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "close_.svg"));
    }
}

/*  add close button;*/

void SuperWindow::Addminisizebutton(QString colorstyle)
{
    Title->Minisizebutton->setIcon(QIcon(":/__supericon__/_" + colorstyle + "minimize_.svg"));
}

/*  add minisize button;*/

void SuperWindow::Settitle(QString titletext)
{
    Title->ui->label_2->setText(titletext);
}

/*  set title;*/

void SuperWindow::Disablemaxisize()
{
    disconnect(Title,                   &SuperTitle::Signalsb,  this,&SuperWindow::Changemaxicon);
    disconnect(Title->Maxisizebutton,   &QPushButton::clicked,  this,&SuperWindow::Changemaxicon);
    Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_blank_.png"));
    Title->Maxisizebutton->setEnabled(false);
    Enablemaxbutton = false;
}

/*  disable maxisize function and button;*/

void SuperWindow::Enablemaxisize()
{
    Enablemaxbutton = true;
    connect(Title,                  &SuperTitle::Signalsb,this,&SuperWindow::Changemaxicon);
    connect(Title->Maxisizebutton,&QPushButton::clicked,this,&SuperWindow::Changemaxicon);
    Title->Maxisizebutton->setEnabled(true);
    Addmaxisizebutton(Activatestatus);
}

/*  enable maxisize function and button;*/

void SuperWindow::Disableclose()
{
    disconnect(Title->Closebutton,&QPushButton::clicked,this,&SuperWindow::Close);
    Title->Closebutton->setIcon(QIcon(":/__supericon__/_blank_.png"));
    Title->Closebutton->setEnabled(false);
    Enableclosebutton = false;
}

/*  disable close function and button;*/

void SuperWindow::Enableclose()
{
    Enableclosebutton = true;
    connect(Title->Closebutton,&QPushButton::clicked,this,&SuperWindow::Close);
    Addclosebutton(Activatestatus);
}

/*  enable maxisize function and button;*/

void SuperWindow::Mouseenter(bool mouseontitle)
{
    Mouseontitle = mouseontitle;
}

/*  title send signal if mouse enter;*/

void SuperWindow::Changeshowstatus()
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

void SuperWindow::Changemaxicon()
{
    if(isMaximized())
    {
        Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "maximize_.svg"));
    }
    else
    {
        Title->Maxisizebutton->setIcon(QIcon(":/__supericon__/_" + Activatestatus + "restoredown_.svg"));
    }
    Changeshowstatus();
}

/*  change button status,minimized or maximized;*/

void SuperWindow::Minimized()
{
    showMinimized();
}

/*  min size;*/

void SuperWindow::Addthemefunction()
{
    Themeactioninit();
    Themeconnectinit();
    Setframetheme();
}

/*  add theme function;*/

void SuperWindow::Thememenuinit()
{
    Themes = new QMenu(this);
    Themes->setIcon(QIcon(":/__supericon__/_themes_.svg"));
}

/*  enable themes menu interface;*/

void SuperWindow::Themeactioninit()
{
    Thememenuinit();
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

void SuperWindow::Addiconfunction()
{
    connect(Title->ui->pushButton_5,&QPushButton::clicked,  this,&SuperWindow::Callmenu);
}

/*  enable icon function;*/

void SuperWindow::Themeconnectinit()
{
    Addiconfunction();
    connect(Actionoriginal,         &QAction::triggered,    this,&SuperWindow::Setoriginaltheme);
    connect(Actioncolor,            &QAction::triggered,    this,&SuperWindow::Selectcolortheme);
    connect(Actionheartofiron,      &QAction::triggered,    this,&SuperWindow::Setheartofirontheme);
    connect(Actiongoertek,          &QAction::triggered,    this,&SuperWindow::Setgoertektheme);
}

/*  enable themes' function;*/

void SuperWindow::Callmenu()
{
    if(Functionenable)
    {
        Supermenu->exec(Core->Widgetleftbottompoint(Title));
    }
    else
    {
        Themes->exec(Core->Widgetleftbottompoint(Title));
    }
}

/*  exec file menu;*/

void SuperWindow::Setframetheme()
{
    bool boola = false;
    QString stringindex = Core->Readonlyfile(Themepath);
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
            Setoriginaltheme();
            break;
        }
        case 1:
        {
            Setcolortheme();
            break;
        }
        case 2:
        {
            Setheartofirontheme();
            break;
        }
        case 3:
        {
            Setgoertektheme();
            break;
        }
    }
}

/*  set theme by which action checked;*/

void SuperWindow::Enablethemesapi(bool boola,bool boolb,bool boolc,bool boold,QString theme)
{
    Actionoriginal->setCheckable(boola);
    Actioncolor->setCheckable(boolb);
    Actionheartofiron->setCheckable(boolc);
    Actiongoertek->setCheckable(boold);
    Actionoriginal->setChecked(boola);
    Actioncolor->setChecked(boolb);
    Actionheartofiron->setChecked(boolc);
    Actiongoertek->setChecked(boold);
    Core->Writeonlyfile(Themepath,theme);
}

/*  set tabwidget background color;*/

void SuperWindow::Setoriginaltheme()
{
    Enablethemesapi(true,false,false,false,"0");
    Core->Replacefile(":/__supericon__/_originaltitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(16,81,142);
    Fontcolor.setRgb(255,255,255);
    Setwidgettheme();
}

/*  set original theme;*/

void SuperWindow::Selectcolortheme()
{
    emit Signalwb();
}

/*  select color theme;*/

void SuperWindow::Setcolor(QColor color)
{
    Backgroundcolor = color;
    Core->Writeonlyfile(Backgroundcolorpath,Core->Rgbcolor(&Backgroundcolor));
    if(Backgroundcolor.red() + Backgroundcolor.green() + Backgroundcolor.blue() > 380)
    {
        Fontcolor.setRgb(0,0,0);
    }
    else
    {
        Fontcolor.setRgb(255,255,255);
    }
    Core->Writeonlyfile(Fontcolorpath,Core->Rgbcolor(&Fontcolor));
    Setcolortheme();
}

/*  set color;*/

void SuperWindow::Setcolortheme()
{
    Enablethemesapi(false,true,false,false,"1");
    QStringList backgroundrgb = Core->Readonlyfile(Backgroundcolorpath).split(",");
    QStringList fontrgb = Core->Readonlyfile(Fontcolorpath).split(",");
    Core->Replacefile(":/__supericon__/_colortitle_.png",Localtitlepath);
    if(backgroundrgb.count() >= 3 && fontrgb.count() >= 3)
    {
        Backgroundcolor.setRgb(backgroundrgb.at(0).toInt(),backgroundrgb.at(1).toInt(),backgroundrgb.at(2).toInt());
        Fontcolor.setRgb(fontrgb.at(0).toInt(),fontrgb.at(1).toInt(),fontrgb.at(2).toInt());
    }
    Setwidgettheme();
}

/*  set color theme;*/

void SuperWindow::Setheartofirontheme()
{
    Enablethemesapi(false,false,true,false,"2");
    Core->Replacefile(":/__supericon__/_heartofirontitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(121,35,32);
    Fontcolor.setRgb(255,255,255);
    Setwidgettheme();
}

/*  set Heart of iron theme;*/

void SuperWindow::Setgoertektheme()
{
    Enablethemesapi(false,false,false,true,"3");
    Core->Replacefile(":/__supericon__/_goertektitle_.png",Localtitlepath);
    Backgroundcolor.setRgb(69,86,17);
    Fontcolor.setRgb(255,255,255);
    Setwidgettheme();
}

/*  set goertek theme;*/

void SuperWindow::Setwidgettheme()
{
    Strrgbbackgroundcolor = "rgb(" + Core->Rgbcolor(&Backgroundcolor) + ")";
    Strrgbfontcolor = "rgb(" + Core->Rgbcolor(&Fontcolor) + ")";
    setStyleSheet("QGroupBox{border:1px solid " + Strrgbbackgroundcolor + "}");
    Title->setStyleSheet("QFrame#SuperTitleui{border-image:url(" + Localtitlepath + ");background-color:" + Strrgbbackgroundcolor + "}QWidget{color:" + Strrgbfontcolor + "}");
    Title->Setsourcecolor(Strrgbbackgroundcolor);
    Core->Writeonlyfile(Backgroundcolorpath,Core->Rgbcolor(&Backgroundcolor));
    Core->Writeonlyfile(Fontcolorpath,Core->Rgbcolor(&Fontcolor));
    Updatesvgfile();
}

/*  set widget style sheet;*/

void SuperWindow::Updatesvgfile()
{
    if(Backgroundcolor.red() + Backgroundcolor.green() + Backgroundcolor.blue() > 380)
    {
        Activatestatus = "b";
    }
    else
    {
        Activatestatus = "w";
    }
    Addmaxisizebutton(Activatestatus);
    Addclosebutton(Activatestatus);
    Addminisizebutton(Activatestatus);
}

/*  update svg file when change color and frame show status;*/

void SuperWindow::Setdeactivetheme()
{
    Activatestatus = "b";
    Title->setStyleSheet("");
    Addmaxisizebutton(Activatestatus);
    Addclosebutton(Activatestatus);
    Addminisizebutton(Activatestatus);
}

/*  set deactive style sheet;*/

void SuperWindow::Addframefunction()
{
    Functionenable = true;
    Supermenu = new QMenu(this);
    Core->Addmenu(Supermenu,Themes,"Themes");
    Enablemaxisize();
}

/*  enable frames' function;*/

void SuperWindow::Addmenu(QMenu *menu,QString titlename,bool addseparator)
{
    Core->Addmenu(Supermenu,menu,titlename);
    if(addseparator)
    {
        Supermenu->addSeparator();
    }
}

/*  frame add menu interface;*/

void SuperWindow::Addaction(QAction *action)
{
    Supermenu->addAction(action);
}

/*  frame add action interface;*/

void SuperWindow::Addthemesaction(QAction *action)
{
    Themes->addAction(action);
}

/*  themes add action interface;*/

void SuperWindow::Show()
{
    if(windowState().testFlag(Qt::WindowNoState) && !Showtimes)
    {
        show();
        Movecenter(this);
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

void SuperWindow::Movecenter(QWidget *widget)
{
    int width = qApp->primaryScreen()->geometry().width();
    int height = qApp->primaryScreen()->geometry().height();
    move((width - widget->width()) / 2,(height - widget->height()) / 2);
}

/*  cal screen width and height and move to center;*/

void SuperWindow::Addresizefunction()
{
    setMouseTracking(true);
    ui->PluginBox->setMouseTracking(true);
}

/*  add drag function;*/

Qt::CursorShape SuperWindow::Calmouseposition(QMouseEvent *event)
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

void SuperWindow::Resizebycursor()
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

void SuperWindow::Close()
{
    Mouseontitle = false;
    close();
}

/*  close and reset parameter;*/
