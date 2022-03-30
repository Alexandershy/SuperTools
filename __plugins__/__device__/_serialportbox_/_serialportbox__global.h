#ifndef _SERIALPORTBOX__GLOBAL_H
#define _SERIALPORTBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_SERIALPORTBOX__LIBRARY)
#  define _SERIALPORTBOX__EXPORT Q_DECL_EXPORT
#else
#  define _SERIALPORTBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _SERIALPORTBOX__GLOBAL_H
