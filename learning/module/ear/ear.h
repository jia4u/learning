//
//  ear.h
//  ear
//
//  Created by xiangyun.kongxy on 5/12/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef __ear__ear__
#define __ear__ear__

#include "bus_compatible.h"

class ear : public bus_compatible {
protected:

public:
  virtual void* get_resource( uint64 res_id );
  virtual void set_depend( module *depend, uint64 module_id );
  virtual long start();
  virtual long pause();
  virtual long stop();

  virtual long push_message( const event &msg );
  virtual long push_request( const event &req, long timeout = -1 );
  virtual long push_response( const event &response, const event &src );
};

#endif /* defined(__ear__ear__) */
