//
//  addr_imm.cpp
//  instruction
//
//  Created by xiangyun.kongxy on 4/20/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_immediate.h"

addressing_type addr_imm::type() const
{
  return ADDR_IMMEDIATELY;
}

object* addr_imm::get() const
{
  return m_addr;
}

addr_imm::addr_imm( object *address )
{
  m_addr = address;
}

addr_imm::~addr_imm()
{
  
}
