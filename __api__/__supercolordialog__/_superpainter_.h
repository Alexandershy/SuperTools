#ifndef _SUPERPAINTER__H
#define _SUPERPAINTER__H

#include <QLabel>
#include <QLayout>
#include <QPainter>
#include <QMouseEvent>

class SuperPainter : public QLabel
{
    Q_OBJECT

public:

    SuperPainter(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~SuperPainter();

public slots:

    void repainter(
        int basiccolor,
        int colorvalue);

protected:

    void mousePressEvent(
        QMouseEvent *event);

    void paintEvent(
        QPaintEvent * event);

private:

    QWidget *Widget                             = nullptr;
    QLayout *Layout                             = nullptr;
    QColor Initcolor                            = Qt::blue;
    QColor Pointcolor                           = Qt::red;
    int Colorcounts                             = 3;
    int Basiccolor                              = 0;
    int Colorvalue                              = 0;
    QVector<QVector<QVector<int>>> Colorvector  = {};

private slots:

    void init();

    void parameterInit();

    void calColorVector();

    void calPointColor(
        int xvalue,
        int yvalue);

signals:

    void signalPa(
        QColor color);

};


#endif // _SUPERPAINTER__H
