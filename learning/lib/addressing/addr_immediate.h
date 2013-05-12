//
//  addr_imm.h
//  instruction
//
//  Created by xiangyun.kongxy on 4/20/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef instruction_addr_imm_h
#define instruction_addr_imm_h

#include "addressing.h"

class addr_imm : public addressing
{
protected:
  object *m_addr;

public:
  virtual addressing_type type() const;
  virtual object* get() const;

  addr_imm( object *address );
  virtual ~addr_imm();
};

#endif
