//
//  loader.h
//  learning
//
//  Created by xiangyun.kongxy on 4/7/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_loader_h
#define learning_loader_h

#include "module.h"
#include "module_manager.h"

class module_loader : public module {
  module_manager *m_module;

public:
  virtual ~module_loader();

  void set_manager( module_manager *mgr );

  virtual void* get_resource( uint64 res_id );

  virtual void set_depend( module *depend, uint64 module_id );

  virtual long start();

  virtual long pause();

  virtual long stop();

};

#endif
