#ifndef _SUPERFILESYSTEMMODEL__H
#define _SUPERFILESYSTEMMODEL__H

#include <QFileSystemModel>

class SuperFileSystemModel : public QFileSystemModel
{
    Q_OBJECT

public:

    SuperFileSystemModel(
        QObject *parent = nullptr);

    ~SuperFileSystemModel();

private:

    void init();

    void parameterInit();

};

#endif // _SUPERFILESYSTEMMODEL__H
