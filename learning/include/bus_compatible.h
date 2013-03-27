//
//  bus_compatible.h
//  learning
//
//  Created by xiangyun.kongxy on 3/26/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_bus_compatible_h
#define learning_bus_compatible_h

#include "module.h"
#include "event.h"

class bus_compatible : public module {
public:
  virtual long push_message( const event &msg ) = 0;
  virtual long push_request( const event &req, long timeout = -1 ) = 0;
  virtual long push_response( const event &response, const event &src ) = 0;
};

#endif
