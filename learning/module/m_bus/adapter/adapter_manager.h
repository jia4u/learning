//
//  adapter_manager.h
//  learning
//
//  Created by xiangyun.kongxy on 3/24/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef learning_adapter_manager_h
#define learning_adapter_manager_h

#include "adapter.h"

#include <map>

class adapter_manager {
  std::map<uint64, adapter*> m_adapter;

public:
  virtual ~adapter_manager();

  long add_adapter( adapter *adapter );
  long remove_adapter( uint64 id );
  adapter* query_adapter( uint64 id );
  
};

#endif
