#ifndef _RESUPER__GLOBAL_H
#define _RESUPER__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_RESUPER__LIBRARY)
#  define _RESUPER__EXPORT Q_DECL_EXPORT
#else
#  define _RESUPER__EXPORT Q_DECL_IMPORT
#endif

#endif // _RESUPER__GLOBAL_H
