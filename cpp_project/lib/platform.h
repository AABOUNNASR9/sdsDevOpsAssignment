#pragma once
#ifndef ACME_MYLIB_PLATFORM_INCLUDED
#define ACME_MYLIB_PLATFORM_INCLUDED

// Supported compiler
#define ACME_MYLIB_COMPILER_MSVC 1
#define ACME_MYLIB_COMPILER_GCC  2
#define ACME_MYLIB_COMPILER_CLANG       6

// Supported platform
#define ACME_MYLIB_PLATFORM_LINUX_x86       2
#define ACME_MYLIB_PLATFORM_WIN64           5


#if defined( _MSC_VER )
    #define ACME_MYLIB_COMPILER ACME_MYLIB_COMPILER_MSVC
    #define ACME_MYLIB_COMPILER_VERSION _MSC_VER
    #define __SSE2__ // MSVC doesn't set it, and we don't make purely scalar builds
#elif defined( __GNUC__ )
    // gcc family of compilers: gcc, android, clang
    #define ACME_MYLIB_GEN_VERSION(major, minor, patch) (((major)*100) + \
        ((minor)*10) + \
        (patch))

    #define ACME_MYLIB_COMPILER_VERSION ACME_MYLIB_GEN_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)

    #if defined(__ANDROID__)
        #define ACME_MYLIB_COMPILER ACME_MYLIB_COMPILER_ANDROID
    #elif defined(__clang__)
        #define ACME_MYLIB_COMPILER ACME_MYLIB_COMPILER_CLANG
        #undef ACME_MYLIB_COMPILER_VERSION
        #define ACME_MYLIB_COMPILER_VERSION ACME_MYLIB_GEN_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
    #else
        #define ACME_MYLIB_COMPILER ACME_MYLIB_COMPILER_GCC
    #endif
#else
    #error "Compilation error: Unsupported compiler."
#endif

// function call conventions
#if (ACME_MYLIB_PLATFORM == ACME_MYLIB_PLATFORM_WIN32) && !defined(__MINGW32__) && !defined(__CYGWIN__)
	#define ACME_MYLIB_DECL  __stdcall
	#define ACME_MYLIB_CDECL  __cdecl
#else
	#define ACME_MYLIB_DECL
	#define ACME_MYLIB_CDECL
#endif



// shared lib import/export
#if (ACME_MYLIB_COMPILER == ACME_MYLIB_COMPILER_MSVC)
	#define ACME_MYLIB_DLL_EXPORT __declspec(dllexport)
	#define ACME_MYLIB_DLL_IMPORT __declspec(dllimport)
#elif (ACME_MYLIB_COMPILER == ACME_MYLIB_COMPILER_GCC)
	#if (ACME_MYLIB_COMPILER_VERSION >= ((__GNUC__) * 100)) || (ACME_MYLIB_COMPILER_VERSION >= (500000))
		#define ACME_MYLIB_DLL_EXPORT         __attribute__ ((visibility ("default")))
		#define ACME_MYLIB_DLL_IMPORT         __attribute__ ((visibility ("default")))
	#else
		#define ACME_MYLIB_DLL_EXPORT
		#define ACME_MYLIB_DLL_IMPORT
#endif
#else
	#define ACME_MYLIB_DLL_EXPORT
	#define ACME_MYLIB_DLL_IMPORT
#endif


// import/export macros
#ifdef ACME_MYLIB_EXPORTS
	#define ACME_MYLIB_API ACME_MYLIB_DLL_EXPORT
#else
	#define ACME_MYLIB_API ACME_MYLIB_DLL_IMPORT
#endif

#endif