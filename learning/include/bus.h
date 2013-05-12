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
#include "adapter.h"
#include "event.h"

class bus {
  adapter **m_reg_adapter;

  bus(){
  }

public:
  virtual ~bus();
  static bus* get_instance();

  long register_adapter( adapter *adt );
  long push_event( event *evt );
};

#endif
