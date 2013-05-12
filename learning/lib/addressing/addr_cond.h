//
//  addressing_condition.h
//  instruction
//
//  Created by xiangyun.kongxy on 4/27/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#ifndef instruction_addressing_condition_h
#define instruction_addressing_condition_h

#include "addressing.h"
#include <cstdio>

template < typename predicate, typename para_type >
class addr_cond : public addressing {
protected:
  predicate m_pred;
  para_type m_para;

public:
  addr_cond( )
  {

  }

  addr_cond( predicate pred, para_type para )
  {
    set( pred, para );
  }

  virtual ~addr_cond()
  {

  }

  void set( predicate pred, para_type para )
  {
    m_pred = pred;
    m_para = para;
  }
  
  virtual addressing_type type() const
  {
    return ADDR_CONDITION;
  }
};



#endif
