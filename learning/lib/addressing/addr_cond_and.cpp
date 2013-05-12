//
//  addr_cond.cpp
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_cond_and.h"

addressing_type addr_cond_and::type()
{
  return ADDR_CONDITION_AND;
}

void addr_cond_and::set( std::vector<addressing *> cond )
{
  m_cond = cond;
}

addr_cond_and::addr_cond_and()
{

}

addr_cond_and::addr_cond_and( std::vector<addressing *> cond )
{
  set( cond );
}

addr_cond_and::~addr_cond_and()
{

}
