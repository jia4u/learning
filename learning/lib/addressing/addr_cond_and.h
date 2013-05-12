//
//  addr_cond.h
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef instruction_addr_cond_h
#define instruction_addr_cond_h

#include "addressing.h"
#include <cstdio>
#include <vector>

class addr_cond_and : public addressing {
protected:
  std::vector<addressing*> m_cond;

public:
  virtual addressing_type type();
  void set( std::vector<addressing*> cond );

  virtual ~addr_cond_and();
  addr_cond_and();
  addr_cond_and( std::vector<addressing*> cond );

};

#endif
