#include "_hitbricksdialogui_.h"
#include "ui__hitbricksdialogui_.h"

HitBricksDialogui::HitBricksDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::HitBricksDialogui)
{
    ui->setupUi(this);
}

HitBricksDialogui::~HitBricksDialogui()
{
    delete ui;
}







