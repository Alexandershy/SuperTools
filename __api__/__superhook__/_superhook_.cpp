#include "_superhook_.h"

HHOOK SuperHook::Keyhook                                = NULL;
std::function<void(int)> SuperHook::Pressedfunction     = NULL;
QList<int> *SuperHook::Keyvaluelist                     = nullptr;

SuperHook::SuperHook(QObject *parent)
    : QObject(parent)
{
    Keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)Keyhookevent, GetModuleHandle(NULL), 0);
}

SuperHook::~SuperHook()
{
    if (Keyhook != NULL)
    {
        UnhookWindowsHookEx(Keyhook);
        Keyhook = NULL;
    }
}

void SuperHook::Setpressedfunction(const std::function<void(int)> function)
{
    Pressedfunction = function;
}

/*  set pressed function;*/

LRESULT CALLBACK SuperHook::Keyhookevent(int code, WPARAM wparameter, LPARAM lparameter)
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

void SuperHook::Setsourcekeylist(QList<int> *keyvaluelist)
{
    Keyvaluelist = keyvaluelist;
}

/*  set source key;*/
