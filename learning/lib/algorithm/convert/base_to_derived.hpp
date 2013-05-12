//
//  base_to_derived.h
//  algorithm
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef algorithm_base_to_derived_h
#define algorithm_base_to_derived_h

  // there are some limitations to use this function:
  //    @para obj: it must be a base of derived
  //    @para type dervied: it must be a class or struct, it can not be a pointer
  //    @return: this dervied class must have  explicit the same data  field to the base
  //    @multi-inherit is not allowed
  // orelse this convertion may cause damage
template < typename derived >
derived* to_derived_ptr( void *obj ) {
  derived assist;

  reinterpret_cast<long*>(obj)[0] = reinterpret_cast<long*>(&assist)[0];

  return reinterpret_cast<derived*>( obj );
}

#endif
