//
//  expr_eq.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/9/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_eq.h"

expr_eq::~expr_eq()
{

}

expr_eq::expr_eq( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_eq::operation() const
{
  return OPT_EQ;
}

expression* expr_eq::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_eq::calculate( ) const
{
    // override this implement
  return nullptr;
}
