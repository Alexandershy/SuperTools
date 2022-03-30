#ifndef _SCANNERBOX__GLOBAL_H
#define _SCANNERBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_SCANNERBOX__LIBRARY)
#  define _SCANNERBOX__EXPORT Q_DECL_EXPORT
#else
#  define _SCANNERBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _SCANNERBOX__GLOBAL_H
