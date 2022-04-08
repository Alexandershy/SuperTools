#ifndef _GEMINIBOX__GLOBAL_H
#define _GEMINIBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_GEMINIBOX__LIBRARY)
#  define _GEMINIBOX__EXPORT Q_DECL_EXPORT
#else
#  define _GEMINIBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _GEMINIBOX__GLOBAL_H
