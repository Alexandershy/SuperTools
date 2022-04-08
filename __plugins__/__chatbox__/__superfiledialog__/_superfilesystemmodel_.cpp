#include "_superfilesystemmodel_.h"

SuperFileSystemModel::SuperFileSystemModel(QObject *parent)
    : QFileSystemModel(parent)
{
    Init();
}

SuperFileSystemModel::~SuperFileSystemModel()
{

}

void SuperFileSystemModel::Init()
{
    Parameterinit();
}

/*  file system model init;*/

void SuperFileSystemModel::Parameterinit()
{
    setRootPath(QDir::currentPath());
    setFilter(QDir::Drives | QDir::Dirs | QDir::NoDotAndDotDot);
    setOptions(QFileSystemModel::DontWatchForChanges | QFileSystemModel::DontResolveSymlinks | QFileSystemModel::DontUseCustomDirectoryIcons);
}

/*  file system model parameter init;*/
