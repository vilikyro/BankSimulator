#ifndef PINKOODI_DLL_GLOBAL_H
#define PINKOODI_DLL_GLOBAL_H

//#include <QtCore/qglobal.h>

#if defined(PINKOODI_DLL_LIBRARY)
#  define PINKOODI_DLL_EXPORT Q_DECL_EXPORT
#else
#  define PINKOODI_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // PINKOODI_DLL_GLOBAL_H
