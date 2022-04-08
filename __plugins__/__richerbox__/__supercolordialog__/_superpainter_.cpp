#include "_superpainter_.h"

SuperPainter::SuperPainter(QWidget *parent,QLayout *layout)
    : QLabel(parent)
{
    Widget = parent;
    Layout = layout;
    Init();
}

SuperPainter::~SuperPainter()
{

}

void SuperPainter::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    if(Colorvector.isEmpty())
    {
        return;
    }
    QPainter painter(this);
    for(int i = 0;i < width();i++)
    {
        for(int j = 0;j < height();j++)
        {
            QColor colortemp(Colorvector.at(i).at(j).at(0),Colorvector.at(i).at(j).at(1),Colorvector.at(i).at(j).at(2));
            painter.setPen(colortemp);
            painter.drawPoint(i,j);
        }
    }
}

/*  rewrite paint event function;*/

void SuperPainter::mousePressEvent(QMouseEvent *event)
{
    switch (event->button())
    {
        case Qt::LeftButton:
        {          
            Calpointcolor(event->position().x(),event->position().y());
            emit Signalpa(Pointcolor);
            break;
        }
        default:
        {
            break;
        }
    }
}

/*  rewrite press event function;*/

void SuperPainter::Init()
{
    Parameterinit();
}

/*  widget init;*/

void SuperPainter::Parameterinit()
{
    Layout->addWidget(this);
}

/*  parameter init;*/

void SuperPainter::Repainter(int basiccolor,int colorvalue)
{
    Basiccolor = basiccolor;
    Colorvalue = colorvalue;
    Calcolorvector();
    update();
}

/*  repaint label;*/

void SuperPainter::Calcolorvector()
{
    Colorvector.clear();
    int xcolor = 0;
    int ycolor = 0;
    switch(Basiccolor)
    {
        case 0:
        {
            for(int i = 0;i < width();i++)
            {
                Colorvector.append(QVector<QVector<int>> ());
                for(int j = 0;j < height();j++)
                {
                    xcolor = 255 * i / width();
                    ycolor = 255 * j / height();
                    Colorvector[i].append({Colorvalue,xcolor,ycolor});
                }
            }
            break;
        }
        case 1:
        {
            for(int i = 0;i < width();i++)
            {
                Colorvector.append(QVector<QVector<int>> ());
                for(int j = 0;j < height();j++)
                {
                    xcolor = 255 * i / width();
                    ycolor = 255 * j / height();
                    Colorvector[i].append({xcolor,Colorvalue,ycolor});
                }
            }
            break;
        }
        case 2:
        {
            for(int i = 0;i < width();i++)
            {
                Colorvector.append(QVector<QVector<int>> ());
                for(int j = 0;j < height();j++)
                {
                    xcolor = 255 * i / width();
                    ycolor = 255 * j / height();
                    Colorvector[i].append({xcolor,ycolor,Colorvalue});
                }
            }
            break;
        }
    }
}

/*  cal color vector;*/

void SuperPainter::Calpointcolor(int xvalue,int yvalue)
{
    int xcolor = 255 * xvalue / width();
    int ycolor = 255 * yvalue / height();
    switch(Basiccolor)
    {
        case 0:
        {
            Pointcolor.setRgb(Colorvalue,xcolor,ycolor);
            break;
        }
        case 1:
        {
            Pointcolor.setRgb(xcolor,Colorvalue,ycolor);
            break;
        }
        case 2:
        {
            Pointcolor.setRgb(xcolor,ycolor,Colorvalue);
            break;
        }
    }
}

/*  cal start color;*/
