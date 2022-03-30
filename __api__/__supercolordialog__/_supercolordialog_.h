#ifndef _SUPERCOLORDIALOG__H
#define _SUPERCOLORDIALOG__H

#include "_supercolorbox_.h"
#include "__superwindow__/_superwindow_.h"
#include <QPalette>

class SuperColorDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperColorDialog(
        QWidget *parent = nullptr,
        QColor sourcecolor = "");

    ~SuperColorDialog();

public slots:

    void Changebasiccolor();

    void Refreshlabelcolor();

private:

    QColor Sourcecolor                          = "";
    SuperColorBox *Plugin                       = nullptr;
    int Rowcounts                               = 8;
    int Columncounts                            = 8;
    int Difference                              = 85;
    QVector<QVector<QVector<int>>> Coloritem    = {
                                                {{0,0,0},        {85,0,0},       {170,0,0},      {255,0,0},      {0,85,0},       {85,85,0},      {170,85,0},     {255,85,0}},
                                                {{0,170,0},      {85,170,0},     {170,170,0},    {255,170,0},    {0,255,0},      {85,255,0},     {170,255,0},    {255,255,0}},
                                                {{0,0,85},       {85,0,85},      {170,0,85},     {255,0,85},     {0,85,85},      {85,85,85},     {170,85,85},    {255,85,85}},
                                                {{0,170,85},     {85,170,85},    {170,170,85},   {255,170,85},   {0,255,85},     {85,255,85},    {170,255,85},   {255,255,85}},
                                                {{0,0,170},      {85,0,170},     {170,0,170},    {255,0,170},    {0,85,170},     {85,85,170},    {170,85,170},   {255,85,170}},
                                                {{0,170,170},    {85,170,170},   {170,170,170},  {255,170,170},  {0,255,170},    {85,255,170},   {170,255,170},  {255,255,170}},
                                                {{0,0,255},      {85,0,255},     {170,0,255},    {255,0,255},    {0,85,255},     {85,85,255},    {170,85,255},   {255,85,255}},
                                                {{0,170,255},    {85,170,255},   {170,170,255},  {255,170,255},  {0,255,255},    {85,255,255},   {170,255,255},  {255,255,255}},
                                                };
    int Colorindex                              = 2;
    QTimer *Timer                               = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Colorinit();

    void Refreshrbgcolora(
        QTableWidgetItem *item);

    void Refreshrbgcolorb(
        QColor color);

    void Selectcolor();

    void Refreshsampler();

signals:

    void Signalsa(
        QColor color);

};


#endif // _SUPERCOLORDIALOG__H
