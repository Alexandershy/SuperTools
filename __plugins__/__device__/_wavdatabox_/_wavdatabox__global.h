#ifndef _WAVDATABOX__GLOBAL_H
#define _WAVDATABOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_WAVDATABOX__LIBRARY)
#  define _WAVDATABOX__EXPORT Q_DECL_EXPORT
#else
#  define _WAVDATABOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _WAVDATABOX__GLOBAL_H
