//
//  addr_indirect.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_indirect.h"

addressing_type addr_indirect::type() const
{
  return ADDR_INDIRECT;
}

object* addr_indirect::get() const
{
  // TODO: change  null to empty object
  if( m_address == nullptr )
    return nullptr;

  switch ( m_address->operation() ) {
    case OPT_CONST_NUMBER:
    case OPT_CONST_STRING:
    case OPT_CONST_OBJ_ALL:
    case OPT_CONST_OBJ_CUR:
    case OPT_CONST_OBJ_REST:
      return nullptr;

    default:
      return addressing::get();
  }
  
  return nullptr;
}

addr_indirect::addr_indirect( expression *address )
{
  m_address = address;
}

addr_indirect::~addr_indirect()
{

}
