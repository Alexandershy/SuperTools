#ifndef _RICHERBOX__GLOBAL_H
#define _RICHERBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_RICHERBOX__LIBRARY)
#  define _RICHERBOX__EXPORT Q_DECL_EXPORT
#else
#  define _RICHERBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _RICHERBOX__GLOBAL_H
