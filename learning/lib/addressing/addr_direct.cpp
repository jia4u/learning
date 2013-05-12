//
//  addr_direct.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_direct.h"

addressing_type addr_direct::type() const
{
  return ADDR_DIRECT;
}

addr_direct::addr_direct( uint64 address )
{
  m_address = address;
}

addr_direct::~addr_direct()
{
  
}
