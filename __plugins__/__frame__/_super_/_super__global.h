#ifndef _SUPER__GLOBAL_H
#define _SUPER__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_SUPER__LIBRARY)
#  define _SUPER__EXPORT Q_DECL_EXPORT
#else
#  define _SUPER__EXPORT Q_DECL_IMPORT
#endif

#endif // _SUPER__GLOBAL_H
