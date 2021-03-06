#ifndef _SUPERTABWIDGET__H
#define _SUPERTABWIDGET__H
#define _SUPERTABWIDGET__EXPORT Q_DECL_EXPORT

#include <QTabWidget>

class _SUPERTABWIDGET__EXPORT SuperTabWidget : public QTabWidget
{
    Q_OBJECT

public:

    SuperTabWidget(
        QWidget *parent = nullptr);

    ~SuperTabWidget();

private slots:

    void init();

    void parameterInit();

};

#endif // _SUPERTABWIDGET__H
