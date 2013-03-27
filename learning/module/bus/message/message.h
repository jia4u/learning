//
//  message.h
//  learning
//
//  Created by xiangyun.kongxy on 3/24/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_message_h
#define learning_message_h

#include "int.h"
#include <string>

enum message_type {
  MT_SINGLE       = 0 << 0,
  MT_BROADCAST    = 1 << 0,
  MT_REQUEST      = 0 << 1,
  MT_RESPONSE     = 1 << 1,
  MT_PUBLISH      = 1 << 2,
  MT_SUBSCRIBE    = 1 << 3,
};

class message {
public:
  uint64 uuid;
  message_type type;
  std::string name;
  std::string desc;
};

#endif
