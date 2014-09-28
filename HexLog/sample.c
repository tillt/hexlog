//
//  sample.c
//

#include <stdio.h>
#include "hexlog.h"

int main(int argc, const char * argv[])
{
  const char test[] = "blah foo bar \001 \002 doh shoo na ba fi \003";
  hexlog(test, sizeof(test));
  return 0;
}
