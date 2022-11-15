#ifndef SISTEMA_GLOBAL_H
#define SISTEMA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SISTEMA_LIBRARY)
#  define SISTEMA_EXPORT Q_DECL_EXPORT
#else
#  define SISTEMA_EXPORT Q_DECL_IMPORT
#endif

#endif // SISTEMA_GLOBAL_H
