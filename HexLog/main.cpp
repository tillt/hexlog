//
//  main.cpp
//  HexLog
//
//  Created by Till Toenshoff on 9/27/14.
//  Copyright (c) 2014 Till Toenshoff. All rights reserved.
//

#include <iostream>
#include "hexlog.h"
#include "hexlog_plus.hpp"

int main(int argc, const char * argv[]) {
  const char test[] = "blah foo bar \001 \002 doh shoo na ba fi \003";
  hexlog(test, sizeof(test));

  std::cout << hex::log(test, sizeof(test));

  const char yo[] = "\001\001\001\001\001\001\003\001\001\001\001\001\001\003\001\001\001\001\001\001\003\001\001\001\001\001\001\003";

  std::cout << hex::log(yo, sizeof(yo));

  return 0;
}
