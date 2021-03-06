#ifndef _SUPERLINEEDIT__H
#define _SUPERLINEEDIT__H

#include "__supercore__/_supercore_.h"
#include <QLineEdit>

class SuperLineEdit : public QLineEdit
{
    Q_OBJECT

public:

    SuperLineEdit(
        QWidget *parent = nullptr);

    ~SuperLineEdit();

private:

    QWidget *Widget     = nullptr;
    SuperCore *Core     = nullptr;

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void appendTextInit();
};


#endif // _SUPERLINEEDIT__H
