/****************************************************************************/
/*  defines.h                                                               */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2020] Harshit Bargujar                                        */
/*                                                                          */
/*  Licensed under the Apache License, Version 2.0 (the "License");         */
/*  you may not use this file except in compliance with the License.        */
/*  You may obtain a copy of the License at                                 */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/*  See the License for the specific language governing permissions and     */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

#include "editor/logger/colorboy.h"

#if _WIN32 || _WIN64
	#define PLATFORM_WINDOWS
    #define COLORBOY_OS_WINDOWS
#else
#if __linux__
	#define PLATFORM_LINUX
    #define COLORBOY_OS_LINUX
#elif __APPLE__
	#define PLATFORM_MAC
    #define COLORBOY_OS_MACOS
#else
	#error "Unable to determine platform!"
#endif
#endif

#if defined(COLORBOY_OS_WINDOWS)  
    #include <io.h>
    #include <windows.h>
#elif defined(COLORBOY_OS_MACOS) || defined(COLORBOY_OS_LINUX)
    #include <unistd.h>
#endif

#ifdef SF_PLATFORM_WINDOWS
    #define FORCENOINLINE __declspec(noinline)
    #if defined(__clang__)
    #elif defined(__GNU__) || defined(__GNUG__)
        #define FORCEINGINLINE __inline__ __attribute__((__always_inline__))
    #elif defined(_MSC_VER)
        #define FORCEINGINLINE __forceinline
    #endif
#if SF_DYNAMIC_LINK
    #ifdef SF_BUILD_DLL
        #define STUPEFY_API __declspec(dllexport)
    #else
        #define STUPEFY_API __declspec(dllimport)
    #endif
#else
    #define STUPEFY_API 
#endif
#else
    #error Stupefy supports Windows only!
#endif


#define ASSERTIONS_ENABLED
#ifdef ASSERTIONS_ENABLED
#include <iostream>

#if _MSC_VER
    #include <intrin.h>
    #define debugBreak() __debugbreak();
#else
    #define debugBreak() __asm__  volatile("int $0x03");
#endif

#define ASSERT(expr) \
{ \
    if( expr ) \
    { \
    } \
    else \
    { \
        reportAssertionFailure(#expr, "", __FILE__, __LINE__); \
        debugBreak(); \
    } \
}

#define ASSERT_MSG(expr,message) \
{ \
    if( expr ) \
    { \
    } \
    else \
    { \
        reportAssertionFailure(#expr,message, __FILE__, __LINE__); \
        debugBreak(); \
    } \
}

#ifdef _DEBUG
#define ASSERT_DEBUG(expr) \
{ \
    if( expr ) \
    { \
    } \
    else \
    { \
        reportAssertionFailure(#expr, __FILE__, __LINE__); \
        debugBreak(); \
    } \
}
#else
    #define ASSERT_DEBUG(expr)
#endif

FORCEINGINLINE void reportAssertionFailure(const char* expression, const char* message, const char* file, int line)
{
    ColorBoy::setupConsole();
    ColorBoy::setBackgroundColor(ColorBoy::WHITE_BKG);
    ColorBoy::setTextColorBright(ColorBoy::BLUE_TXT);
    ColorBoy::setStyle(ColorBoy::BOLD);
	std::cerr << "Assertion Failure: " << expression << " message: ' " << message<<" ' in file: " << file << " at line: " << line << "\n";
    ColorBoy::restoreConsole();
}

#else
#define ASSERT(expr)
#define ASSERT_MSG(expr,message)
#define ASSERT_DEBUG(expr)

#endif