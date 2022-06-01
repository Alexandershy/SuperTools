#ifndef _SUPERTITLEBUTTON__H
#define _SUPERTITLEBUTTON__H

#include <QPushButton>

class SuperTitleButton : public QPushButton
{
    Q_OBJECT

public:

    SuperTitleButton(
        QWidget *parent = nullptr);

    ~SuperTitleButton();

public slots:

    void setSourceColor(
        QString rgbcolor);

protected:

    void enterEvent(
        QEnterEvent *);

    void leaveEvent(
        QEvent *);

private:

    QString Rgbcolor = "rgb(232,17,35)";

private slots:

    void init();

    void sizeInit();

    void styleSheetInit();

    void addBackGroundColor();

    void removeBackGroundColor();

};

#endif // _SUPERTITLEBUTTON__H
