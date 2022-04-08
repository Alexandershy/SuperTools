#ifndef _WASAPIBOX__GLOBAL_H
#define _WASAPIBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_WASAPIBOX__LIBRARY)
#  define _WASAPIBOX__EXPORT Q_DECL_EXPORT
#else
#  define _WASAPIBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _WASAPIBOX__GLOBAL_H
