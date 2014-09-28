hexlog
======

Trivial hex-viewer component for rendering binary data streams into something human readable.

- C & C++ interfaces
- installable output function
- thread safe (but not reentrant)
- dual build system: Makefile & Xcode project


###Usage

####C interface
Prints directly to the console by default.

`void hexlog(const char *data, const unsigned long size);`

######Sample

    #include "hexlog.h"

    int main(int argc, const char* argv[]) 
    {
      const char test[] = "blah foo bar \001 \002 doh shoo na ba fi \003";
      hexlog(test, sizeof(test));
      return 0;
    }

####C++ interface
Converts the supplied data blob into a hex-view styled `std::string`.

`const std::string hex::log(const char *data, unsigned long size);`

######Sample
    #include "hexlog_plus.hpp"

    int main(int argc, const char* argv[]) 
    {
      const char test[] = "blah foo bar \001 \002 doh shoo na ba fi \003";
      cout << hex::log(test, sizeof(test));
      return 0;
    }


###Example Output

    62 6C 61 68 20 66 6F 6F 20 62 61 72 20 01 20 02 | blah foo bar . .
    20 64 6F 68 20 73 68 6F 6F 20 6E 61 20 62 61 20 |  doh shoo na ba
    66 69 20 03 00                                  | fi ..
