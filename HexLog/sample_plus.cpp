//
//  sample_plus.cpp
//

#include <iostream>
#include "hexlog_plus.hpp"

int main(int argc, const char * argv[])
{
  const char test[] = "blah foo bar \001 \002 doh shoo na ba fi \003";
  std::cout << hex::log(test, sizeof(test));
  return 0;
}
