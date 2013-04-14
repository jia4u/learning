//
//  object.h
//  learning
//
//  Created by losor on 13-2-6.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_object_h
#define learning_object_h

#include "int.h"

enum item_type {
  IT_OBJECT         = 1 << 0,
  IT_RULE           = 1 << 1,
  IT_STATUS         = 1 << 2,
  IT_FACT           = 1 << 3,
  IT_LANGUAGE       = 1 << 4,
  IT_INSTRUCTION    = 1 << 5,
};

class object {
public:
  uint64 uuid;
  uint64 creator;
  uint32 nref;
  uint32 nvisit;

public:
  virtual item_type type() const;
};

#endif
