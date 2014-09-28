//
//  hexlog.c
//

#include <string.h>
#include <stdarg.h>
#include <pthread.h>

#include "hexlog.h"

static __thread int (*hexLogPrint)(void *, const char *, ...);

void init_hexlog_(int (*print)(void *, const char *, ...))
{
  hexLogPrint = print;
}

void hexlog_(const char *data, const unsigned long size, void *context)
{
  static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

  static const int maxBytesPerLine = 16;

  char hex[4];
  char ascii[maxBytesPerLine + 1];
  char line[maxBytesPerLine * 4 + 2 + 1];

  line[0] = 0;

  unsigned long int count = 0;
  char buffer[maxBytesPerLine + 2 + 1];

  // Brute force thread safe log output.
  pthread_mutex_lock(&mutex);

  unsigned long i;
  for (i = 0;i < size;i++) {
    unsigned char byte = *(data + i);

    sprintf(hex, "%02X ", byte);
    strcat(line, hex);

    if ((byte >= 0x20 && byte <= 0x7E)) {
      ascii[count] = byte;
    } else {
      ascii[count] = '.';
    }

    ++count;

    // Once we reached the maximum bytes per line, we do a
    // linefeed.
    if (count == maxBytesPerLine) {
      ascii[count] = 0;
      sprintf(buffer, "| %s", ascii);
      strcat(line, buffer);

      hexLogPrint(context, "%s\n", line);

      line[0] = 0;
      count = 0;
    }
  }

  // Incomplete lines need padding.
  if (count > 0) {
    for (i=0;i < maxBytesPerLine - count;i++) {
      strcat(line, "   ");
    }
    ascii[count] = 0;
    sprintf(buffer, "| %s", ascii);
    strcat(line, buffer);

    hexLogPrint(context, "%s\n", line);
  }

  pthread_mutex_unlock(&mutex);
}

int printf_wrapper(void *context, const char *format, ...)
{
  va_list argptr;
  va_start(argptr, format);
  int ret = vprintf(format, argptr);
  va_end(argptr);
  return ret;
}

void hexlog(const char* data, const unsigned long size)
{
  init_hexlog_(printf_wrapper);
  hexlog_(data, size, NULL);
}
