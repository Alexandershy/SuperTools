#include "_superfilesystemmodel_.h"

SuperFileSystemModel::SuperFileSystemModel(QObject *parent)
    : QFileSystemModel(parent)
{
    init();
}

SuperFileSystemModel::~SuperFileSystemModel()
{

}

void SuperFileSystemModel::init()
{
    parameterInit();
}

/*  file system model init;*/

void SuperFileSystemModel::parameterInit()
{
    setRootPath(QDir::currentPath());
    setFilter(QDir::Drives | QDir::Dirs | QDir::NoDotAndDotDot);
    setOptions(QFileSystemModel::DontWatchForChanges | QFileSystemModel::DontResolveSymlinks | QFileSystemModel::DontUseCustomDirectoryIcons);
}

/*  file system model parameter init;*/
