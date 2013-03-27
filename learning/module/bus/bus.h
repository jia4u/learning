//
//  bus.h
//  learning
//
//  Created by xiangyun.kongxy on 3/23/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_bus_h
#define learning_bus_h

#include "int.h"
#include "event.h"
#include "bus_compatible.h"
#include "adapter/adapter_manager.h"

class bus : public bus_compatible {
  adapter_manager *m_adapter;

public:
  bus( adapter_manager *adapter );
  virtual ~bus();
  
  virtual void* get_resource( uint64 res_id );
  virtual void set_depend( module *depend, uint64 module_id );
  
  virtual long start();
  virtual long stop();
  
  virtual long push_message( const event &msg );
  virtual long push_request( const event &req, long timeout = -1 );
  virtual long push_response( const event &response, const event &src );

};

module* init_bus( const xml_tree *root );

#endif
