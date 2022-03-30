#ifndef _CSVDATABOX__GLOBAL_H
#define _CSVDATABOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_CSVDATABOX__LIBRARY)
#  define _CSVDATABOX__EXPORT Q_DECL_EXPORT
#else
#  define _CSVDATABOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _CSVDATABOX__GLOBAL_H
