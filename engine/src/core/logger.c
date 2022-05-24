#include "logger.h"
#include "asserts.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initializ_logging() {
    // TODO: create log file
    return true;
}

void shutdown_logging() {
    // TODO: cleanup logging/wite queued entries
}

 void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    // b8 is_error = level < 2;

    // Tehnically impose a 32k character limit on a single log entry, but ...
    // Don't do that!
    // We don't use dynamyc memory allocation because It's slower 
    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    //Format original message
    // NOTE: We use __builtin_va_list which is type of GCC/Clang's va_start 
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);
    
    char out_message2[32000];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    //TODO: platform-specific output. 
    printf("%s", out_message2);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}