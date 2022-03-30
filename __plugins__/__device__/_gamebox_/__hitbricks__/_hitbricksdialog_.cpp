#include "_hitbricksdialog_.h"

HitBricksDialog::HitBricksDialog(QWidget *parent)
    : SuperWindow(parent)
{
    Disablemaxisize();
    Settitle("Hit Bricks V1.01");
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose);
    Init();
}

HitBricksDialog::~HitBricksDialog()
{

}

void HitBricksDialog::Init()
{
    Objectinit();
    Backgroundinit();
}

void HitBricksDialog::Objectinit()
{
    Plugin = new HitBricksBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(this,&HitBricksDialog::Signalwa,this,&HitBricksDialog::Setfocus);
    connect(this,&HitBricksDialog::Signalwd,this,&HitBricksDialog::Addsceneinit);
}

/*  creat object and set focus;*/

void HitBricksDialog::Backgroundinit()
{
    Plugin->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    Plugin->ui->graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
}

/*  set antialiasing and minimal update mode;*/

void HitBricksDialog::Setfocus()
{
    Plugin->ui->graphicsView->setFocus();
}

/*  set focus;*/

void HitBricksDialog::Addsceneinit()
{
    Mainscene = new HitBricksScene(nullptr,Plugin->ui->graphicsView);
    Plugin->ui->graphicsView->setScene(Mainscene);
}

/*  add scene;*/
