#ifndef _SUPERHOOK__H
#define _SUPERHOOK__H

#include <windows.h>
#include <QObject>

class SuperHook : public QObject
{
    Q_OBJECT

public:

    SuperHook(
        QObject *parent = nullptr);

    ~SuperHook();

public:

    static LRESULT CALLBACK Keyhookevent(
        int code,
        WPARAM wparameter,
        LPARAM lparameter);

    void Setpressedfunction(
        std::function<void(int)> function);

    void Setsourcekeylist(
        QList<int> *keyvaluelist);

private:

    static HHOOK Keyhook;
    static std::function<void(int)> Pressedfunction;
    static QList<int> *Keyvaluelist;
};

#endif // _SUPERHOOK__H