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

enum message_type {
  MT_SINGLE       = 0 << 0,
  MT_BROADCAST    = 1 << 0,
  MT_REQUEST      = 1 << 1,
  MT_RESPONSE     = 1 << 2,
  MT_PUBLISH      = 1 << 3,
  MT_SUBSCRIBE    = 1 << 4,
};

class event {
  uint64 m_uuid;
  uint64 m_msg_id;
  message_type m_msg_type;
  long m_timeout;

public:
  event( uint64 msgid, object *body, message_type type = MT_REQUEST,
         long timeout = -1 );
  virtual ~event();

  object* get() const;
};

#endif
