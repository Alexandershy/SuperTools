#ifndef _DEMOBOX__GLOBAL_H
#define _DEMOBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_DEMOBOX__LIBRARY)
#  define _DEMOBOX__EXPORT Q_DECL_EXPORT
#else
#  define _DEMOBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _DEMOBOX__GLOBAL_H
