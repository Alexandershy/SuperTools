#ifndef _GAMEBOX__GLOBAL_H
#define _GAMEBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_GAMEBOX__LIBRARY)
#  define _GAMEBOX__EXPORT Q_DECL_EXPORT
#else
#  define _GAMEBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _GAMEBOX__GLOBAL_H
