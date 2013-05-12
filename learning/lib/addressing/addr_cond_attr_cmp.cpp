//
//  addr_cond_attr_cmp.cpp
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "addr_cond_attr_cmp.h"

bool attr_int_equal( object *object, addr_attr_int *attr )
{
  switch ( attr->field ) {
    case ATTR_UUID:
      return object->uuid == attr->value;
    case ATTR_CREATOR:
      return object->creator == attr->value;
    case ATTR_NREF:
      return object->nref == attr->value;
    case ATTR_NVISIT:
      return object->nvisit == attr->value;
    default:
      break;
  }
  return false;
}
