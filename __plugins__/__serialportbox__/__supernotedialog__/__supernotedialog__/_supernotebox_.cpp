#include "_supernotebox_.h"

SuperNoteBox::SuperNoteBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperNoteBox)
{
    ui->setupUi(this);
}

SuperNoteBox::~SuperNoteBox()
{
    delete ui;
}
