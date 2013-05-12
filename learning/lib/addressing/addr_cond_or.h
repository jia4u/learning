//
//  addr_cond_or.h
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef instruction__addr_cond_or
#define instruction__addr_cond_or

#include "addressing.h"
#include <cstdio>
#include <vector>

class addr_cond_or : public addressing {
protected:
  std::vector<addressing*> m_cond;

public:
  virtual addressing_type type();
  void set( std::vector<addressing*> cond );

  virtual ~addr_cond_or();
  addr_cond_or();
  addr_cond_or( std::vector<addressing *> cond );
  
};

#endif
