#ifndef _CHATBOX__GLOBAL_H
#define _CHATBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_CHATBOX__LIBRARY)
#  define _CHATBOX__EXPORT Q_DECL_EXPORT
#else
#  define _CHATBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _CHATBOX__GLOBAL_H
