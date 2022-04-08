#include "_supernotedialogui_.h"

SuperNoteDialogui::SuperNoteDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperNoteDialogui)
{
    ui->setupUi(this);
}

SuperNoteDialogui::~SuperNoteDialogui()
{
    delete ui;
}

/*  for ui;*/
