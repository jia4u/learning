//
//  module_manager.h
//  learning
//
//  Created by xiangyun.kongxy on 4/7/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_module_manager_h
#define learning_module_manager_h

#include "module_info.h"

#include <map>

class module_manager {
  std::map<uint64,module_info*> m_module;

public:
  typedef std::map<uint64, module_info*>::const_iterator const_iterator;

public:
  virtual ~module_manager();

  long add_module( uint64 id, module_info *info );
  long remove_module( uint64 id );
  module_info* query_module( uint64 id );

  const_iterator begin() const;
  const_iterator end() const;
};

#endif
