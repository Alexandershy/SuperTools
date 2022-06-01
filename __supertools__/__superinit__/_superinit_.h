#ifndef _SUPERINIT__H
#define _SUPERINIT__H

#include "__supercore__/_supercore_.h"
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
    void init();

    void objectInit();

    void creatFolder();

    void creatFile();

    void creatModuleFiles();

    void readmeInit();

    void defaultSetting();

    void enterMainFrame();

    void selectIni();

    void setIniFile(
            QString file);

    void local();

private:

    Ui::SuperInit *ui       = nullptr;
    SuperCore *Core         = nullptr;
    QString Defaultsetting  = "/__depycache__/__cache__/__setting__/_defaultsetting_.ini";

signals:

    void signalIa(
            QString setting);

};

#endif // _SUPERINIT__H
