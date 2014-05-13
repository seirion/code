#include <trace/trace.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdafx.h>

void trace(const char *format, ...)
{
    char s[256];
    va_list vargs;
    va_start(vargs, format);
    _vsnprintf(s, 256, format, vargs);
    va_end(vargs);
    ::OutputDebugString(s);
}
