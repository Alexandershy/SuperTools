#ifndef _SUPERHOOK__H
#define _SUPERHOOK__H
#define _SUPERHOOK__EXPORT Q_DECL_EXPORT

#include <QObject>

#ifdef Q_CC_MSVC
#include <windows.h>

class _SUPERHOOK__EXPORT SuperHook : public QObject
{
    Q_OBJECT

public:

    SuperHook(
        QObject *parent = nullptr);

    ~SuperHook();

public:

    static LRESULT CALLBACK keyHookEvent(
        int code,
        WPARAM wparameter,
        LPARAM lparameter);

    void setPressedFunction(
        std::function<void(int)> function);

    void setSourceKeyList(
        QList<int> *keyvaluelist);

private:

    static HHOOK Keyhook;
    static std::function<void(int)> Pressedfunction;
    static QList<int> *Keyvaluelist;

};

#endif

#ifdef Q_CC_GNU

class _SUPERHOOK__EXPORT SuperHook : public QObject
{
    Q_OBJECT

public:

    SuperHook(
        QObject *parent = nullptr);

    ~SuperHook();

public:

    void setPressedFunction(
        std::function<void(int)> function);

    void setSourceKeyList(
        QList<int> *keyvaluelist);


private:

    static std::function<void(int)> Pressedfunction;
    static QList<int> *Keyvaluelist;

};

#endif

#endif // _SUPERHOOK__H
