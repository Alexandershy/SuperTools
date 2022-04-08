#ifndef _SUPERGROUPBOX__H
#define _SUPERGROUPBOX__H
#define _SUPERGROUPBOX__EXPORT Q_DECL_EXPORT

#include <QGroupBox>
#include <QVBoxLayout>

class _SUPERGROUPBOX__EXPORT SuperGroupBox : public QGroupBox
{
    Q_OBJECT

public:

    QLayout *Insidelayout   = nullptr;

public:

    SuperGroupBox(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~SuperGroupBox();

public slots:

    void Addwidget(
        QWidget *widget);

private:

    QLayout *Outsidelayout  = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

};

#endif // _SUPERGROUPBOX__H
