#include "_supercolordialog_.h"

SuperColorDialog::SuperColorDialog(QWidget *parent,QColor sourcecolor)
    :SuperWindow(parent)
{
    Sourcecolor = sourcecolor;
    Disablemaxisize();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Settitle("SuperColorDialog");
    Init();
}

SuperColorDialog::~SuperColorDialog()
{

}

void SuperColorDialog::Init()
{
    Objectinit();
    Colorinit();
}

void SuperColorDialog::Objectinit()
{
    Plugin = new SuperColorDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->tableWidget,        &QTableWidget::itemPressed, this,&SuperColorDialog::Refreshrbgcolora);
    connect(Plugin->ui->pushButton_2,       &QPushButton::clicked,      this,&SuperColorDialog::Selectcolor);
    connect(Plugin->ui->spinBox,            &QSpinBox::textChanged,     this,&SuperColorDialog::Refreshlabelcolor);
    connect(Plugin->ui->spinBox_2,          &QSpinBox::textChanged,     this,&SuperColorDialog::Refreshlabelcolor);
    connect(Plugin->ui->spinBox_3,          &QSpinBox::textChanged,     this,&SuperColorDialog::Refreshlabelcolor);
    connect(Plugin->ui->horizontalSlider,   &QSlider::sliderReleased,   this,&SuperColorDialog::Refreshsampler);
    connect(Plugin->Painter,                &SuperPainter::Signalpa,    this,&SuperColorDialog::Refreshrbgcolorb);
    connect(Plugin->ui->pushButton_3,       &QPushButton::clicked,      this,&SuperColorDialog::Changebasiccolor);
    connect(Plugin->ui->pushButton,         &QPushButton::clicked,      this,&SuperColorDialog::close);
    connect(this,                           &SuperColorDialog::Signalwd,this,&SuperColorDialog::Changebasiccolor);
    connect(this,                           &SuperColorDialog::Signalwd,this,&SuperColorDialog::Refreshlabelcolor);
}

void SuperColorDialog::Colorinit()
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

void SuperColorDialog::Refreshrbgcolora(QTableWidgetItem *item)
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

void SuperColorDialog::Refreshrbgcolorb(QColor color)
{
    Plugin->ui->spinBox->setValue(color.red());
    Plugin->ui->spinBox_2->setValue(color.green());
    Plugin->ui->spinBox_3->setValue(color.blue());
}

/*  add rgb to spinbox;*/

void SuperColorDialog::Refreshlabelcolor()
{
    int red = Plugin->ui->spinBox->value();
    int green = Plugin->ui->spinBox_2->value();
    int blue = Plugin->ui->spinBox_3->value();
    QColor color(red,green,blue);
    Plugin->ui->label->setPalette(color);
    Plugin->ui->lineEdit->setText(color.name());
}

/*  add rgb to spinbox;*/

void SuperColorDialog::Selectcolor()
{
    QColor color(Plugin->ui->spinBox->value(),Plugin->ui->spinBox_2->value(),Plugin->ui->spinBox_3->value());
    emit Signalsa(color);
}

/*  select current color;*/

void SuperColorDialog::Refreshsampler()
{
    Plugin->Painter->Repainter(Colorindex,Plugin->ui->horizontalSlider->value());
}

/*  refresh sampler;*/

void SuperColorDialog::Changebasiccolor()
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
    Refreshsampler();
}

/*  change basic color and refresh sampler;*/
