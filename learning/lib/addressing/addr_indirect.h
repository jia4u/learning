//
//  addr_indirect.h
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef addressing_addr_indirect_h
#define addressing_addr_indirect_h

#include "addressing.h"
#include "expression/expression.h"

class addr_indirect : public addressing
{
protected:
  expression *m_address;
  
public:
  virtual addressing_type type() const;
  virtual object* get() const;
  
  addr_indirect( expression *address );
  virtual ~addr_indirect();
};

#endif
