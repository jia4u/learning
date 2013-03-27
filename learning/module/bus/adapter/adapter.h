//
//  adapter.h
//  learning
//
//  Created by xiangyun.kongxy on 3/23/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_adapter_h
#define learning_adapter_h

#include "int.h"
#include "../message/message_manager.h"
#include "event.h"
#include "bus_compatible.h"

class adapter {
  /// equal to module::uuid
  uint64 m_uuid;
  message_manager *m_cap;
  bus_compatible *m_instance;

public:
  adapter( int64 uuid, message_manager *cap );
  virtual ~adapter();

  uint64 uuid() const;
  message_manager* get_capacity( ) const;
  bus_compatible* get_instance( ) const;

  long push_message( const event &msg );
  long push_request( const event &req, long timeout = -1 );
  long push_response( const event &response, const event &src );

  void set_instance( bus_compatible *instance );
};

#endif
