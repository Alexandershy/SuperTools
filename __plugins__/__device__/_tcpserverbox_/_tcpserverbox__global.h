#ifndef _TCPSERVERBOX__GLOBAL_H
#define _TCPSERVERBOX__GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(_TCPSERVERBOX__LIBRARY)
#  define _TCPSERVERBOX__EXPORT Q_DECL_EXPORT
#else
#  define _TCPSERVERBOX__EXPORT Q_DECL_IMPORT
#endif

#endif // _TCPSERVERBOX__GLOBAL_H
