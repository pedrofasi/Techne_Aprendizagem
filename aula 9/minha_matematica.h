#pragma once
 
#ifdef BUILD_DLL
    #define DLL_API __declspec(dllexport)
#else
    #define DLL_API __declspec(dllimport)
#endif
 
 
extern "C" {
    DLL_API int somar(int a, int b);
    DLL_API int multiplicar(int a, int b);
}