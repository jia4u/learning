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
#include "items.h"

enum addressing_type {
  ADDR_IMMEDIATELY,
  ADDR_DIRECT,
  ADDR_INDIRECT,
};

class addressing {
public:
  virtual addressing_type type() const = 0;
  virtual object* get() const ;

  virtual ~addressing();
};

#include "addr_immediate.h"
#include "addr_direct.h"
#include "addr_indirect.h"

#endif
