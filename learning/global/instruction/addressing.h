//
//  addressing.h
//  learning
//
//  Created by xiangyun.kongxy on 3/23/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_addressing_h
#define learning_addressing_h

#include "int.h"

enum addressing_type {
  immediate,
  };

class addressing {
public:
  virtual addressing_type type() const = 0;
};

#endif
