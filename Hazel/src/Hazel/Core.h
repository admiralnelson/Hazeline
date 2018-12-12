#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED


    #ifdef HZ_BUILD_LINUX
        #ifdef HZ_BUILD_SO
            #define HAZEL_API __attribute__((visibility("default")))
        #else
            #define HAZEL_API
        #endif // HZ_BUILD_SO
    #elif HZ_BUILD_WINDOWS
        #ifdef HZ_BUILD_SO
            #define HAZEL_API __declspec(dllexport)
        #else
            #define HAZEL_API __declspec(dllimport)
        #endif // HZ_BUILD_SO
    #else
        #define HAZEL_API
        #pragma warning Unknown dynamic link import/export semantics.
    #endif

#define BIT(x) (1 << x)

#endif // CORE_H_INCLUDED
