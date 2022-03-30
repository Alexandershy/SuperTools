#ifndef _SUPERINIT__H
#define _SUPERINIT__H

#include "__supercore__/_supercore_.h"
#include "__superinit__/_superinit__ui_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supercolordialog__/_supercolordialog_.h"
#include <QLibrary>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui {class SuperInit;}
QT_END_NAMESPACE

class SuperInit : public QFrame
{
    Q_OBJECT

public:

    SuperInit(
            QWidget *window = nullptr);

    ~SuperInit();

private slots:
    /*main function;*/
    void Init();

    void Objectinit();

    void Creatfolder();

    void Creatfile();

    void Creatmodulefiles();

    void Readmeinit();

    void Default();

    void Entermainframe();

    void Selectini();

    void Setinifile(
            QString file);

    void Local();

private:

    Ui::SuperInit *ui = nullptr;
    SuperCore *SuperC = nullptr;

signals:

    void Signalia(
            QString setting);

};

#endif // _SUPERINIT__H
