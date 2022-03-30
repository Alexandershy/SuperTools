#ifndef _RESUPER__H
#define _RESUPER__H

#include "__supercore__/_supercore_.h"
#include "_resuper__global.h"
#include <QApplication>
#include <QTimer>

class _RESUPER__EXPORT Interface
{
public:
    QWidget* Loadplugin();                                /*  return class resuper new instance pointer;*/
};

class Resuper : public QWidget
{
    Q_OBJECT

public:

    Resuper(
            QWidget *parent = nullptr);

    ~Resuper();

private:

    QString Openstatuspath      = "./__depycache__/__cache__/__ini__/_openedstatus_.ini";
    SuperCore* SuperC           = nullptr;
    QTimer *Timer               = nullptr;

private slots:

    void Init();

    void Writeinit();

    void Objectinit();

    void Timerinit();

    void Closeapp();

};


#endif // _RESUPER__H
