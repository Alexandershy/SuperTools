#ifndef _SUPERTABWIDGET__H
#define _SUPERTABWIDGET__H

#include <QTabWidget>

class SuperTabWidget : public QTabWidget
{
    Q_OBJECT

public:

    SuperTabWidget(
        QWidget *parent = nullptr);

    ~SuperTabWidget();

private:

    void Init();

    void Parameterinit();

};

#endif // _SUPERTABWIDGET__H
