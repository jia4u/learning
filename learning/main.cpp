//
//  main.cpp
//  learning
//
//  Created by losor on 3/16/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include <iostream>
#include "items.h"

int main(int argc, const char * argv[])
{

  // insert code here...
  std::cout << "Hello, World!\n";

  language *lang;
  lang = new language;
  lang->word = NULL;
  delete lang;

  return 0;
}

