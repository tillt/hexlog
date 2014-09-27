//
//  hexlog_plus.cpp
//

#include <stdio.h>

#include <string>
#include <sstream>

#include <stdio.h>
#include <stdarg.h>
#include <alloca.h>

#include "hexlog_int.h"

namespace hex
{
  namespace internal
  {
    int print(void *context, const char *format, ...);

    struct logger
    {
      std::stringstream stream;

      const std::string operator ()(const char *data, unsigned long size)
      {
        init_hexlog_(print);
        hexlog_(data, size, this);
        return stream.str();
      }
    };
    
    int print(void *context, const char *format, ...)
    {
      logger* l = (logger*)context;

      va_list argptr;
      char* ptr;
      va_start(argptr, format);
      vasprintf(&ptr, format, argptr);
      va_end(argptr);
      std::string str(ptr);
      free(ptr);

      l->stream << str;

      return (int)str.length();
    }
  }

  const std::string log(const char *data, unsigned long size)
  {
    internal::logger logger;
    return logger(data, size);
  }
}
