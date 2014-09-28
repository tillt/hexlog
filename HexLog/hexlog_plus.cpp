//
//  hexlog_plus.cpp
//

#include <stdio.h>

#include <string>
#include <sstream>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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
      int ret = vasprintf(&ptr, format, argptr);
      va_end(argptr);
      l->stream << std::string(ptr);
      free(ptr);
      return ret;
    }
  }

  const std::string log(const char *data, unsigned long size)
  {
    internal::logger logger;
    return logger(data, size);
  }
}
