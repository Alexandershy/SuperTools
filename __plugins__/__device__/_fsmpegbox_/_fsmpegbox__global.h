#ifndef _FSMPEGBOX__GLOBAL_H
#define _FSMPEGBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_FSMPEGBOX__LIBRARY)
#  define _FSMPEGBOX__EXPORT Q_DECL_EXPORT
#else
#  define _FSMPEGBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _FSMPEGBOX__GLOBAL_H
