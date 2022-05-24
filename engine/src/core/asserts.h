#pragma once

#include "defines.h"

// Comment this line to disable assertions
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

KAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define KASSERT(expr)                                                     \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);      \
            debugBreak();                                                 \
        }                                                                 \
    }

#define KASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }                           

#ifdef _DEBUG                                                           
#define KASSERT_DEBUG(expr)                                                \
    {                                                                      \
        if (expr) {                                                        \
        } else {                                                           \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);       \
            debugBreak();                                                  \
        }                                                                  \
    }                                                                   
#else
#define KASSERT_DEBUG(expr) // Do nothing
#endif

#else
#define KASSERT(expr) // Do nothing
#define KASSERT_MSG(expr, message) // Do nothing
#define KASSERT_DEBUG(expr) // Do nothing
#endif