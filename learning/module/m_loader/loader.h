//
//  loader.h
//  learning
//
//  Created by xiangyun.kongxy on 4/7/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_loader_h
#define learning_loader_h

#include "loader_conf.h"

class module_loader {
  module_manager *m_module;

public:
  virtual ~module_loader();

  virtual long load( xml_tree *root );
  virtual long start();
  virtual long pause();
  virtual long stop();

  virtual long pause( uint64 module_id );
  virtual long stop( uint64 module_id );
};

#endif
