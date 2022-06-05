#include "_hitbricksdialog_.h"
#include "ui__hitbricksdialogui_.h"

HitBricksDialog::HitBricksDialog(QWidget *parent)
    : SuperWindow(parent)
{
    disableMaxisize();
    setTitle("Hit Bricks V1.01");
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose);
    init();
}

HitBricksDialog::~HitBricksDialog()
{

}

void HitBricksDialog::init()
{
    objectInit();
    backgroundInit();
}

void HitBricksDialog::objectInit()
{
    Plugin = new HitBricksDialogui(this);
    setWidget(Plugin);
    connect(this,&HitBricksDialog::signalWa,this,&HitBricksDialog::setFocus);
    connect(this,&HitBricksDialog::signalWd,this,&HitBricksDialog::addSceneInit);
}

/*  creat object and set focus;*/

void HitBricksDialog::backgroundInit()
{
    Plugin->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    Plugin->ui->graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
}

/*  set antialiasing and minimal update mode;*/

void HitBricksDialog::setFocus()
{
    Plugin->ui->graphicsView->setFocus();
}

/*  set focus;*/

void HitBricksDialog::addSceneInit()
{
    Mainscene = new HitBricksScene(nullptr,Plugin->ui->graphicsView);
    Plugin->ui->graphicsView->setScene(Mainscene);
}

/*  add scene;*/
