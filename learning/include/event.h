//
//  event.h
//  learning
//
//  Created by xiangyun.kongxy on 3/23/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_event_h
#define learning_event_h

#include "items.h"
#include "int.h"

class event {
public:
  uint64 uuid;
  uint64 msg_id;
  uint64 dst_module;
  uint64 src_module;
  object *body;
};

#endif
