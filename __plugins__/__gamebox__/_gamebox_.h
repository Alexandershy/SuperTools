#ifndef _GAMEBOX__H
#define _GAMEBOX__H
#define _GAMEBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__hitbricks__/_hitbricksdialog_.h"
#include "__module__/_gamemodulea_.h"

/**************interface****************/
class _GAMEBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class gamebox new instance pointer;*/
};

class GameBox : public SuperTab
{
    Q_OBJECT

public:

    GameBox(
            QWidget *parent = nullptr);

    ~GameBox();

private:

    GameModuleA *Modulea            = nullptr;
    QString Hitbricks               = "./__depycache__/__game__/_hitbricks_.super";
    QStringList *Gamefilelist       = nullptr;
    SuperLogger *Logger             = nullptr;
    SuperFileManager *Filemanager   = nullptr;
    QString Sourcepath              = "./__depycache__/__game__/";

private slots:
    /*  main function;*/
    void init();

    void objectInit();

    void parameterInit();

    void creatGameFileInit();

    void play();

};

#endif // _GAMEBOX__H
