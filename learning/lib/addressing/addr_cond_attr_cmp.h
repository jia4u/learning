//
//  addr_cond_attr_cmp.h
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef instruction__addr_cond_attr_cmp
#define instruction__addr_cond_attr_cmp

#include "addr_cond.h"

enum attr_field {
  ATTR_UUID           = 0,
  ATTR_CREATOR        = 1,
  ATTR_NREF           = 2,
  ATTR_NVISIT         = 3,
};

struct addr_attr_int
{
  attr_field field;
  uint64 value;
};

bool attr_int_equal( object *object, addr_attr_int *attr );

typedef bool (*attr_int_equal_func)( object *object, addr_attr_int *attr );
typedef addr_cond< attr_int_equal_func, addr_attr_int* > addr_attr_int_equal;

#endif
