#include "_superhook_.h"

std::function<void(int)> SuperHook::Pressedfunction     = NULL;
QList<int> *SuperHook::Keyvaluelist                     = nullptr;

#ifdef Q_CC_MSVC
HHOOK SuperHook::Keyhook                                = NULL;

SuperHook::SuperHook(QObject *parent)
    : QObject(parent)
{
    Keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)keyHookEvent, GetModuleHandle(NULL), 0);
}

SuperHook::~SuperHook()
{
    if (Keyhook != NULL)
    {
        UnhookWindowsHookEx(Keyhook);
        Keyhook = NULL;
    }
}

void SuperHook::setPressedFunction(const std::function<void(int)> function)
{
    Pressedfunction = function;
}

/*  set pressed function;*/

LRESULT CALLBACK SuperHook::keyHookEvent(int code, WPARAM wparameter, LPARAM lparameter)
{
    if (code < 0)
        return CallNextHookEx(Keyhook, code, wparameter, lparameter);
    if (wparameter == WM_KEYDOWN)
    {
        int keyvalue = ((KBDLLHOOKSTRUCT *)lparameter)->vkCode;
        if(Keyvaluelist->contains(keyvalue))
        {
            Pressedfunction(keyvalue);
            return 0;
        }
    }
    return CallNextHookEx(Keyhook, code, wparameter, lparameter);
}

/*  return result;*/

void SuperHook::setSourceKeyList(QList<int> *keyvaluelist)
{
    Keyvaluelist = keyvaluelist;
}

/*  set source key;*/

#endif

#ifdef Q_CC_GNU

SuperHook::SuperHook(QObject *parent)
    : QObject(parent)
{

}

SuperHook::~SuperHook()
{

}

void SuperHook::setPressedFunction(const std::function<void(int)> function)
{
    Pressedfunction = function;
}

/*  set pressed function;*/

void SuperHook::setSourceKeyList(QList<int> *keyvaluelist)
{
    Keyvaluelist = keyvaluelist;
}

/*  set source key;*/

#endif
