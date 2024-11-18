#ifndef __OPERACIONMATRIZ_H__
#define __OPERACIONMATRIZ_H__



#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#define MAX 3

#ifdef MI_DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C" DLL_API int sumaRecursivaMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int f, int c);

#endif
#endif
