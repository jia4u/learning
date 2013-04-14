//
//  message_manager.h
//  learning
//
//  Created by xiangyun.kongxy on 3/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_message_manager_h
#define learning_message_manager_h

#include "message.h"
#include "int.h"

#include <map>

class message_manager {
  std::map<uint64,message> m_msg;

public:
  long register_msg( const message &msg );
  long unregister_msg( uint64 id );
  long query_msg( uint64 id, message &message );

};

#endif
