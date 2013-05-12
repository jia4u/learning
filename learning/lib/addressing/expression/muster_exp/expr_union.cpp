//
//  expr_union.cpp
//  addressing
//
//  Created by xiangyun.kongxy on 5/8/13.
//  Copyright (c) 2013 losor. All rights reserved.
//

#include "expr_union.h"

expr_union::~expr_union()
{

}

expr_union::expr_union( expression *src, expression *dst )
{
  m_src = src;
  m_dst = dst;
}

enum operation expr_union::operation() const
{
  return OPT_UNION;
}

expression* expr_union::paramenter( int nth ) const
{
  switch ( nth ) {
    case 0:
      return m_src;
    case 1:
      return m_dst;
  }

  return nullptr;
}

expr_result* expr_union::calculate( ) const
{
    // override this implement
  return nullptr;
}
