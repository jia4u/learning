//
//  addr_cond_or.cpp
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_cond_or.h"

addressing_type addr_cond_or::type()
{
  return ADDR_CONDITION_OR;
}

void addr_cond_or::set( std::vector<addressing *> cond )
{
  m_cond = cond;
}

addr_cond_or::addr_cond_or()
{

}

addr_cond_or::addr_cond_or( std::vector<addressing *> cond )
{
  set( cond );
}

addr_cond_or::~addr_cond_or()
{

}
