#ifndef _TCPCLIENTBOX__GLOBAL_H
#define _TCPCLIENTBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_TCPCLIENTBOX__LIBRARY)
#  define _TCPCLIENTBOX__EXPORT Q_DECL_EXPORT
#else
#  define _TCPCLIENTBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _TCPCLIENTBOX__GLOBAL_H
