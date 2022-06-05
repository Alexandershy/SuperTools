#include "_supercolordialog_.h"
#include "ui__supercolordialogui_.h"

SuperColorDialog::SuperColorDialog(QWidget *parent,QColor sourcecolor)
    :SuperWindow(parent)
{
    Sourcecolor = sourcecolor;
    disableMaxisize();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    setTitle("SuperColorDialog");
    init();
}

SuperColorDialog::~SuperColorDialog()
{

}

void SuperColorDialog::init()
{
    objectInit();
    colorInit();
}

void SuperColorDialog::objectInit()
{
    Plugin = new SuperColorDialogui(this);
    setWidget(Plugin);
    connect(Plugin->ui->tableWidget,        &QTableWidget::itemPressed, this,&SuperColorDialog::refreshRgbColora);
    connect(Plugin->ui->pushButton_2,       &QPushButton::clicked,      this,&SuperColorDialog::selectColor);
    connect(Plugin->ui->spinBox,            &QSpinBox::textChanged,     this,&SuperColorDialog::refreshLabelColor);
    connect(Plugin->ui->spinBox_2,          &QSpinBox::textChanged,     this,&SuperColorDialog::refreshLabelColor);
    connect(Plugin->ui->spinBox_3,          &QSpinBox::textChanged,     this,&SuperColorDialog::refreshLabelColor);
    connect(Plugin->ui->horizontalSlider,   &QSlider::sliderReleased,   this,&SuperColorDialog::refreshSampler);
    connect(Plugin->Painter,                &SuperPainter::signalPa,    this,&SuperColorDialog::refreshRgbColorb);
    connect(Plugin->ui->pushButton_3,       &QPushButton::clicked,      this,&SuperColorDialog::changeBasicColor);
    connect(Plugin->ui->pushButton,         &QPushButton::clicked,      this,&SuperColorDialog::close);
    connect(this,                           &SuperColorDialog::signalWd,this,&SuperColorDialog::changeBasicColor);
    connect(this,                           &SuperColorDialog::signalWd,this,&SuperColorDialog::refreshLabelColor);
}

void SuperColorDialog::colorInit()
{
    for(int i = 0;i < Rowcounts;i++)
    {
        for(int j = 0;j < Columncounts;j++)
        {
            int red = Coloritem.at(i).at(j).at(0);
            int green = Coloritem.at(i).at(j).at(1);
            int blue = Coloritem.at(i).at(j).at(2);
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setBackground(QColor(red,green,blue));
            Plugin->ui->tableWidget->setItem(i,j,item);
        }
    }
    Plugin->ui->lineEdit->setText(Sourcecolor.name());
    Plugin->ui->spinBox->setValue(Sourcecolor.red());
    Plugin->ui->spinBox_2->setValue(Sourcecolor.green());
    Plugin->ui->spinBox_3->setValue(Sourcecolor.blue());
}

/*  add color to table widget;*/

void SuperColorDialog::refreshRgbColora(QTableWidgetItem *item)
{
    int row = item->row();
    int column = item->column();
    int red = Coloritem.at(row).at(column).at(0);
    int green = Coloritem.at(row).at(column).at(1);
    int blue = Coloritem.at(row).at(column).at(2);
    Plugin->ui->spinBox->setValue(red);
    Plugin->ui->spinBox_2->setValue(green);
    Plugin->ui->spinBox_3->setValue(blue);
}

/*  add rgb to spinbox;*/

void SuperColorDialog::refreshRgbColorb(QColor color)
{
    Plugin->ui->spinBox->setValue(color.red());
    Plugin->ui->spinBox_2->setValue(color.green());
    Plugin->ui->spinBox_3->setValue(color.blue());
}

/*  add rgb to spinbox;*/

void SuperColorDialog::refreshLabelColor()
{
    int red = Plugin->ui->spinBox->value();
    int green = Plugin->ui->spinBox_2->value();
    int blue = Plugin->ui->spinBox_3->value();
    QColor color(red,green,blue);
    Plugin->ui->label->setPalette(color);
    Plugin->ui->lineEdit->setText(color.name());
}

/*  add rgb to spinbox;*/

void SuperColorDialog::selectColor()
{
    QColor color(Plugin->ui->spinBox->value(),Plugin->ui->spinBox_2->value(),Plugin->ui->spinBox_3->value());
    emit signalSa(color);
}

/*  select current color;*/

void SuperColorDialog::refreshSampler()
{
    Plugin->Painter->repainter(Colorindex,Plugin->ui->horizontalSlider->value());
}

/*  refresh sampler;*/

void SuperColorDialog::changeBasicColor()
{
    QColor color;
    switch (Colorindex)
    {
    case 0:
    {
        Colorindex = 1;
        color.setRgb(0,255,0);
        break;
    }
    case 1:
    {
        Colorindex = 2;
        color.setRgb(0,0,255);
        break;
    }
    case 2:
    {
        Colorindex = 0;
        color.setRgb(255,0,0);
        break;
    }
    }
    QPalette palette = Plugin->ui->pushButton_3->palette();
    palette.setColor(QPalette::ButtonText,color);
    Plugin->ui->pushButton_3->setPalette(palette);
    refreshSampler();
}

/*  change basic color and refresh sampler;*/
